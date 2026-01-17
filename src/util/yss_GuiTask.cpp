/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <util/GuiTask.h>
#include <gui/Frame.h>

#if USE_GUI

GuiTask::GuiTask(uint32_t stackSize)
{
	mStackSize = stackSize;
	mFrame = nullptr; 
}

GuiTask::~GuiTask(void)
{
	if(mFrame != nullptr)
		delete mFrame;
}

void GuiTask::activate(void)
{
	if(mFrame == nullptr)
		mFrame = new Frame;

	mFrame->setAsSystemFrame();

	runThread(mStackSize);
}

void GuiTask::deactivate(void)
{
	stopThread();

	if(mFrame != nullptr)
	{
		delete mFrame;
		mFrame = nullptr;
	}
}

Frame *GuiTask::getFrame(void)
{
	return mFrame;
}

#endif

