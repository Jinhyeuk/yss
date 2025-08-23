/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/mcu.h>
#include <yss/debug.h>

#if defined(STM32F4)

#include <stdint.h>
#include <drv/peripheral.h>
#include <drv/I2s.h>
#include <yss/thread.h>
#include <yss/reg.h>
#include <targets/st/bitfield.h>

I2s::I2s(const Drv::setup_t drvConfig, const setup_t config) : Drv(drvConfig)
{
	mDev = config.peri;
	mTxDma = &config.txDma;
	mTxDmaInfo = config.txDmaInfo;
	mRxDma = &config.rxDma;
	mRxDmaInfo = config.rxDmaInfo;
	mLastTransferIndex = 0;
	mCurrentDma = mTxDma;
	mDataBuffer = 0;
	mTransferBufferSize = 0;
	mDataSize = 2;
	mMode = MODE_NOT_INITIALIZED;
}

error_t I2s::initialize(const config_t &config)
{
	uint32_t clock = getClockFrequency(), div1, div2, odd, reg, wordWidth, std;

	switch(config.wordWidth)
	{
	case WORD_WIDTH_16BIT :
		wordWidth = 0;
		mDataSize = 2;
		div2 = 32;
		div1 = 8;
		break;

	case WORD_WIDTH_24BIT :
		wordWidth = 1;
		mDataSize = 4;
		div2 = 64;
		div1 = 4;
		break;

	case WORD_WIDTH_32BIT :
		wordWidth = 2;
		mDataSize = 4;
		div2 = 64;
		div1 = 4;
		break;

	default :
		return error_t::NOT_SUPPORTED_OPTION;
	}

	switch(config.std)
	{
	case STD_I2S_PHILIPS :
		std = 0;
		break;
	
	case STD_MSB_JUSTIFIED :
		std = 1;
		break;

	case STD_LSB_JUSTIFIED :
		std = 2;
		break;

	case STD_PCM:
		std = 3;
		break;
	
	default :
		return error_t::NOT_SUPPORTED_OPTION;
	}

	if(!config.mckoe)
		div1 = 1;
	
	div1 = clock / (div2 * div1);
	div1 = (div1 + config.sampleRate / 2) / config.sampleRate;
	
	odd = div1 & 0x01;
	div1 /= 2;

	reg = config.chlen << SPI_I2SCFGR_CHLEN_Pos | wordWidth << SPI_I2SCFGR_DATLEN_Pos | 0 << SPI_I2SCFGR_CKPOL_Pos | std << SPI_I2SCFGR_I2SSTD_Pos | 1 << SPI_I2SCFGR_I2SMOD_Pos;
	switch(config.mode)
	{
	case MODE_MAIN_TX :
		reg |= 2 << SPI_I2SCFGR_I2SCFG_Pos;
		mCurrentDma = mTxDma;
		break;

	case MODE_MAIN_RX :
		reg |= 3 << SPI_I2SCFGR_I2SCFG_Pos;
		mCurrentDma = mRxDma;
		break;

	case MODE_SUB_TX:
		reg |= 0 << SPI_I2SCFGR_I2SCFG_Pos;
		mCurrentDma = mTxDma;
		break;

	case MODE_SUB_RX:
		reg |= 1 << SPI_I2SCFGR_I2SCFG_Pos;
		mCurrentDma = mRxDma;
		break;
	
	default :
		return error_t::WRONG_CONFIG;
	}

	mMode = config.mode;

	setBitData(mDev->I2SCFGR, false, SPI_I2SCFGR_I2SE_Pos);	// I2S 비활성화
	
	mDev->I2SPR = config.mckoe << SPI_I2SPR_MCKOE_Pos | odd << SPI_I2SPR_ODD_Pos | div1 << SPI_I2SPR_I2SDIV_Pos;
	mDev->I2SCFGR = reg;
	mDev->CR2 = SPI_CR2_TXDMAEN_Msk | SPI_CR2_ERRIE_Msk;

	setBitData(mDev->I2SCFGR, true, SPI_I2SCFGR_I2SE_Pos);	// I2S 활성화

	return error_t::NOT_INITIALIZED;
}

