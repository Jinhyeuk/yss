/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef	YSS_SAC_POINTER_DEVICE__H_
#define	YSS_SAC_POINTER_DEVICE__H_

#include <yss/Trigger.h>
#include <util/Fifo.h>
#include <yss/Mutex.h>

class Frame;
class Object;

class PointerDevice : public Trigger, protected Mutex
{
public :
	typedef enum
	{
		EVENT_NOTTING = 0,
		EVENT_TOUCH_DOWN,
		EVENT_TOUCH_DRAG,
		EVENT_TOUCH_UP
	}eventType_t;

	typedef struct
	{
		int16_t x;
		int16_t y;
		eventType_t event;
	}event_t;

	PointerDevice(void);

	void push(event_t event);

	void setFrame(Frame &frame);

	void setFrame(Frame *frame);

	void resetFrame(void);

	void resetFrame(Frame *frame);

	virtual void trigger(void);

protected :
	
private :
	Frame *mFrame;
	Object *mObject;
	uint8_t mStep;
	event_t mPushEvent, mDragEvent, mUpEvent;
	bool mCompleteFlag;
};

#endif

