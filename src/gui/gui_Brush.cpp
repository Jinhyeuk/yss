/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <gui/Brush.h>
#include <math.h>
#include <gui/Font.h>

void Brush::fillRectBase(int16_t x, int16_t y, uint16_t width, uint16_t height, Color color)
{
	uint16_t cwidth = getCanvasSize().getWidth(), cheight = getCanvasSize().getHeight();
	int16_t ex = x + width, ey = y + height, offset = getPixelCapacity();
	uint32_t des;

	if(ey >= cheight - 1)
		ey = cheight - 1;
	if(ex >= cwidth - 1)
		ex = cwidth - 1;

	for (int16_t i = y; i <= ey; i++)
	{
		des = i * cwidth * offset + x * offset;
		fillDotArray(des, width, color);
	}
}

void Brush::fillRectangular(Rectangular rect)
{
	Position pos = rect.getPosition();
	Size size = rect.getSize();

	fillRectBase(pos.getX(), pos.getY(), size.getWidth(), size.getHeight(), getBrushColor());
}

void Brush::fill(void)
{
	Size size = getCanvasSize();

	fillRectBase(0, 0, size.getWidth(), size.getHeight(), getBrushColor());
}

void Brush::clear(void)
{
	Size size = getCanvasSize();

	fillRectBase(0, 0, size.getWidth(), size.getHeight(), getBackgroundColor());
}

void Brush::fillCircle(Position pos, uint16_t radius)
{
	float r = radius, buf;
	int32_t sx, ex, count, y, px = pos.getX(), py = pos.getY();
	uint16_t width = getCanvasSize().getWidth(), height = getCanvasSize().getHeight();
	int16_t offset = getPixelCapacity();
	Color color = getBrushColor();
	uint32_t des;

	if (radius < 3)
		return;

	for (uint16_t i = 0; i < radius; i++)
	{
		buf = i + 1;
		buf = r * r - buf * buf;
		ex = sx = pow(buf, (float)0.5) + 0.5f;

		sx = px - sx + 1;
		ex = px + ex;

		if(sx < 0)
			sx = 0;
		if(ex > width - 1)
			ex = width - 1;
		
		y = py + i + 1;
		if(y < height)
		{
			des = y * width * offset + sx * offset;
			count = ex - sx;
			if(count > 0)
				fillDotArray(des, ex - sx, color);
		}
		
		y = py - i;
		if(y >= 0)
		{
			des = y * width * offset + sx * offset;
			count = ex - sx;
			if(count > 0)
				fillDotArray(des, ex - sx, color);
		}
	}
}

void Brush::drawCircle(Position pos, uint16_t radius)
{
	int16_t px = pos.getX(), py = pos.getY();
	float r = radius, x, yp, yn;
	uint16_t width = getCanvasSize().getWidth(), height = getCanvasSize().getHeight();
	int16_t offset = getPixelCapacity();
	uint32_t color = getBrushColor().getCode();
	uint32_t des;

	if (radius < 3)
		return;

	for (uint16_t i = 0; i < radius; i++)
	{
		x = i;
		yp = r * r - x * x;
		yp = pow(yp, (float)0.5) + (float)0.5;
		yn = yp - (float)1.0;
		
		drawDot(px + x, py + yp);
		drawDot(px + x, py - yn);
		drawDot(px - x, py - yn);
		drawDot(px - x, py + yp);
		drawDot(px + yp, py + x);
		drawDot(px + yp, py - x);
		drawDot(px - yn, py - x);
		drawDot(px - yn, py + x);
	}
}

