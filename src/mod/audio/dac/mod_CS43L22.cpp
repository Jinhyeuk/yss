/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <mod/audio/dac/CS43L22.h>

#if !defined(YSS_DRV_I2C_UNSUPPORTED) || !defined(YSS_DRV_I2S_UNSUPPORTED)

typedef enum
{
	ID = 0x01,
	PWR_CTL1,
	PWR_CTL2 = 0x04,
	CLOCKING_CTL,
	INTERFACE_CTL1,
	INTERFACE_CTL2,
	PASSTHROUGH_A_SEL,
	PASSTHROUGH_B_SEL,
	ANALOG_ZC_AND_SR_SET,
	PASSTHROUGH_GANG_CTL = 0x0C,
	PLAYBACK_CTL1,
	MISC_CTL,
	PLAYBACK_CTL2,
	PASSTHROUGH_A_VOL = 0x14,
	PASSTHROUGH_B_VOL,
	PCMA_VOL = 0x1A,
	PCMB_VOL,
	BEEP_FREQ_ON_TIME,
	BEEP_VOL_OFF_TIME,
	BEEP_TONE_CTL,
	TONE_CTL,
	MASTER_A_VOL,
	MASTER_B_VOL,
	HP_A_VOL,
	HP_B_VOL,
	SPK_A_VOL,
	SPK_B_VOL,
	CH_MIXER_AND_SWAP,
	LIMIT_CTL1,
	LIMIT_CTL2,
	LIMITER_ATTACK_RATE,
	OVERFLOW_AND_CLK_STA = 0x2E,
	BATT_COMP,
	VP_BATT_LV,
	SPK_STA,
	CHARGE_PUMP_FREQ = 0x34
}register_t;

CS43L22::CS43L22(void)
{
	mResetPin = {0, 0};
	mI2c = nullptr;
	mI2s = nullptr;
	mAddr = AD0_LOW;
}

