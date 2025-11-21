/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <config.h>

#include <mod/tft_lcd_driver/ST6201_qspi_with_Brush_RGB565.h>

static const Quadspi::specification_t gSpec = 
{
	40000000,					//uint32_t maxFrequncy;
	0xFFFF,						//uint32_t capacity;
	Quadspi::CLOCK_MODE_MODE0	//uint8_t clockMode;
};

static const Quadspi::dataform_t gCmdForm =
{
	Quadspi::BIT_WIDTH_SINGLE,	//bitWidth_t bitWidth;
	Quadspi::DATA_WIDTH_32BIT	//dataWidth_t dataWidth;
};

static const Quadspi::dataform_t g1ByteForm =
{
	Quadspi::BIT_WIDTH_SINGLE,	//bitWidth_t bitWidth;
	Quadspi::DATA_WIDTH_8BIT	//dataWidth_t dataWidth;
};

ST6201_qspi_with_Brush_RGB565::ST6201_qspi_with_Brush_RGB565(void)
{

}

void ST6201_qspi_with_Brush_RGB565::setConfig(const config_t &config)
{
	mDev = &config.dev;
	mDev->setSpecification(gSpec);

	mRstPin = config.reset;
	mCsPin = config.cs;

	mCsPin.port->setOutput(mCsPin.pin, true);
}

void ST6201_qspi_with_Brush_RGB565::reset(void)
{
	if(mRstPin.port)
	{
		mRstPin.port->setOutput(mRstPin.pin, false);
		thread::delay(100);
		mRstPin.port->setOutput(mRstPin.pin, true);
		thread::delay(100);
	}
}

void ST6201_qspi_with_Brush_RGB565::sendCmd(uint8_t cmd)
{
	uint32_t buf;

	mCsPin.port->setOutput(mCsPin.pin, false);
	buf = 0x02000000 | cmd << 8;
	mDev->transmit(gCmdForm, buf);
	mCsPin.port->setOutput(mCsPin.pin, true);
}

void ST6201_qspi_with_Brush_RGB565::sendCmd(uint8_t cmd, uint8_t data)
{
	uint32_t buf;

	mCsPin.port->setOutput(mCsPin.pin, false);
	buf = 0x02000000 | cmd << 8;
	mDev->transmit(gCmdForm, buf);
	mDev->transmit(g1ByteForm, data);
	mCsPin.port->setOutput(mCsPin.pin, true);
}

void ST6201_qspi_with_Brush_RGB565::sendCmd(uint8_t cmd, uint8_t *data, uint32_t count)
{
	uint32_t buf;
	Quadspi::dataform_t dataform = 
	{
		Quadspi::BIT_WIDTH_SINGLE,
		Quadspi::DATA_WIDTH_8BIT
	};

	mCsPin.port->setOutput(mCsPin.pin, false);
	buf = 0x02000000 | cmd << 8;
	mDev->transmit(gCmdForm, buf);
	mDev->transmit(dataform, data, count);
	mCsPin.port->setOutput(mCsPin.pin, true);
}

void ST6201_qspi_with_Brush_RGB565::sendData(uint8_t *data, uint32_t len)
{
	uint32_t buf;
	Quadspi::dataform_t dataform = 
	{
		Quadspi::BIT_WIDTH_SINGLE,
		Quadspi::DATA_WIDTH_8BIT
	};

	mCsPin.port->setOutput(mCsPin.pin, false);
	buf = 0x02002C00;
	mDev->transmit(gCmdForm, buf);
	mDev->transmit(dataform, data, len);
	mCsPin.port->setOutput(mCsPin.pin, true);
}

void ST6201_qspi_with_Brush_RGB565::sendData(uint16_t *data, uint32_t len)
{
	uint32_t buf;
	Quadspi::dataform_t dataform = 
	{
		Quadspi::BIT_WIDTH_SINGLE,
		Quadspi::DATA_WIDTH_16BIT
	};

	mCsPin.port->setOutput(mCsPin.pin, false);
	buf = 0x02002C00;
	mDev->transmit(gCmdForm, buf);
	mDev->transmit(dataform, data, len);
	mCsPin.port->setOutput(mCsPin.pin, true);
}

void ST6201_qspi_with_Brush_RGB565::sendData(uint32_t *data, uint32_t len)
{
	uint32_t buf;
	Quadspi::dataform_t dataform = 
	{
		Quadspi::BIT_WIDTH_SINGLE,
		Quadspi::DATA_WIDTH_32BIT
	};

	mCsPin.port->setOutput(mCsPin.pin, false);
	buf = 0x02002C00;
	mDev->transmit(gCmdForm, buf);
	mDev->transmit(dataform, data, len);
	mCsPin.port->setOutput(mCsPin.pin, true);
}

void ST6201_qspi_with_Brush_RGB565::enable(void)
{
}

void ST6201_qspi_with_Brush_RGB565::disable(void)
{
}

#if USE_GUI == true

#include <mod/tft_lcd_driver/ST7789V_spi_with_Brush_RGB565.h>
#include <yss/debug.h>

#if !defined(YSS_DRV_SPI_UNSUPPORTED) && !defined(YSS_DRV_GPIO_UNSUPPORTED)

static const Spi::specification_t gLcdSpec =
{
	Spi::CLOCK_MODE_MODE0,	//uint8_t mode;
	15000000,			//uint32_t maxFreq;
	Spi::BIT_BIT8		//uint8_t bit;
};

ST7789V_spi_with_Brush_RGB565::ST7789V_spi_with_Brush_RGB565(void)
{
	mSpec = &gLcdSpec;
}

void ST7789V_spi_with_Brush_RGB565::setSpiSpecification(const Spi::specification_t &spec)
{
	mSpec = &spec;
}

void ST7789V_spi_with_Brush_RGB565::setConfig(const config_t &config)
{
	mPeri = &config.peri;
	mCsPin = config.chipSelect;
	mDcPin = config.dataCommand;
	mRstPin = config.reset;

	if(mRstPin.port)
		mRstPin.port->setOutput(mRstPin.pin, false);
	mCsPin.port->setOutput(mCsPin.pin, true);
}



void ST7789V_spi_with_Brush_RGB565::read(uint8_t cmd, uint8_t &des)
{
	mDcPin.port->setOutput(mDcPin.pin, false);
	mCsPin.port->setOutput(mCsPin.pin, false);
	mPeri->send(cmd);
	mDcPin.port->setOutput(mDcPin.pin, true);
	des = mPeri->exchange(0);
	mCsPin.port->setOutput(mCsPin.pin, true);	
}


void ST7789V_spi_with_Brush_RGB565::reset(void)
{
	if(mRstPin.port)
	{
		mRstPin.port->setOutput(mRstPin.pin, false);
		thread::delay(10);
		mRstPin.port->setOutput(mRstPin.pin, true);
	}
	else
	{
		enable();
		sendCmd(SOFTWARE_RESET);
		disable();
	}
}

#endif

#endif