void Brush::drawLine(Position p1, Position p2)
{
	uint16_t p1x = p1.getX(), p1y = p1.getY(), p2x = p2.getX(), p2y = p2.getY();
	uint16_t lenX, lenY, x, y;
	uint16_t width = getCanvasSize().getWidth(), height = getCanvasSize().getHeight();
	float slope;

	if(p1x == p2x && p1y == p2y)
	{
		drawDot(p1x, p2y);
		return;
	}

	if (p1x <= p2x && p1y <= p2y)
	{
		lenX = p2x - p1x;
		lenY = p2y - p1y;

		if (lenX > lenY)
		{
			slope = (float)lenY / (float)lenX;
			for (uint16_t i = 0; i <= lenX; i++)
			{
				x = p1x + i;
				y = p1y + slope * (float)i;
				drawDot(x, y);
			}
		}
		else
		{
			slope = (float)lenX / (float)lenY;
			for (uint16_t i = 0; i <= lenY; i++)
			{
				x = p1x + slope * (float)i;
				y = p1y + i;
				drawDot(x, y);
			}
		}
	}
	else if (p1x >= p2x && p1y <= p2y)
	{
		lenX = p1x - p2x;
		lenY = p2y - p1y;

		if (lenX > lenY)
		{
			slope = (float)lenY / (float)lenX;
			for (uint16_t i = 0; i <= lenX; i++)
			{
				x = p1x - i;
				y = p1y + slope * (float)i;
				drawDot(x, y);
			}
		}
		else
		{
			slope = (float)lenX / (float)lenY * (float)-1;
			for (uint16_t i = 0; i <= lenY; i++)
			{
				x = p1x + slope * (float)i;
				y = p1y + i;
				drawDot(x, y);
			}
		}
	}
	else if (p1x <= p2x && p1y >= p2y)
	{
		lenX = p2x - p1x;
		lenY = p1y - p2y;

		if (lenX > lenY)
		{
			slope = (float)lenY / (float)lenX * (float)-1;
			for (uint16_t i = 0; i <= lenX; i++)
			{
				x = p1x + i;
				y = p1y + slope * (float)i;
				drawDot(x, y);
			}
		}
		else
		{
			slope = (float)lenX / (float)lenY;
			for (uint16_t i = 0; i <= lenY; i++)
			{
				x = p1x + slope * (float)i;
				y = p1y - i;
				drawDot(x, y);
			}
		}
	}
	else
	{
		p1x = p2.getX();
		p2x = p1.getX();
		p1y = p2.getY();
		p2y = p1.getY();

		lenX = p2x - p1x;
		lenY = p2y - p1y;

		if (lenX > lenY)
		{
			slope = (float)lenY / (float)lenX;
			for (uint16_t i = 0; i <= lenX; i++)
			{
				x = p1x + i;
				y = p1y + slope * (float)i;
				drawDot(x, y);
			}
		}
		else
		{
			slope = (float)lenX / (float)lenY;
			for (uint16_t i = 0; i <= lenY; i++)
			{
				x = p1x + slope * (float)i;
				y = p1y + i;
				drawDot(x, y);
			}
		}
	}
}

void Brush::drawTriangle(Position p1, Position p2, Position p3)
{
	drawLine(p1, p2);
	drawLine(p2, p3);
	drawLine(p3, p1);
}

void Brush::drawRectangular(Rectangular rect)
{
	Position p1, p2;
	Size size = rect.getSize();
	
	p1 = rect.getPosition();
	p2 = p1;
	p2.addX(size.getWidth());
	drawLine(p1, p2);
	
	p1 = p2;
	p1.addY(size.getHeight());
	drawLine(p1, p2);
	
	p2 = p1;
	p2.subX(size.getWidth());	
	drawLine(p1, p2);

	p1 = p2;
	p1.subY(size.getHeight());
	drawLine(p1, p2);
}

