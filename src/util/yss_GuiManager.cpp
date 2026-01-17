/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <util/GuiManager.h>


GuiManager::GuiManager(uint32_t maxCount)
{
	mGuiTask = new GuiTask*[maxCount];
	mMaxCount = maxCount;
	mCount = 0;
}

GuiManager::~GuiManager(void)
{
	delete mGuiTask;
}

error_t GuiManager::add(GuiTask &obj)
{
	if(mCount < mMaxCount)
	{
		mGuiTask[mCount++] = &obj;

		return error_t::ERROR_NONE;
	}
	else 
	{
		
		return error_t::OVERFLOW;
	}
}

error_t GuiManager::add(GuiTask *obj)
{

	return error_t::ERROR_NONE;
}

