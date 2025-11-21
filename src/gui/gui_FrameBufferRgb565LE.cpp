/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <gui/FrameBufferRgb565LE.h>
#include <gui/ColorRgb565LE.h>
#include <gui/Size.h>
#include <cmsis/cmsis_compiler.h>
#include <config.h>
#include <std_ext/malloc.h>
#include <std_ext/string.h>
#include <__debug_stdio.h>
#include <gui/BitmapDrawingCalculator.h>

FrameBufferRgb565LE::FrameBufferRgb565LE(void)
{
}

FrameBufferRgb565LE::~FrameBufferRgb565LE(void)
{
	if(mMallocFlag)
#if YSS_L_HEAP_USE
		lfree(mFrameBuffer);
#else
		free(mFrameBuffer);
#endif
}

uint8_t FrameBufferRgb565LE::getPixelCapacity(void)
{
	return 2;
}

void FrameBufferRgb565LE::drawDot(int16_t x, int16_t y)
{
	uint16_t width = mSize.getWidth();
	uint16_t height = mSize.getHeight();
	uint16_t *des = (uint16_t*)mFrameBuffer;
	
	if(x < 0 || y < 0 || x >= width || y >= height)
		return;

	des[width * y + x] = mBrushColorCode;
}

void FrameBufferRgb565LE::blendDot(int16_t x, int16_t y, uint8_t alpha)
{
	if(alpha < 16)
		return;

	uint16_t width = mSize.getWidth();
	uint16_t height = mSize.getHeight();

	if(x < 0 || y < 0 || x >= width || y >= height)
		return;

	uint16_t *des = (uint16_t*)mFrameBuffer;
	uint16_t blend;
	int32_t r, g, b, buf, d1, d2, d3;
	
	blend = des[width * y + x];
	
	// Red
	d1 = r = blend >> 8 & 0xF8 | 0x07;
	d2 = buf = mBrushColorCode >> 8 & 0xF8 | 0x07;
	d3 = r = (((buf - r) * (int32_t)alpha) >> 8) + r;
	
	// Green
	g = blend >> 3 & 0xFC | 0x03;
	buf = mBrushColorCode >> 3 & 0xFC | 0x03;
	g = (((buf - g) * (int32_t)alpha) >> 8) + g;

	// Blue
	b = (blend << 3) & 0xF8 | 0x07;
	buf = (mBrushColorCode << 3) & 0xF8;// | 0x07;
	b = (((buf - b) * (int32_t)alpha) >> 8) + b;
	
	des[width * y + x] = ((r << 8) & 0xF800) | ((g << 3) & 0x07E0) | ((b >> 3) & 0x001F);
}

void FrameBufferRgb565LE::fillDotArray(uint32_t offset, uint32_t count, Color color)
{
	memsethw(&mFrameBuffer[offset], color.getCode(), count * 2);
}

Size FrameBufferRgb565LE::getCanvasSize(void)
{
	return mSize;
}

void FrameBufferRgb565LE::setBrushColor(Color color)
{
	mBrushColor.Color::setColor(color);
	mBrushColorCode = mBrushColor.getCode();
}

Color FrameBufferRgb565LE::getBrushColor(void)
{
	return mBrushColor;
}

void FrameBufferRgb565LE::setBackgroundColor(Color color)
{
	mBgColor.Color::setColor(color);
}

Color FrameBufferRgb565LE::getBackgroundColor(void)
{
	return mBgColor;
}

void FrameBufferRgb565LE::drawBitmapBase(Size canvasSize, Rectangular canvasRect, Position bitmapPos, const bitmap_t bitmap)
{
	switch(bitmap.type)
	{
	case BITMAP_TYPE_RGB565 :
		drawBitmapRgb565(getCanvasSize(), canvasRect, bitmapPos, bitmap);
		break;
	
	case BITMAP_TYPE_ARGB1555 :
		drawBitmapArgb1555(getCanvasSize(),canvasRect, bitmapPos, bitmap);
		break;

	default :
		return;
	}
}

void FrameBufferRgb565LE::drawBitmapRgb565(Size canvasSize, Rectangular canvasDesArea, Position bitmapPos, const bitmap_t bitmap)
{
	if(bitmap.type != BITMAP_TYPE_RGB565)
		return;

	Rectangular bitmapArea = {bitmapPos, {bitmap.width, bitmap.height}};
	BitmapDrawingCalculator bdc(canvasSize, canvasDesArea, bitmapArea);
	
	if(bdc.calculate() == false)
		return;

	uint16_t cwidth = getCanvasSize().getWidth(), *des = (uint16_t*)mFrameBuffer, *src = (uint16_t*)bitmap.data;
	uint16_t bwidth = bdc.getTrimedBitmapWidth();
	uint16_t bheight = bdc.getTrimedBitmapHeight();
	des = &des[bdc.getCanvasDesFrameBufferOffset()];
	src = &src[bdc.getBitmapSrcFrameBufferOffset()];

	for(uint16_t i = 0; i < bheight; i++)
	{
		memcpy(des, src, bwidth * 2);
		des += cwidth;
		src += bitmap.width;
	}
}

void FrameBufferRgb565LE::drawBitmapArgb1555(Size canvasSize, Rectangular canvasDesArea, Position bitmapPos, const bitmap_t bitmap)
{
	if(bitmap.type != BITMAP_TYPE_ARGB1555)
		return;
	
	Rectangular bitmapArea = {bitmapPos, {bitmap.width, bitmap.height}};
	BitmapDrawingCalculator bdc(canvasSize, canvasDesArea, bitmapArea);
	
	if(bdc.calculate() == false)
		return;

	uint16_t cwidth = getCanvasSize().getWidth(), *des = (uint16_t*)mFrameBuffer, *src = (uint16_t*)bitmap.data;
	uint16_t bwidth = bdc.getTrimedBitmapWidth();
	uint16_t bheight = bdc.getTrimedBitmapHeight();
	uint16_t buf, offset, trans;
	des = &des[bdc.getCanvasDesFrameBufferOffset()];
	src = &src[bdc.getBitmapSrcFrameBufferOffset()];
	offset = bitmap.width - bwidth;

	for(uint16_t i = 0; i < bheight; i++)
	{
		for(uint16_t j = 0; j < bwidth; j++)
		{
			trans = *src++;
			if(trans & 0x8000)
			{
				buf = trans;
				trans <<= 1;
				trans &= ~0x003F;
				trans |= buf & 0x1F;
				if(trans & 0x0400)
					trans |= 0x0020;
				*des = trans;
			}
			des++;
		}

		des += cwidth - bwidth;
		src += offset;
	}
}

bitmap_t FrameBufferRgb565LE::getBitmap(void)
{
	bitmap_t bitmap = 
	{
		mSize.getWidth(),	//uint16_t width;
		mSize.getHeight(),	//uint16_t height;
		BITMAP_TYPE_RGB565,	//bitmapType_t type; // 0 : RGB565, 1 : RGB888, 2 : ARGB1555
		mFrameBuffer		//uint8_t *data;
	};

	return bitmap;
}

