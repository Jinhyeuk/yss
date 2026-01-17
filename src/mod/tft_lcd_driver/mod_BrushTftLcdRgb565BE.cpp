/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <mod/tft_lcd_driver/BrushTftLcdRgb565BE.h>
#include <gui/ColorRgb565LE.h>
#include <gui/Size.h>
#include <cmsis/cmsis_compiler.h>
#include <config.h>
#include <std_ext/malloc.h>
#include <std_ext/string.h>

BrushTftLcdRgb565BE::BrushTftLcdRgb565BE(void)
{
	mFb = nullptr;
}

BrushTftLcdRgb565BE::~BrushTftLcdRgb565BE(void)
{

}

void BrushTftLcdRgb565BE::setFrameBuffer(FrameBufferRgb565BE &obj)
{
	mFb = &obj;
}

void BrushTftLcdRgb565BE::setBrushColor(Color color)
{
	mBrushColor.Color::setColor(color);
	mBrushColorCode = mBrushColor.getCode();
}

Color BrushTftLcdRgb565BE::getBrushColor(void)
{
	return mBrushColor;
}

void BrushTftLcdRgb565BE::setBackgroundColor(Color color)
{
	mBgColor.Color::setColor(color);
}

Color BrushTftLcdRgb565BE::getBackgroundColor(void)
{
	return mBgColor;
}

