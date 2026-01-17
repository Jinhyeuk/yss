/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_NUVOTON_DRV_SDH__H_
#define YSS_NUVOTON_DRV_SDH__H_

#include <drv/Sdmmc.h>
#include <drv/Dma.h>
#include <yss/error.h>

class NuvotonSdh : public Sdmmc
{
public :
	virtual error_t initialize(void);

	// 여기부터 아래 내용들은 사용자가 호출할 필요가 없는 함수입니다.
	typedef struct
	{
		SDH_T *dev;
		void (*setSdhClockFrequency)(uint32_t freq);
	}setup_t;

	NuvotonSdh(const Drv::setup_t &drvSetup, const setup_t &setup);

private :
	SDH_T *mDev;
	Dma *mTxDma, *mRxDma;
	Dma::dmaInfo_t mTxDmaInfo, mRxDmaInfo;
	bool mAcmdFlag;
	uint8_t mBlockSize;
	void (*setSdhClockFrequency)(uint32_t freq);

protected:
	virtual error_t sendPowerOn74Clock(void);

	virtual error_t sendCmd(cmd_t cmd, uint32_t arg, response_t responseType);

	virtual uint32_t getShortResponse(void);

	virtual void getLongResponse(void *des);

	virtual void setSdioClockBypass(bool en);

	virtual void setSdioClockEn(bool en);

	virtual void setClockFrequency(int32_t  frequency);

	virtual void enablePower(bool en = true);

	virtual void readyRead(void *des, uint16_t length);

	virtual void stopReadyRead(void);

	virtual void readyWrite(void *des, uint16_t length);

	virtual void setDataBlockSize(uint16_t blockSize);

	virtual error_t waitUntilReadComplete(void);

	virtual error_t waitUntilWriteComplete(void);

	virtual bool setBusWidth(busWidth_t width);
};

#endif

