/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_DRV_NUVOTON_HBI__H_
#define YSS_DRV_NUVOTON_HBI__H_

#include <drv/Hbi.h>

class NuvotonHbi : public Hbi
{
public:
	virtual error_t initialize(config_t config, uint32_t hbiClkFreq) __attribute__((optimize("-O1")));

	// 여기부터 아래 내용들은 사용자가 호출할 필요가 없는 함수입니다.
	void isr(void) __attribute__((optimize("-O1")));

private :
	HBI_T *mDev;
};

#endif

