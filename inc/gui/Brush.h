/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_BRUSH__H_
#define YSS_GUI_BRUSH__H_

#include <stdint.h>
#include "Color.h"
#include "Position.h"
#include "Rectangular.h"
#include "Size.h"
#include <gui/util.h>

class Font;

class Brush
{
public:
	virtual void drawDot(int16_t x, int16_t y) = 0;

	virtual void blendDot(int16_t x, int16_t y, uint8_t alpha) = 0;
	
	virtual void setBrushColor(Color &color) = 0;

	virtual void setBrushColor(Color color) = 0;

	virtual Color getBrushColor(void) = 0;

	virtual void setBackgroundColor(Color &color) = 0;

	virtual void setBackgroundColor(Color color) = 0;

	virtual Color getBackgroundColor(void) = 0;

	void drawLine(Position p1, Position p2);

	void drawCircle(Position pos, uint16_t r);

	void fillCircle(Position p1, uint16_t r);

	void drawTriangle(Position p1, Position p2, Position p3);

	void fillTriangle(Position p1, Position p2, Position p3);

	void drawRectangular(Rectangular rect);

	void fillRectangular(Rectangular rect);

	void fill(void);

	void clear(void);

	void setFont(Font &font);

	uint8_t drawChar(Position pos, uint32_t utf8);

	uint16_t drawString(Position pos, const char *str);

	void drawBitmap(Position pos, const bitmap_t &bitmap);

protected:
	Font *mFont;

	virtual void fillRectBase(int16_t x, int16_t y, uint16_t width, uint16_t height, Color color);

	virtual void drawBitmapBase(Position pos, const bitmap_t &bitmap) = 0;

	virtual void drawDotNc(uint32_t offset, Color color) = 0;

	virtual void fillDotArray(uint32_t offset, uint32_t count, Color color) = 0;

	virtual uint8_t getPixelCapacity(void) = 0;

	virtual Size getCanvasSize(void) = 0;
};

#endif

