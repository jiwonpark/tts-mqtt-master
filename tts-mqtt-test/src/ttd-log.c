/*
 * Copyright (c) 2018 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Flora License, Version 1.1 (the License);
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://floralicense.org/license/
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <glib.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>
#include <dlog.h>
//#include <tzplatform_config.h>
#include "ttd-log.h"
#include "common-util.h"

/*
 * ttd log format
 * [time][log_level][pid-tid] message([func : line] log)
 */

static FILE *log_fp = NULL;
static GMutex log_mutex;
static ttd_log_type_e ltype = TTD_LOG_TYPE_DLOG;

static const char log_prio_name[][TTD_LOG_LEVEL_MAX] = {
	"U", /**< Unknown - DO NOT use */
	"V", /**< Verbose */
	"D", /**< Debug */
	"I", /**< Info */
	"W", /**< Warning */
	"E", /**< Error */
};

static inline long int __get_tid(void)
{
	return (long int)syscall(__NR_gettid);
}

static log_priority __level_to_dlog_prio(ttd_log_level_e level)
{
	log_priority prio = DLOG_UNKNOWN;
	switch (level) {
	case TTD_LOG_DEBUG:
		prio = DLOG_DEBUG;
		break;
	case TTD_LOG_ERROR:
		prio = DLOG_ERROR;
		break;
	case TTD_LOG_WARNING:
		prio = DLOG_WARN;
		break;
	case TTD_LOG_VERBOSE:
		prio = DLOG_VERBOSE;
		break;
	case TTD_LOG_INFO:
		prio = DLOG_INFO;
		break;
	case TTD_LOG_UNKNOWN:
	case TTD_LOG_LEVEL_MAX:
	default:
		prio = DLOG_UNKNOWN;
	}
	return prio;
}

static const char* getFormattedTime(void)
{
	struct timespec time_s;
	struct tm *ptm;
	static char res_time[40] = {0, };

	time_s.tv_sec = 0;
	time_s.tv_nsec = 0;

	if (0 == common_get_epoch_coarse_timespec(&time_s)) {
		ptm = localtime((const time_t *)&time_s.tv_sec);

		// format : YY-MM-DD hh:mm:ss:uuuuuu
		g_snprintf(res_time, sizeof(res_time),
			"%04d-%02d-%02d %02d:%02d:%02d:%06ld"
			, ptm->tm_year + 1900, ptm->tm_mon + 1, ptm->tm_mday
			, ptm->tm_hour, ptm->tm_min, ptm->tm_sec
			, (long int)(time_s.tv_nsec / 1000));
	} /* if failed, return last time */

	return res_time;
}

static int __open_log_file(void)
{
	const char *log_file = "log/ttd.log";
	dlog_print(DLOG_DEBUG, LOG_TAG, "log file - %s\n", log_file);

	/* TODO : splits log file, if log file size is exceeded specified max size */
	g_mutex_lock(&log_mutex);
	log_fp = fopen(log_file, "a");
	if (!log_fp) {
		g_mutex_unlock(&log_mutex);
		dlog_print(DLOG_ERROR,
			LOG_TAG, "error[%s] to use log file, so use dlog as log system\n",
			strerror(errno));

		ltype = TTD_LOG_TYPE_DLOG;
		return -1;
	}
	setvbuf(log_fp, (char *)NULL, _IOLBF, 0);
	g_mutex_unlock(&log_mutex);
	return 0;
}

static void __close_log_file(void)
{
	g_mutex_lock(&log_mutex);
	if (log_fp) {
		fclose(log_fp);
		log_fp = NULL;
	}
	g_mutex_unlock(&log_mutex);

	dlog_print(DLOG_DEBUG, LOG_TAG, "close log file\n");
}

static void
__write_log_to_file(const char *msg, ttd_log_level_e level, const char *tag)
{
	/* TODO : we need to logging tag ??? */

	char *log_msg = NULL;

	if (!msg)
		return;

	log_msg = g_strdup_printf("[%s][%s][%ld-%ld] %s",
			getFormattedTime(),
			log_prio_name[level],
			(long int)getpid(), __get_tid(),
			msg);

	if (!log_msg) {
		dlog_print(DLOG_ERROR, LOG_TAG, "failed to create log msg\n");
		dlog_print(DLOG_ERROR, LOG_TAG, "%s", msg);
	}

	g_mutex_lock(&log_mutex);
	if (log_fp)
		fprintf(log_fp, "%s", log_msg);
	g_mutex_unlock(&log_mutex);
	g_free(log_msg);
}

int ttd_log_init(ttd_log_type_e type)
{
	ltype = type;
	g_mutex_init(&log_mutex);
	dlog_print(DLOG_DEBUG, LOG_TAG, "initializing log type : [%d]\n", type);
	switch (type) {
	case TTD_LOG_TYPE_FILE:
	case TTD_LOG_TYPE_ALL:
		__open_log_file();
		break;
	case TTD_LOG_TYPE_DLOG: /* nothing to do */
	default:
		ltype = TTD_LOG_TYPE_DLOG;
		break;
	}
	return 0;
}

void ttd_log_fini(void)
{
	__close_log_file();
	g_mutex_clear(&log_mutex);
	ltype = TTD_LOG_TYPE_DLOG;

	return;
}

int ttd_log_print(ttd_log_level_e level, const char *tag, const char *fmt, ...)
{
	va_list ap;

	switch (ltype) {
	case TTD_LOG_TYPE_FILE:
	{
		char *msg = NULL;

		va_start(ap, fmt);
		msg = g_strdup_vprintf(fmt, ap);
		va_end(ap);

		__write_log_to_file(msg, level, tag);
		g_free(msg);
	}
		break;
	case TTD_LOG_TYPE_ALL:
	{
		char *msg = NULL;

		va_start(ap, fmt);
		msg = g_strdup_vprintf(fmt, ap);
		va_end(ap);

		dlog_print(__level_to_dlog_prio(level), tag, "%s", msg);
		__write_log_to_file(msg, level, tag);
		g_free(msg);
	}
		break;
	case TTD_LOG_TYPE_DLOG:
	default:
		va_start(ap, fmt);
		dlog_vprint(__level_to_dlog_prio(level), tag, fmt, ap);
		va_end(ap);
		break;
	}
	return 0;
}
