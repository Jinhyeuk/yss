/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <util/TaskManager.h>
#include <util/Task.h>

TaskManager::TaskManager(uint32_t maxCount)
{
	mTask = new Task*[maxCount];
	mMaxCount = maxCount;
	mCount = 0;
	mWorkingId = -1;
}

TaskManager::~TaskManager(void)
{
	delete mTask;
}

error_t TaskManager::add(Task &obj)
{
	if(mCount < mMaxCount)
	{
		obj.setManager(this, mCount);
		mTask[mCount++] = &obj;

		return error_t::ERROR_NONE;
	}
	else 
	{
		return error_t::OVERFLOW;
	}
}

error_t TaskManager::add(Task *obj)
{
	if(mCount < mMaxCount)
	{
		obj->setManager(this, mCount);
		mTask[mCount++] = obj;

		return error_t::ERROR_NONE;
	}
	else 
	{
		return error_t::OVERFLOW;
	}
}

bool TaskManager::notifyActivated(int32_t id)
{
	if(id == mWorkingId)
		return false;

	lock();
	if(mWorkingId >= 0)
	{
		mTask[mWorkingId]->terminate();
		mTask[mWorkingId]->deactivate();
	}

	mWorkingId = id;
	unlock();

	return true;
}
