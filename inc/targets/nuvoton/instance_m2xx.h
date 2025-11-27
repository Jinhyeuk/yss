/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_INSTANCE_M2XX__H_
#define YSS_INSTANCE_M2XX__H_

#include <yss/instance.h>

// YSS OS RUNTIME 설정 관련 정의
#define RUNTIME_TIMER0		1
#define RUNTIME_TIMER1		2
#define RUNTIME_TIMER2		3
#define RUNTIME_TIMER3		4

#if defined(BPWM0)
#include "NuvotonBpwm.h"
extern NuvotonBpwm bpwm0;
#endif

#if defined(BPWM1)
extern NuvotonBpwm bpwm1;
#endif

#include "NuvotonClock.h"
extern Clock clock;

#if defined(__M2xx_FAMILY)
#include "NuvotonDma.h"

extern DmaChannel1 dmaChannel1;
extern DmaChannel2 dmaChannel2;
extern DmaChannel3 dmaChannel3;
extern DmaChannel4 dmaChannel4;
extern DmaChannel5 dmaChannel5;
extern DmaChannel6 dmaChannel6;
extern DmaChannel7 dmaChannel7;
extern DmaChannel8 dmaChannel8;
#endif

#if defined(PA)
#include "NuvotonGpio.h"
extern Gpio gpioA;
#endif
#if defined(PB)
extern Gpio gpioB;
#endif
#if defined(PC)
extern Gpio gpioC;
#endif
#if defined(PD)
extern Gpio gpioD;
#endif
#if defined(PE)
extern Gpio gpioE;
#endif
#if defined(PF)
extern Gpio gpioF;
#endif
#if defined(PG)
extern Gpio gpioG;
#endif
#if defined(PH)
extern Gpio gpioH;
#endif

#if defined(I2C0)
#include "NuvotonI2c.h"
extern NuvotonI2c i2c0;
#endif
#if defined(I2C1)
extern NuvotonI2c i2c1;
#endif

#if defined(SPI0)
#include "NuvotonSpi.h"

extern NuvotonSpi spi0;
#endif

#if defined(SPI1)
extern NuvotonSpi spi1;
#endif

#if defined(UART0)
#include "NuvotonUart.h"
extern NuvotonUart uart0;
#endif

#if defined(UART1)
extern NuvotonUart uart1;
#endif

#if defined(UART2)
extern NuvotonUart uart2;
#endif

#if defined(UART3)
extern NuvotonUart uart3;
#endif

#if defined(USBD)
extern Usbd usbd;
#endif

#endif

