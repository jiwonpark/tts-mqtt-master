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

#ifndef __TT_DAEMON_LOG_H__
#define __TT_DAEMON_LOG_H__

typedef enum {
	TTD_LOG_UNKNOWN = 0,
	TTD_LOG_VERBOSE,
	TTD_LOG_DEBUG,
	TTD_LOG_INFO,
	TTD_LOG_WARNING,
	TTD_LOG_ERROR,
	TTD_LOG_LEVEL_MAX
} ttd_log_level_e;

typedef enum {
	TTD_LOG_TYPE_DLOG = 0,
	TTD_LOG_TYPE_FILE,
	TTD_LOG_TYPE_ALL,
} ttd_log_type_e;

int ttd_log_print(ttd_log_level_e level, const char *tag, const char *fmt, ...);
int ttd_log_init(ttd_log_type_e type);
void ttd_log_fini(void);

#ifdef	LOG_TAG
#undef	LOG_TAG
#endif
#define LOG_TAG "TTD"

#if !defined(_V)
#define _V(fmt, arg...) ttd_log_print(TTD_LOG_VERBOSE, LOG_TAG, "[%s : %d] " fmt "\n", __func__, __LINE__, ##arg)
#endif

#if !defined(_D)
#define _D(fmt, arg...) ttd_log_print(TTD_LOG_DEBUG, LOG_TAG, "[%s : %d] " fmt "\n", __func__, __LINE__, ##arg)
#endif

#if !defined(_I)
#define _I(fmt, arg...) ttd_log_print(TTD_LOG_INFO, LOG_TAG, "[%s : %d] " fmt "\n", __func__, __LINE__, ##arg)
#endif

#if !defined(_W)
#define _W(fmt, arg...) ttd_log_print(TTD_LOG_WARNING, LOG_TAG, "[%s : %d] " fmt "\n", __func__, __LINE__, ##arg)
#endif

#if !defined(_E)
#define _E(fmt, arg...) ttd_log_print(TTD_LOG_ERROR, LOG_TAG, "[%s : %d] " fmt "\n", __func__, __LINE__, ##arg)
#endif

#define retvm_if(expr, val, fmt, arg...) do { \
	if (expr) { \
		_E(fmt, ##arg); \
		_E("(%s) -> %s() return", #expr, __func__); \
		return val; \
	} \
} while (0)

#define retv_if(expr, val) do { \
	if (expr) { \
		_E("(%s) -> %s() return", #expr, __func__); \
		return (val); \
	} \
} while (0)

#define retm_if(expr, fmt, arg...) do { \
	if (expr) { \
		_E(fmt, ##arg); \
		_E("(%s) -> %s() return", #expr, __func__); \
		return; \
	} \
} while (0)

#define ret_if(expr) do { \
	if (expr) { \
		_E("(%s) -> %s() return", #expr, __func__); \
		return; \
	} \
} while (0)

#define goto_if(expr, val) do { \
	if (expr) { \
		_E("(%s) -> goto", #expr); \
		goto val; \
	} \
} while (0)

#define break_if(expr) { \
	if (expr) { \
		_E("(%s) -> break", #expr); \
		break; \
	} \
}

#define continue_if(expr) { \
	if (expr) { \
		_E("(%s) -> continue", #expr); \
		continue; \
	} \
}

#endif /* __TT_DAEMON_LOG_H__ */
