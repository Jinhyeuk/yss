/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_FRAME_BUFFER_RGB565LE__H_
#define YSS_GUI_FRAME_BUFFER_RGB565LE__H_

#include "FrameBuffer.h"
#include "Brush.h"
#include "ColorRgb565LE.h"

class FrameBufferRgb565LE : public FrameBuffer, public Brush
{
public :
	FrameBufferRgb565LE(void);

	virtual ~FrameBufferRgb565LE(void);

	virtual uint8_t getPixelCapacity(void);

	virtual void drawDot(int16_t x, int16_t y);

	virtual void blendDot(int16_t x, int16_t y, uint8_t alpha);
	
	virtual void setBrushColor(Color color);

	virtual Color getBrushColor(void);

	virtual void setBackgroundColor(Color color);

	virtual Color getBackgroundColor(void);

	virtual bitmap_t getBitmap(void);

protected :
	virtual void fillDotArray(uint32_t offset, uint32_t count, Color color);

	virtual void drawBitmapBase(Size canvasSize, Rectangular canvasDesArea, Position bitmapPos, const bitmap_t bitmap);

	virtual Size getCanvasSize(void);

private :
	ColorRgb565LE mBrushColor, mBgColor, mFontColor;
	uint16_t mBrushColorCode;

	void drawBitmapRgb565(Size canvasSize, Rectangular canvasDesArea, Position bitmapPos, const bitmap_t bitmap);

	void drawBitmapArgb1555(Size canvasSize, Rectangular canvasDesArea, Position bitmapPos, const bitmap_t bitmap);
};

#endif

