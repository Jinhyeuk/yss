/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_UTIL_GUI_TASK__H_
#define YSS_UTIL_GUI_TASK__H_

#include <yss/Thread.h>
#include <stdint.h>
#include <yss/Mutex.h>
#include <yss/error.h>

class Frame;

class GuiTask : public Thread
{
public:
	GuiTask(uint32_t stackSize);

	~GuiTask(void);

	void activate(void);

	void deactivate(void);

	Frame *getFrame(void);

protected :
	Frame *mFrame;
	uint32_t mStackSize;
};

#endif

 