void Brush::fillTriangle(Position p1, Position p2, Position p3)
{
	float slope1, slope2;
	bool nextDrawFlag = false;
	uint32_t des;
	int16_t p1x = p1.getX(), p2x = p2.getX(), p3x = p3.getX();
	int16_t p1y = p1.getY(), p2y = p2.getY(), p3y = p3.getY();
	int16_t sx, ex, ey, buf, cy = 0; 
	uint16_t width = getCanvasSize().getWidth(), height = getCanvasSize().getHeight();
	uint8_t offset = getPixelCapacity();
	Position p;
	
	if(p1y < p2y)
	{
		p = p1;
		p1 = p2;
		p2 = p;
	}
	
	if(p1y <p3y)
	{
		p = p1;
		p1 = p3;
		p3 = p;
	}

	if(p2x > p3x)
	{
		p = p2;
		p2 = p3;
		p3 = p;
	}

	p1x = p1.getX();
	p2x = p2.getX();
	p3x = p3.getX();
	p1y = p1.getY();
	p2y = p2.getY();
	p3y = p3.getY();

	if(p1y !=p3y && p1y != p2y)
	{
		if(p2y <p3y)
			ey = p1y -p3y;
		else
			ey = p1y - p2y;
	
		slope1 = (float)(p1x - p2x) / (float)(p1y - p2y);
		slope2 = (float)(p1x - p3x) / (float)(p1y -p3y);
	
		for(int32_t  y=0;y<=ey;y++)
		{
			sx = p1x - (y * slope1);
			ex = p1x - (y * slope2);

			if(sx > ex)
			{
				buf = sx;
				sx = ex;
				ex = buf;
			}
			cy = p1y - y;

			if(sx < 0)
				sx = 0;
		
			if(ex > width - 1)
				ex = width - 1;

			cy = p1y + y;
			des = cy * width * offset + sx * offset;
			fillDotArray(des, ex - sx, getBrushColor());
		}

		if(p1y < p2y)
		{
			p1x = ex;
			p1y = cy;
		}
	}
	else 
		nextDrawFlag = true;

	if(ey == p1y && nextDrawFlag == false)
		return;
	
	if(p1y > p2y)
	{
		p = p1;
		p1 = p2;
		p2 = p;
	}
	
	if(p1y >p3y)
	{
		p = p1;
		p1 = p3;
		p3 = p;
	}

	if(p2x > p3x)
	{
		p = p2;
		p2 = p3;
		p3 = p;
	}

	p1x = p1.getX();
	p2x = p2.getX();
	p3x = p3.getX();
	p1y = p1.getY();
	p2y = p2.getY();
	p3y = p3.getY();

	if(p1y ==p3y || p1y == p2y)
		return;

	slope1 = (float)(p2x - p1x) / (float)(p2y - p1y);
	slope2 = (float)(p3x - p1x) / (float)(p3y - p1y);

	if(p2y <p3y)
		ey = p2y - p1y;
	else
		ey =p3y - p1y;

	for(int32_t  y=0;y<=ey;y++)
	{
		sx = p1x + (y * slope1);
		ex = p1x + (y * slope2);

		if(sx > ex)
		{
			buf = sx;
			sx = ex;
			ex = buf;
		}

		if(sx < 0)
			sx = 0;
		
		if(ex > width - 1)
			ex = width - 1;

		cy = p1y + y;
		des = cy * width * offset + sx * offset;
		fillDotArray(des, ex - sx, getBrushColor());
	}
}

uint8_t Brush::drawChar(Position pos, uint32_t utf8)
{
	if (mFont == 0)
		return 0;

	Font::fontInfo_t *fontInfo = mFont->getFontInfo(utf8);

	if(fontInfo == 0)
		return 0;

	uint8_t *fontFb, color;
	int32_t  index = 0;
	int16_t width = fontInfo->width, height = fontInfo->height, offset = 0, xoffset;
	int16_t xs = pos.getX(), ys = pos.getY() + (int8_t)fontInfo->ypos;
	int16_t cwidth = getCanvasSize().getWidth(), cheight = getCanvasSize().getHeight();
	
	fontFb = fontInfo->data;
	xoffset = (int8_t)fontInfo->xpos;

	if(xoffset == 0) // 문자의 앞 여백이 없을 경우
		xoffset = 1; // 문자의 앞 여백 하나를 추가해줌
	
	xs += xoffset;

	if(width & 0x01) // 문자 크기가 홀수 일 경우
		width++; // 짝수로 만들어줌

	if (xs + width > cwidth)
	{
		width = cwidth - xs;
		offset = fontInfo->width - width;
	}
	if (ys + height > cheight)
		height = cheight - ys;

	width += xs;
	height += ys;

	for (int32_t  y = ys; y < height; y++)
	{
		for (int32_t  x = xs; x < width; x++, index++)
		{
			if (index % 2 == 0)
			{
				color = (fontFb[index / 2] & 0x0f) << 4 | 0x0F;
				blendDot(x, y, color);
			}
			else
			{
				color = fontFb[index / 2] | 0x0f;
				blendDot(x, y, color);
			}
		}
		index += offset;
	}

	return fontInfo->width + xoffset;
}

void Brush::setFont(Font &font)
{
	mFont = &font;
}

uint16_t Brush::drawString(Position pos, const char *str)
{
	if(mFont == 0)
		return 0;

	uint8_t width, charWidth = mFont->getCharWidth(), spaceWidth = mFont->getSpaceWidth();

	if (charWidth)
	{
		while (*str)
		{
			if (*str == ' ')
			{
				str++;
				pos.addX(spaceWidth);
			}
			else
			{
				width = drawChar(pos, mFont->getUtf8(&str));
				if (charWidth > width)
					pos.addX(charWidth);
				else
					pos.addX(width);
			}
		}
	}
	else
	{
		while (*str)
		{
			if (*str == ' ')
			{
				str++;
				pos.addX(spaceWidth);
			}
			else
				pos.addX(drawChar(pos, mFont->getUtf8(&str)));
		}
	}

	return pos.getX();
}

void Brush::drawBitmap(Position pos, const bitmap_t &bitmap)
{
	drawBitmapBase(pos, bitmap);
}

