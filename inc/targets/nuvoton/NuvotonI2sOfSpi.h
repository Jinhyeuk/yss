/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_NUVOTON_DRV_I2S__H_
#define YSS_NUVOTON_DRV_I2S__H_

#include <drv/peripheral.h>
#include <drv/I2s.h>
#include <drv/Dma.h>

class NuvotonI2sOfSpi : public I2s
{
public :
	error_t initialize(const config_t &config) __attribute__((optimize("-O1")));
	
	uint32_t getLrclkFrequency(void) __attribute__((optimize("-O1")));
	
	uint32_t getMclkFrequency(void) __attribute__((optimize("-O1")));
	
	error_t transfer(void *src, uint16_t count) __attribute__((optimize("-O1")));
	
	void stop(void) __attribute__((optimize("-O1")));
	
	uint32_t getTxCount(void) __attribute__((optimize("-O1")));
	
	uint32_t getRxCount(void) __attribute__((optimize("-O1")));
	
	void* getCurrentBuffer(void) __attribute__((optimize("-O1")));
	
	void releaseBuffer(int32_t count) __attribute__((optimize("-O1")));

	uint32_t getChannelFrameSize(void) __attribute__((optimize("-O1")));

	wordWidth_t getWordWidth(void)  __attribute__((optimize("-O1")));

	std_t getI2sStandard(void)  __attribute__((optimize("-O1")));
	
	// 아래 함수들은 시스템 함수로 사용자 호출을 금지합니다.
	typedef struct
	{
		SPI_T *dev;
		Dma::dmaInfo_t txDmaInfo;
		Dma::dmaInfo_t rxDmaInfo;
	}setup_t;

	NuvotonI2sOfSpi(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

	void isr(void) __attribute__((optimize("-O1")));

private :
	SPI_T *mDev;
	Dma::dmaInfo_t mTxDmaInfo, mRxDmaInfo;
	uint32_t mReleasedSentCount;

	uint32_t mLrclk, mMclk;
};

#endif

