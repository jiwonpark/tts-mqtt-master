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

#ifndef __TTD_COMMON_UTIL_H__
#define __TTD_COMMON_UTIL_H__

#include <time.h>

#define EPOCH_TIME_REF 1526515200000 /* 2018-05-17 GMT */

long long common_get_monotonic_time(void);
long long common_get_monotonic_coarse_time(void);

long long common_get_epoch_time(void);
long long common_get_epoch_coarse_time(void);
int common_get_epoch_timespec(struct timespec *tp);
int common_get_epoch_coarse_timespec(struct timespec *tp);

#endif /* __TTD_COMMON_UTIL_H__ */
