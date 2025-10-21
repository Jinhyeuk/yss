/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_NUVOTON_DRV_I2C__H_
#define YSS_NUVOTON_DRV_I2C__H_

#include <drv/I2c.h>
#include <yss/error.h>

class NuvotonI2c : public I2c
{
public:
	virtual error_t initialize(mainConfig_t config) __attribute__((optimize("-O1")));

	virtual error_t send(uint8_t addr, void *src, uint32_t size, uint32_t timeout = 500) __attribute__((optimize("-O1")));

	virtual error_t receive(uint8_t addr, void *des, uint32_t size, uint32_t timeout = 500) __attribute__((optimize("-O1")));

	virtual void stop(void) __attribute__((optimize("-O1")));

	// 여기부터 아래 내용들은 사용자가 호출할 필요가 없는 함수입니다.
	struct setup_t
	{
		I2C_T *dev;
	};

	NuvotonI2c(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

	void isr(void) __attribute__((optimize("-O1")));

private :
	I2C_T *mDev;
	int32_t mDataCount;
	uint8_t *mDataBuf, mAddr;
	error_t mError;
	bool mDir, mComplete;
};

#endif

