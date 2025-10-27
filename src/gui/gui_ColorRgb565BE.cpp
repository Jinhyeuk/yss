/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <gui/ColorRgb565BE.h>
#include <cmsis/cmsis_compiler.h>

ColorRgb565BE::ColorRgb565BE(void)
{
	setColorBase(0x00, 0x00, 0x00);
}

ColorRgb565BE::ColorRgb565BE(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	setColorBase(red, green, blue, alpha);
}

ColorRgb565BE::ColorRgb565BE(Color obj)
{
	Color::setColor(obj);
}

void  ColorRgb565BE::setColorBase(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
{
	uint8_t code[2];

	mRed = red;
	mGreen = green;
	mBlue = blue;
	mAlapha = alpha;

	code [1] = (mGreen & 0xFC) << 3;
	code [1] |= mRed >> 3;
	code [0] = mBlue & 0xF8;
	code [0] |= mGreen >> 5;

	mCode = *(uint16_t*)code;
}
