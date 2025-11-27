/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>
#include <yss/gui.h>
#include <gui/Label.h>
#include <yss/instance.h>

#if USE_GUI && YSS_L_HEAP_USE

Label::Label(void)
{
	mText = 0;
	mFrameBuffer->setBrushColor({0x00, 0x00, 0x00});
}

void Label::paint(void)
{
	if (mFrameBuffer == 0)
		return;

	Font *font = mFrameBuffer->getFont();

	mFrameBuffer->clear();
	if (mText && font != 0)
	{
		mFrameBuffer->drawString({2, 2}, (char *)mText);
	}
}

void Label::setText(const char *text)
{
	mText = text;
	paint();
	update();
}

void Label::setFontColor(Color color)
{
	mFontColor.setColor(color);
}

void Label::setFontColor(uint8_t red, uint8_t green, uint8_t blue)
{
	mFontColor.setColor({red, green, blue});
}

void Label::setBackgroundColor(Color color)
{
	mFrameBuffer->setBackgroundColor(color);
}

void Label::setBackgroundColor(uint8_t red, uint8_t green, uint8_t blue)
{
	mFrameBuffer->setBackgroundColor({red, green, blue});
}

#endif