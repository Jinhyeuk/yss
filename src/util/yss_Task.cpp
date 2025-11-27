/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <util/Task.h>
#include <util/TaskManager.h>

Task::Task(uint32_t stackSize)
{
	mStackSize = stackSize;
	mId = -1;
	mTaskManager = nullptr;
}

Task::~Task(void)
{

}

void Task::activate(void)
{
	if(mTaskManager)
	{
		if(mTaskManager->notifyActivated(mId))
			runThread(mStackSize);
	}
}

void Task::deactivate(void)
{
	stopThread();
}

void Task::setManager(TaskManager *manager, int32_t id)
{
	mTaskManager = manager;
	mId = id;
}

