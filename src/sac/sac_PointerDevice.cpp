/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#if USE_POINTER_DEVICE

#include <sac/PointerDevice.h>
#include <gui/Frame.h>

PointerDevice::PointerDevice(void)
{
	mFrame = nullptr;
	mObject = nullptr;
	activateTrigger();
	mStep = 0;
}

void PointerDevice::push(event_t event)
{
	// Up과 Down 이벤트는 놓치지 않기 위한 필터링 처리
	switch(event.event)
	{
	case EVENT_TOUCH_DOWN :
		if(mStep == 0)
		{
			mPushEvent = event;
			mDragEvent.event = EVENT_NOTTING;
			mUpEvent.event = EVENT_NOTTING;
		}
		break;
	
	case EVENT_TOUCH_DRAG :
		if(mStep == 1)
		{
			mDragEvent = event;
		}
		break;

	case EVENT_TOUCH_UP : 
		mUpEvent = event;
		break;
	}
	runTrigger();
}

void PointerDevice::trigger(void)
{
	if(mFrame != nullptr)
	{
		switch(mStep)
		{
		case 0 : // IDLE 상태
			if(mPushEvent.event != EVENT_NOTTING)
			{
				mObject = mFrame->handlerPush({mPushEvent.x, mPushEvent.y});
				mPushEvent.event = EVENT_NOTTING;
				mStep = 1;
			}
			break;
		
		case 1 : // DRAG 상태
			if(mUpEvent.event != EVENT_NOTTING)
			{
				if(mObject != nullptr)
					mObject->handlerUp();
				mPushEvent.event = EVENT_NOTTING;
				mDragEvent.event = EVENT_NOTTING;
				mUpEvent.event = EVENT_NOTTING;
				mStep = 0;
			}
			else if(mDragEvent.event != EVENT_NOTTING)
			{
				if(mObject != nullptr)
					mObject->handlerDrag({mDragEvent.x, mDragEvent.y});
			}
			break;
		}
	}

	mCompleteFlag = true;
}

void PointerDevice::setFrame(Frame &frame)
{
	lock();
	mFrame = &frame;
	unlock();
}

void PointerDevice::setFrame(Frame *frame)
{
	lock();
	mFrame = frame;
	unlock();
}

void PointerDevice::resetFrame(void)
{
	lock();
	mFrame = nullptr;
	unlock();
}

void PointerDevice::resetFrame(Frame *frame)
{
	lock();
	if(mFrame == frame)
		mFrame = nullptr;
	unlock();
}

#endif

