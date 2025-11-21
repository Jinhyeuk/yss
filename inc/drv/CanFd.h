/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_CAN_FD__H_
#define YSS_DRV_CAN_FD__H_

#include "Can.h"

typedef enum
{
	DLC_0BYTE = 0,
	DLC_1BYTE1,
	DLC_2BYTES,
	DLC_3BYTES,
	DLC_4BYTES,
	DLC_5BYTES,
	DLC_6BYTES,
	DLC_7BYTES,
	DLC_8BYTES,
	DLC_12BYTES,
	DLC_16BYTES,
	DLC_20BYTES,
	DLC_24BYTES,
	DLC_32BYTES,
	DLC_48BYTES,
	DLC_64BYTES
}dlc_t;

typedef struct 
{
	bool xtd;
	bool fdf;
	uint32_t id;
	dlc_t dlc;
	uint8_t data[64];
}canfdMsg_t;

class CanFd : public Can
{
public :
	virtual uint32_t getDataBuadrate(void) = 0;

	virtual float getDataSamplePoint(void) = 0;

	virtual void sendStdCanfdMessage(uint16_t id, uint8_t *src, dlc_t dlc, bool brs = true) = 0;

	virtual void sendXtdCanfdMessage(uint32_t id, uint8_t *src, dlc_t dlc, bool brs = true) = 0;

	virtual canfdMsg_t getNewRxCanfdMessage(void) = 0;

	// 아래 함수들은 시스템 함수로 사용자의 호출을 금지합니다.
	CanFd(const Drv::setup_t drvSetup);

protected :
	static const uint8_t mDlcTable[16];
};

#endif

