/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */
#include <config.h>

//#if USE_GUI && YSS_L_HEAP_USE
#if YSS_L_HEAP_USE

#include <yss/gui.h>
#include <yss/event.h>
#include <yss/gui.h>
#include <yss/thread.h>
#include <yss/instance.h>
#include <yss/debug.h>
//#include <gui/OutputFrameBuffer.h>
#include <yss.h>
#include <sac/TftLcdDriver.h>
#include <sac/PointerDevice.h>

//static OutputFrameBuffer *gFrameBuf;
//static Frame *gCurrentFrame;
//static Object *gLastSelectedObj;
static TftLcdDriver *gTftLcd;

void initOutputFrameBuffer(void)
{
#warning "복원 필요"
	//gFrameBuf = new OutputFrameBuffer();
	//gFrameBuf->setLcdSize(ltdc.getLcdSize());
	//ltdc.setFrameBuffer(gFrameBuf->getFrameBuffer());
}

namespace system 
{
	Frame *gSystemFrame;
	PointerDevice *gPointerDevice;

	void setSystemTftLcd(TftLcdDriver &lcd)
	{
		gTftLcd = &lcd;
	}

	TftLcdDriver* getSystemTftLcd(void)
	{
		return gTftLcd;
	}

	Size getSystemTftLcdSize(void)
	{
		if(gTftLcd)
			return gTftLcd->getLcdSize();
		else
			return {0, 0};
	}

	void drawBitmap(Frame *obj, Position pos, const bitmap_t bitmap)
	{
		if(gTftLcd && gSystemFrame == obj)
			gTftLcd->drawBitmapBase(gTftLcd->getLcdSize(), {{0, 0}, gTftLcd->getLcdSize()}, pos, bitmap);
	}

	void drawBitmap(Frame *obj, Rectangular rect, Position bitmapPos, const bitmap_t bitmap)
	{
		if(gTftLcd && gSystemFrame == obj)
			gTftLcd->drawBitmapBase(gTftLcd->getLcdSize(), rect, bitmapPos, bitmap);
	}

	void setSystemFrame(Frame *obj)
	{
		gSystemFrame = obj;
		obj->update();
		if(gPointerDevice)
			gPointerDevice->setFrame(obj);
	}

	void setSystemPointerDevice(PointerDevice *obj)
	{
		gPointerDevice = obj;
	}

	void setSystemPointerDevice(PointerDevice &obj)
	{
		gPointerDevice = &obj;
	}
}

//void setActiveFrame(Frame *obj)
//{
//	if(gFrameBuf == 0)
//		initOutputFrameBuffer();

//	gCurrentFrame = obj;
//	gFrameBuf->setFrame(obj);
//	obj->setOutputFrameBuffer(gFrameBuf);
//}

//void clearActiveFrame(void)
//{
//	gLastSelectedObj = 0;
//}

#if USE_GUI && USE_EVENT
void setEvent(Position_t pos, uint8_t event)
{
	static Position_t lastPos;

	if(gFrameBuf == 0)
		return;

	switch (event)
	{
	case event::TOUCH_DOWN:
		lastPos = pos;
		gLastSelectedObj = gCurrentFrame->Container::handlerPush(pos);
		if (gLastSelectedObj)
			lastPos = gLastSelectedObj->getAbsolutePos();
		break;
	case event::TOUCH_DRAG:
		if (gLastSelectedObj)
		{
			pos.x -= lastPos.x;
			pos.y -= lastPos.y;
			gLastSelectedObj->handlerDrag(pos);
		}
		break;
	case event::TOUCH_UP:
		if (gLastSelectedObj)
		{
			gLastSelectedObj->handlerUp();
			gLastSelectedObj = 0;
		}
		break;
	}
}
#endif

#endif

