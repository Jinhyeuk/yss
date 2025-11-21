/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)

#include <targets/nuvoton/NuvotonQuadspi.h>
#include <yss.h>

NuvotonQuadspi::NuvotonQuadspi(const Drv::setup_t drvSetup, const setup_t setup) : Quadspi(drvSetup)
{
	mDev = setup.dev;
	mTxDmaInfo = setup.txDmaInfo;
	mRxDmaInfo = setup.rxDmaInfo;
	mCapacity = 0;
	mDma = nullptr;
}

error_t NuvotonQuadspi::initialize(config_t config)
{
	if(config.mode == MODE_SUB)
		return error_t::NOT_SUPPORTED_YET;
	
	mDma = system::allocateDma();
//	mDev->FIFOCTL = 1 << QSPI_FIFOCTL_TXTH_Pos;
	mDev->PDMACTL = QSPI_PDMACTL_PDMARST_Msk;
	if(mDma == nullptr)
		return error_t::DMA_ALLOCATION_FAILED;
	else
		return error_t::ERROR_NONE;
}

error_t NuvotonQuadspi::setSpecification(const specification_t &spec)
{
	uint32_t clk = getClockFrequency(), mode;
	uint32_t div = (clk + spec.maxFrequncy - 1) / spec.maxFrequncy;

	if(div > 0)
		div--;
	
	if(spec.maxFrequncy < clk / (div + 1))
		return error_t::WRONG_CLOCK_FREQUENCY;

	mDev->CLKDIV = div;
	mCapacity = spec.capacity;

	switch(spec.clockMode)
	{
	case CLOCK_MODE_MODE0 :
		mode = 0x3;
		break;

	case CLOCK_MODE_MODE1 :
		mode = 0x0;
		break;

	case CLOCK_MODE_MODE2 :
		mode = 0x7;
		break;

	case CLOCK_MODE_MODE3 :
		mode = 0x4;
		break;
	}
	
	mClockMode = 0;
	setFieldData(mClockMode, QSPI_CTL_CLKPOL_Msk | QSPI_CTL_TXNEG_Msk | QSPI_CTL_RXNEG_Msk, mode, QSPI_CTL_RXNEG_Pos);
	setFieldData(mClockMode, QSPI_CTL_SUSPITV_Msk, 0, QSPI_CTL_SUSPITV_Pos);

	return error_t::ERROR_NONE;
}

error_t NuvotonQuadspi::transmit(dataform_t dataform, uint32_t data)
{
	uint32_t ctl = QSPI_CTL_SPIEN_Msk | mClockMode, buf;
	
	ctl |= (dataform.dataWidth + 8 & 0x1F) << QSPI_CTL_DWIDTH_Pos;
	ctl |= dataform.bitWidth << QSPI_CTL_DUALIOEN_Pos;

	mDev->CTL = ctl;
	mDev->TX = data;

	while(mDev->STATUS & QSPI_STATUS_BUSY_Msk)
		thread::yield();

	return error_t::ERROR_NONE;
}

error_t NuvotonQuadspi::receive(dataform_t dataform, uint32_t &data)
{
	return error_t::ERROR_NONE;
}

error_t NuvotonQuadspi::transmit(dataform_t dataform, void *data, uint32_t count)
{
	uint32_t ctl = QSPI_CTL_SPIEN_Msk | mClockMode, buf;
	uint8_t *byte = (uint8_t*)data;
	uint16_t *hw = (uint16_t*)data;
	uint32_t *wd = (uint32_t*)data;
	
	ctl |= (dataform.dataWidth + 8 & 0x1F) << QSPI_CTL_DWIDTH_Pos;
	ctl |= dataform.bitWidth << QSPI_CTL_DUALIOEN_Pos;
	
	mDev->CTL = ctl;
	
	switch(dataform.dataWidth)
	{
	case Quadspi::DATA_WIDTH_8BIT :
		while(count)
		{
			if(~mDev->STATUS & QSPI_STATUS_TXFULL_Msk)
			{
				mDev->TX = *byte++;
				count--;
			}
			else
				thread::yield();
		}
		break;

	case Quadspi::DATA_WIDTH_9BIT :
	case Quadspi::DATA_WIDTH_10BIT :
	case Quadspi::DATA_WIDTH_11BIT :
	case Quadspi::DATA_WIDTH_12BIT :
	case Quadspi::DATA_WIDTH_13BIT :
	case Quadspi::DATA_WIDTH_14BIT :
	case Quadspi::DATA_WIDTH_15BIT :
	case Quadspi::DATA_WIDTH_16BIT :
		while(count)
		{
			if(~mDev->STATUS & QSPI_STATUS_TXFULL_Msk)
			{
				mDev->TX = *hw++;
				count--;
			}
			else
				thread::yield();
		}
		break;
	
	default :
		while(count)
		{
			if(~mDev->STATUS & QSPI_STATUS_TXFULL_Msk)
			{
				mDev->TX = *wd++;
				count--;
			}
			else
				thread::yield();
		}
		break;
	}
	
	while(mDev->STATUS & QSPI_STATUS_BUSY_Msk)
		thread::yield();
	
	// DMA 전송 실패 코드
	//mDma->ready(mTxDmaInfo, data, size);
	//mDev->PDMACTL = QSPI_PDMACTL_TXPDMAEN_Msk;

	//while(!mDma->isComplete())
	//	thread::yield();

	//mDev->CTL = 0;
	//mDev->PDMACTL = 0;
	
	return error_t::ERROR_NONE;
}

void NuvotonQuadspi::isr(void)
{
	mDev->STATUS = QSPI_STATUS_UNITIF_Msk;
}

#endif

