/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_SPI_TFT_LCD_P028B052_V3_IPS__H_
#define YSS_MOD_SPI_TFT_LCD_P028B052_V3_IPS__H_

#include <mod/tft_lcd_driver/ST7789V_spi_with_Brush_RGB565.h>

// 구매처 : https://www.alibaba.com/product-detail/Polcd-2-8-inch-Lcd-Display_1601210824541.html?spm=a2700.galleryofferlist.normal_offer.d_title.301213a0U102Ki&priceId=b473ad8892c0448ca8aa6dbb79fcdef5

class P028B052_V3_IPS : public ST7789V_spi_with_Brush_RGB565
{
  public:
	P028B052_V3_IPS(void);
	
	// TftLcdDriver
	virtual error_t initialize(void); // pure

	virtual Size_t getLcdSize(void); // pure
};

#endif

