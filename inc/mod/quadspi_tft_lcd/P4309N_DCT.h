/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_SPI_TFT_LCD_P4309N_DCT__H_
#define YSS_MOD_SPI_TFT_LCD_P4309N_DCT__H_

#include <mod/tft_lcd_driver/ST6201_qspi_with_Brush_RGB565.h>

// 구매처 : https://ko.aliexpress.com/item/1005006485444769.html

class P4309N_DCT : public ST6201_qspi_with_Brush_RGB565
{
public :
	P4309N_DCT(void);
	
	virtual error_t initialize(config_t config);

	virtual Size getLcdSize(void); // pure

	virtual Size getCanvasSize(void);

protected :
};

#endif

