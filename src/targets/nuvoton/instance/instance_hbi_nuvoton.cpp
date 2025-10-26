/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/peripheral.h>

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)

#include <targets/nuvoton/NuvotonHbi.h>
#include <config.h>
#include <yss.h>

#if HBI_ENABLE && defined(HBI)
NuvotonHbi hbi;

extern "C"
{
	void HBI_IRQHandler(void)
	{
		hbi.isr();
	}
}

#endif

#endif

