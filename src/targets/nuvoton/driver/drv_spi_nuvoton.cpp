/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY) || defined(__M2xx_FAMILY)

#include <yss.h>
#include <stdint.h>
#include <drv/peripheral.h>
#include <targets/nuvoton/NuvotonSpi.h>
#include <yss/thread.h>
#include <yss/reg.h>

NuvotonSpi::NuvotonSpi(const Drv::setup_t drvSetup, const setup_t setup) : Spi(drvSetup)
{
	mDev = setup.dev;
	mTxDmaInfo = setup.txDmaInfo;
	mRxDmaInfo = setup.rxDmaInfo;
	mTxDma = nullptr;
	mRxDma = nullptr;
}

error_t NuvotonSpi::setSpecification(const specification_t &spec)
{
	if (mLastSpec == &spec)
		return error_t::ERROR_NONE;

	mLastSpec = &spec;

	uint32_t reg;
	uint32_t div, clk = Drv::getClockFrequency(), mode = 0;
	
	div = clk / spec.maxFreq;
	if(clk % spec.maxFreq == 0 && div > 0)
		div--;

	if(div > 0x1FF)
		return error_t::WRONG_CLOCK_FREQUENCY;

	switch(spec.mode)
	{
	case 0 :
		mode = 0x0 << SPI_CTL_RXNEG_Pos;
		break;

	case 1 :
		mode = 0x3 << SPI_CTL_RXNEG_Pos;
		break;

	case 2 :
		mode = 0x4 << SPI_CTL_RXNEG_Pos;
		break;

	case 3 :
		mode = 0x7 << SPI_CTL_RXNEG_Pos;
		break;
	}
	
	reg = mDev->CTL;
	reg &= ~(SPI_CTL_DWIDTH_Msk | SPI_CTL_RXNEG_Msk | SPI_CTL_TXNEG_Msk | SPI_CTL_CLKPOL_Msk);
	reg |= (spec.bit << SPI_CTL_DWIDTH_Pos) | mode;
	mDev->CTL = reg;

	mDev->CLKDIV = div;

	return error_t::ERROR_NONE;
}

error_t NuvotonSpi::initialize(config_t config)
{
	mMode = config.mode;

	switch(mMode)
	{
	case Spi::MODE_MAIN :	
		mDev->CTL = 0x00000034;	// Reset Value
		mDev->PDMACTL = SPI_PDMACTL_RXPDMAEN_Msk | SPI_PDMACTL_TXPDMAEN_Msk;
		break;
	
	default:
		return error_t::NOT_SUPPORTED_YET;
	}

	mTxDma = allocateDma();
	if(mTxDma == nullptr)
		return error_t::DMA_ALLOCATION_FAILED;

	mRxDma = allocateDma();
	if(mRxDma == nullptr)
		return error_t::DMA_ALLOCATION_FAILED;

	mTxDma->setSource(mTxDmaInfo.src);
	mRxDma->setSource(mRxDmaInfo.src);

	return error_t::ERROR_NONE;
}

void NuvotonSpi::enable(bool en)
{
	setBitData(mDev->CTL, en, SPI_CTL_SPIEN_Pos);
}

error_t NuvotonSpi::send(void *src, int32_t  size)
{
	if(size == 0)
		return error_t::ERROR_NONE;
	
	mRxDma->ready(mRxDmaInfo, src, size);
	mTxDma->transfer(mTxDmaInfo, src, size);

	while (mDev->STATUS & SPI_STATUS_BUSY_Msk)
		thread::yield();

	return error_t::ERROR_NONE;
}

error_t NuvotonSpi::exchange(void *des, int32_t  size)
{
	return error_t::ERROR_NONE;
}

uint8_t NuvotonSpi::exchange(uint8_t data)
{
	*(uint8_t*)&mDev->TX = data;

	while (mDev->STATUS & SPI_STATUS_BUSY_Msk)
		thread::yield();

	return mDev->RX;
}

void NuvotonSpi::send(uint8_t data)
{
	*(int8_t*)&mDev->TX = data;
	while (mDev->STATUS & SPI_STATUS_BUSY_Msk)
		thread::yield();
}

void NuvotonSpi::isr(void)
{

}

#endif
