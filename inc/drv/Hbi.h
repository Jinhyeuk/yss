/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_HBI__H_
#define YSS_DRV_HBI__H_

#include "Drv.h"
#include <yss/error.h>

class Hbi
{
public:
	typedef enum
	{
		BURST_GROUP_SIZE_16BYTES = 0,
		BURST_GROUP_SIZE_32BYTES,
		BURST_GROUP_SIZE_64BYTES,
		BURST_GROUP_SIZE_128BYTES
	}bustGroupSize_t;

    typedef struct
	{
		float tCSS_min_ns;
		float tACC_min_ns;
		float tCSH_min_ns;
		float tCSHI_min_ns;
		float tCSM_max_us;
		bustGroupSize_t bgs;
		uint32_t capcacity;
		uint32_t maxFrequency;
	}config_t;

	virtual error_t initialize(config_t config, uint32_t ahbclkFreq) __attribute__((optimize("-O1"))) = 0;

	uint32_t getCapacity(void);

	// 여기부터 아래 내용들은 사용자가 호출할 필요가 없는 함수입니다.
protected:
	uint32_t mCapacity;

};

#endif

