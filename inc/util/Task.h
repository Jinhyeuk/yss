/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_UTIL_TASK__H_
#define YSS_UTIL_TASK__H_

#include <yss/Thread.h>
#include <stdint.h>
#include <yss/Mutex.h>
#include <yss/error.h>

class TaskManager;

class Task : protected Thread
{
public:
	Task(uint32_t stackSize);

	~Task(void);

	void activate(void);

	void deactivate(void);

	virtual void terminate(void) = 0;

	void setManager(TaskManager *manager, int32_t id);

protected :
	uint32_t mStackSize;
	int32_t mId;
	TaskManager *mTaskManager;
};

#endif

 