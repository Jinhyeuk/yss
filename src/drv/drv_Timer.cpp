/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

 #include <drv/Timer.h>

Timer::Timer(const Drv::setup_t drvSetup) : Drv(drvSetup)
{
	mIsrUpdate = nullptr;
}

void Timer::setIsrForUpdate(void (*isr)(void))
{
	mIsrUpdate = isr;
}

void Timer::isrUpdate(void)
{
	if (mIsrUpdate)
		mIsrUpdate();
}