error_t I2s::transfer(void *src, uint16_t count)
{
	mLastTransferIndex = count;
	mTransferBufferSize = count;
	mDataBuffer = (uint8_t*)src;
	
	switch(mMode)
	{
	case MODE_MAIN_TX :
	case MODE_SUB_TX :
		mCurrentDma->lock();
		mCurrentDma->ready(mTxDmaInfo, src, count);
		break;;
	case MODE_MAIN_RX :
	case MODE_SUB_RX :
		mCurrentDma->lock();
		mCurrentDma->ready(mRxDmaInfo, src, count);
		break;

	case MODE_NOT_INITIALIZED :
		return error_t::NOT_INITIALIZED;
	}
	
	return error_t::ERROR_NONE;
}

void I2s::stop(void)
{
	mCurrentDma->stop();
	mCurrentDma->unlock();
}

void I2s::isr(void)
{
	uint16_t sr = mDev->SR;
	if(sr & SPI_SR_FRE_Msk)
	{

	}

	if(sr & SPI_SR_OVR_Msk)
	{
		mDev->DR;
		mDev->DR;
	}
}

uint32_t I2s::getLrclkFrequency(void)
{
	uint32_t lrclk = getClockFrequency(), div;
	bool mckoe;
	
	div = ((mDev->I2SPR & SPI_I2SPR_I2SDIV_Msk) >> SPI_I2SPR_I2SDIV_Pos) * 2 + ((mDev->I2SPR & SPI_I2SPR_ODD_Msk) >> SPI_I2SPR_ODD_Pos);
	mckoe = (mDev->I2SPR & SPI_I2SPR_MCKOE_Msk) >> SPI_I2SPR_MCKOE_Pos;

	if(mckoe)
		lrclk /= 256 * div;
	else 
	{
		if(mDataSize == 2)
			lrclk /= 32 * div;
		else 
			lrclk /= 64 * div;
	}
	
	return lrclk;
}

uint32_t I2s::getMclkFrequency(void)
{
	uint32_t mclk = getClockFrequency(), div;
	bool mckoe;
	
	div = ((mDev->I2SPR & SPI_I2SPR_I2SDIV_Msk) >> SPI_I2SPR_I2SDIV_Pos) * 2 + ((mDev->I2SPR & SPI_I2SPR_ODD_Msk) >> SPI_I2SPR_ODD_Pos);
	mckoe = (mDev->I2SPR & SPI_I2SPR_MCKOE_Msk) >> SPI_I2SPR_MCKOE_Pos;

	if(mckoe)
		mclk /= div;
	else 
		mclk = 0;
	
	return mclk;
}

I2s::wordWidth_t I2s::getWordWidth(void)
{
	switch((mDev->I2SCFGR & SPI_I2SCFGR_DATLEN_Msk) >> SPI_I2SCFGR_DATLEN_Pos)
	{
	case 0 :
		return WORD_WIDTH_16BIT;
	
	case 1 :
		return WORD_WIDTH_24BIT;

	case 2 :
		return WORD_WIDTH_32BIT;

	default :
		return WORD_WIDTH_16BIT;
	}
}

I2s::std_t I2s::getI2sStandard(void)
{
	switch((mDev->I2SCFGR & SPI_I2SCFGR_I2SSTD_Msk) >> SPI_I2SCFGR_I2SSTD_Pos)
	{
	case 0 :
		return STD_I2S_PHILIPS;
	
	case 1 :
		return STD_MSB_JUSTIFIED;

	case 2 :
		return STD_LSB_JUSTIFIED;

	case 3 :
		return STD_PCM;

	default :
		return STD_I2S_PHILIPS;
	}
}

#endif
