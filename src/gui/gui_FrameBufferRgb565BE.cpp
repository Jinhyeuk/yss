/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <gui/FrameBufferRgb565BE.h>
#include <gui/ColorRgb565BE.h>
#include <gui/Size.h>
#include <cmsis/cmsis_compiler.h>
#include <config.h>
#include <std_ext/malloc.h>
#include <std_ext/string.h>

FrameBufferRgb565BE::FrameBufferRgb565BE(void)
{
}

FrameBufferRgb565BE::~FrameBufferRgb565BE(void)
{
	if(mMallocFlag)
#if YSS_L_HEAP_USE
		lfree(mFrameBuffer);
#else
		free(mFrameBuffer);
#endif
}

uint8_t FrameBufferRgb565BE::getPixelCapacity(void)
{
	return 2;
}

void FrameBufferRgb565BE::drawDot(int16_t x, int16_t y)
{
	uint16_t width = mSize.getWidth();
	uint16_t height = mSize.getHeight();
	uint16_t *des = (uint16_t*)mFrameBuffer;
	
	if(x < 0 || y < 0 || x >= width || y >= height)
		return;

	des[width * y + x] = mBrushColorCode;
}

void FrameBufferRgb565BE::blendDot(int16_t x, int16_t y, uint8_t alpha)
{
	if(alpha < 16)
		return;

	uint16_t width = mSize.getWidth();
	uint16_t height = mSize.getHeight();

	if(x < 0 || y < 0 || x >= width || y >= height)
		return;

	uint16_t *des = (uint16_t*)mFrameBuffer;
	uint16_t blend, r, g, b, buf;
	
	blend = des[width * y + x];
	
	// Red
	r = blend >> 5 & 0xF8 | 0x07;
	buf = mBrushColorCode >> 5 & 0xF8 | 0x07;
	r = ((buf - r) * alpha >> 8) + r;

	// Green
	g = (blend << 5) & 0xE0;
	g |= ((blend >> 11) | 0x3) & 0x1F;
	buf = (mBrushColorCode << 5) & 0xE0;
	buf |= ((mBrushColorCode >> 11) | 0x3) & 0x1F;
	g = ((buf - g) * alpha >> 8) + g;

	// Blue
	b = blend & 0xF8 | 0x07;
	buf = mBrushColorCode & 0xF8 | 0x07;
	b = ((buf - b) * alpha >> 8) + b;
	
	des[width * y + x] = ((r << 5) & 0x1F00) | ((g >> 5) & 0x0007) | ((g << 11) & 0xE000) | (b & 0x00F8);
}

void FrameBufferRgb565BE::fillDotArray(uint32_t offset, uint32_t count, Color color)
{
	memsethw(&mFrameBuffer[offset], color.getCode(), count * 2);
}

Size FrameBufferRgb565BE::getCanvasSize(void)
{
	return mSize;
}

void FrameBufferRgb565BE::setBrushColor(Color &color)
{
	mBrushColor.Color::setColor(color);
	mBrushColorCode = mBrushColor.getCode();
}

void FrameBufferRgb565BE::setBrushColor(Color color)
{
	mBrushColor.Color::setColor(color);
	mBrushColorCode = mBrushColor.getCode();
}

Color FrameBufferRgb565BE::getBrushColor(void)
{
	return mBrushColor;
}

void FrameBufferRgb565BE::setBackgroundColor(Color &color)
{
	mBgColor.Color::setColor(color);
}

void FrameBufferRgb565BE::setBackgroundColor(Color color)
{
	mBgColor.Color::setColor(color);
}

Color FrameBufferRgb565BE::getBackgroundColor(void)
{
	return mBgColor;
}

void FrameBufferRgb565BE::drawBitmapBase(Position pos, const bitmap_t bitmap)
{
	switch(bitmap.type)
	{
	case BITMAP_TYPE_RGB565 :
		drawBitmapRgb565(pos, bitmap);
		break;
	
	case BITMAP_TYPE_ARGB1555 :
		
		break;

	default :
		return;
	}
}

void FrameBufferRgb565BE::drawBitmapRgb565(Position pos, const bitmap_t bitmap)
{
	if(bitmap.type != BITMAP_TYPE_RGB565)
		return;

	uint16_t cwidth = getCanvasSize().getWidth(), cheight = getCanvasSize().getHeight();
	uint16_t bwidth = bitmap.width, bheight = bitmap.height;
	int16_t x = pos.getX(), y = pos.getY();
	uint16_t *des = (uint16_t*)mFrameBuffer;
	uint16_t *src = (uint16_t*)bitmap.data;	
	
	if(x < 0)
	{
		src = &src[x * -1];
		x = 0;
	}
	
	if(x + bwidth > cwidth)
		bwidth = cwidth - x;
	
	if(y < 0)
	{
		src = &src[y * -1 * bwidth];
		y = 0;
	}
	
	if(y + bheight > cheight)
		bheight = cheight - y;

	des = &des[cwidth * y + x];
	for(uint16_t i = 0; i < bheight; i++)
	{
		memcpy(des, src, bwidth * 2);
		des += cwidth;
		src += bitmap.width;
	}
}

void FrameBufferRgb565BE::drawBitmapArgb1555(Position pos, const bitmap_t bitmap)
{
}

