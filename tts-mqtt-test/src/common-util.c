/*
 * Copyright (c) 2017 Samsung Electronics Co., Ltd.
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

#include <time.h>

#ifndef CLOCK_REALTIME_COARSE
#define CLOCK_REALTIME_COARSE CLOCK_REALTIME
#endif

#ifndef CLOCK_MONOTONIC_COARSE
#define CLOCK_MONOTONIC_COARSE CLOCK_MONOTONIC
#endif

static inline long long __timespec_to_ms(struct timespec ts)
{
	return (((long long) ts.tv_sec) * 1000) + (ts.tv_nsec / 1000000);
}

static inline long long __timespec_to_ns(struct timespec ts)
{
	return (((long long) ts.tv_sec) * 1000000) + (ts.tv_nsec / 1000);
}

long long common_get_monotonic_time(void)
{
	struct timespec ts;
	int result;

	result = clock_gettime(CLOCK_MONOTONIC, &ts);

	if (result != 0)
		return 0;

	return __timespec_to_ns(ts);
}

long long common_get_monotonic_coarse_time(void)
{
	struct timespec ts;
	int result;

	result = clock_gettime(CLOCK_MONOTONIC_COARSE, &ts);

	if (result != 0)
		return 0;

	return __timespec_to_ns(ts);
}

long long common_get_epoch_time(void)
{
	struct timespec ts;
	int result;

	result = clock_gettime(CLOCK_REALTIME, &ts);

	if (result != 0)
		return 0;

	return __timespec_to_ms(ts);
}

long long common_get_epoch_coarse_time(void)
{
	struct timespec ts;
	int result;

	result = clock_gettime(CLOCK_REALTIME_COARSE, &ts);

	if (result != 0)
		return 0;

	return __timespec_to_ms(ts);
}

int common_get_epoch_timespec(struct timespec *tp)
{
	if (!tp)
		return -1;

	return clock_gettime(CLOCK_REALTIME, tp);
}

int common_get_epoch_coarse_timespec(struct timespec *tp)
{
	if (!tp)
		return -1;

	return clock_gettime(CLOCK_REALTIME_COARSE, tp);
}
