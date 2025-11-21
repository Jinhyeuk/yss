/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_UTIL_GUI_MANAGER__H_
#define YSS_UTIL_GUI_MANAGER__H_

//#include <yss/Thread.h>
//#include <yss/Trigger.h>
#include <stdint.h>
#include <yss/Mutex.h>
#include <yss/error.h>

class GuiTask;

class GuiManager : protected Mutex
{
public:
	GuiManager(uint32_t maxCount);

	~GuiManager(void);

	error_t add(GuiTask &obj);

	error_t add(GuiTask *obj);

private:
	uint32_t  mMaxCount, mCount;
	GuiTask **mGuiTask;
};

#endif