error_t CS43L22::initialize(config_t config)
{
	uint32_t lrclk;
	uint8_t data[5], temp, wordWidth;
	error_t result;

	mResetPin = config.resetPin;
	mI2c = &config.i2c;
	mI2s = &config.i2s;
	mAddr = config.ad0;

	if(mResetPin.port)
	{
		mResetPin.port->setOutput(mResetPin.pin, false);
		thread::delay(10);
		mResetPin.port->setOutput(mResetPin.pin, true);
		thread::delay(10);
	}

	data[0] = ID;
	mI2c->lock();
	result = mI2c->send(mAddr, data, 1);
	if(result != error_t::ERROR_NONE)
		goto error_handler;

	result = mI2c->receive(mAddr, &temp, 1);

	if(result != error_t::ERROR_NONE)
		goto error_handler;

	if((temp & 0xF8) != 0xE0)
	{
		result = error_t::DIFFERENT_DEVICE;
		goto error_handler;
	}
	
	temp &= 0x07;
	if(temp > 3)
	{
		result = error_t::DIFFERENT_DEVICE;
		goto error_handler;
	}
	
	// Required Initialization Settings
	data[0] = 0x00;
	data[1] = 0x99;
	result = mI2c->send(mAddr, data, 2);
	mI2c->stop();
	if(result != error_t::ERROR_NONE)
		goto error_handler;
	
	data[0] = 0x47;
	data[1] = 0x80;
	result = mI2c->send(mAddr, data, 2);
	mI2c->stop();
	if(result != error_t::ERROR_NONE)
		goto error_handler;

	data[0] = 0x32;
	result = mI2c->send(mAddr, data, 1);
	if(result != error_t::ERROR_NONE)
		goto error_handler;

	result = mI2c->receive(mAddr, &temp, 1);
	mI2c->stop();
	if(result != error_t::ERROR_NONE)
		goto error_handler;

	data[0] = 0x32;
	data[1] = temp | 0x80;
	result = mI2c->send(mAddr, data, 2);
	mI2c->stop();
	if(result != error_t::ERROR_NONE)
		goto error_handler;

	data[0] = 0x32;
	data[1] = temp & ~0x80;
	result = mI2c->send(mAddr, data, 2);
	mI2c->stop();
	if(result != error_t::ERROR_NONE)
		goto error_handler;

	data[0] = 0x00;
	data[1] = 0x00;
	result = mI2c->send(mAddr, data, 2);
	mI2c->stop();
	if(result != error_t::ERROR_NONE)
		goto error_handler;
	
	data[0] = PWR_CTL1;
	data[1] = 0x9E;
	result = mI2c->send(mAddr, data, 2);
	mI2c->stop();
	if(result != error_t::ERROR_NONE)
		goto error_handler;

	// Clock Control 설정
	data[0] = CLOCKING_CTL;
	result = mI2c->send(mAddr, data, 1);
	if(result != error_t::ERROR_NONE)
		goto error_handler;

	result = mI2c->receive(mAddr, &temp, 1);
	mI2c->stop();
	if(result != error_t::ERROR_NONE)
		goto error_handler;
	
	temp &= 0x60;
	lrclk = mI2s->getLrclkFrequency();
	if(lrclk >= 50000 && lrclk <= 100000)
		temp |= 0 << 5;
	else if(lrclk >= 25000)
		temp |= 1 << 5;
	else if(lrclk >= 12500)
		temp |= 2 << 5;
	else if(lrclk >= 4000)
		temp |= 3 << 5;
	else
	{
		result = error_t::WRONG_CLOCK_FREQUENCY;
		goto error_handler;
	}

	data[0] = CLOCKING_CTL;
	data[1] = temp;
	result = mI2c->send(mAddr, data, 2);
	mI2c->stop();
	if(result != error_t::ERROR_NONE)
		goto error_handler;

	// Interface Control 설정
	data[0] = INTERFACE_CTL1;
	result = mI2c->send(mAddr, data, 1);
	if(result != error_t::ERROR_NONE)
		goto error_handler;

	result = mI2c->receive(mAddr, &temp, 1);
	mI2c->stop();
	if(result != error_t::ERROR_NONE)
		goto error_handler;

	temp &= ~0x1F;
	wordWidth = mI2s->getWordWidth();
	switch(mI2s->getI2sStandard())
	{
	case I2s::STD_MSB_JUSTIFIED :
		break;
	
	case I2s::STD_I2S_PHILIPS :
		temp |= 0x01 << 2;
		break;

	case I2s::STD_LSB_JUSTIFIED :
		temp |= 0x02 << 2;

		switch(mI2s->getWordWidth())
		{
		case I2s::WORD_WIDTH_16BIT :
			temp |= 0x03;
			break;

		case I2s::WORD_WIDTH_18BIT :
			temp |= 0x02;
			break;
	
		case I2s::WORD_WIDTH_20BIT :
			temp |= 0x01;
			break;

		case I2s::WORD_WIDTH_24BIT :
			break;

		default :
			result = error_t::UNSUPPORTED_MODE;
			goto error_handler;
		}
		break;

	case I2s::STD_DSP :
		temp |= 0x10;

		switch(mI2s->getWordWidth())
		{
		case I2s::WORD_WIDTH_16BIT :
			temp |= 0x03;
			break;

		case I2s::WORD_WIDTH_20BIT :
			temp |= 0x02;
			break;
	
		case I2s::WORD_WIDTH_24BIT :
			temp |= 0x01;
			break;

		case I2s::WORD_WIDTH_32BIT :
			break;

		default :
			result = error_t::UNSUPPORTED_MODE;
			goto error_handler;
		}
		break;

	default :
		result = error_t::UNSUPPORTED_MODE;
		goto error_handler;
	}

	data[0] = INTERFACE_CTL1;
	data[1] = temp;
	result = mI2c->send(mAddr, data, 2);
	mI2c->stop();
	if(result != error_t::ERROR_NONE)
		goto error_handler;
	
	mI2c->unlock();

	return error_t::ERROR_NONE;

error_handler :
	mI2c->unlock();
	return result;
}

#endif

