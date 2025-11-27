/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_UTIL_TASK_MANAGER__H_
#define YSS_UTIL_TASK_MANAGER__H_

#include <stdint.h>
#include <yss/Mutex.h>
#include <yss/error.h>

class Task;

class TaskManager : protected Mutex
{
public:
	TaskManager(uint32_t maxCount);

	~TaskManager(void);

	error_t add(Task &obj);

	error_t add(Task *obj);

	bool notifyActivated(int32_t id);

private:
	uint32_t  mMaxCount, mCount;
	Task **mTask;
	int32_t mWorkingId;
};

#endif
