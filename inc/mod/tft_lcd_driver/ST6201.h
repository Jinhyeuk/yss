/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_TFT_LCD_DRIVER_ILI9341__H_
#define YSS_MOD_TFT_LCD_DRIVER_ILI9341__H_

#include <yss/instance.h>
#include <sac/TftLcdDriver.h>

class ST6201 : public TftLcdDriver
{
  protected:
	typedef enum
	{
	}cmd_t;

	bool mRotateFlag;

  public:
	ST6201(void);

	void setDirection(bool xMirror, bool yMirror, bool rotate);

	void setWindows(uint16_t x, uint16_t y, uint16_t width = 1, uint16_t height = 1);
};

#endif

