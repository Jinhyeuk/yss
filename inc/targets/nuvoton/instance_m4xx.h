/*
 * Copyright (c) 2024 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_INSTANCE_M48X__H_
#define YSS_INSTANCE_M48X__H_

#include <yss/instance.h>

// YSS OS RUNTIME 설정 관련 정의
#define RUNTIME_TIMER0		1
#define RUNTIME_TIMER1		2
#define RUNTIME_TIMER2		3
#define RUNTIME_TIMER3		4

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
#include "NuvotonBpwm.h"

extern Bpwm bpwm0;
extern Bpwm bpwm1;
#endif

extern Clock clock;

#if defined(__M480_FAMILY)
extern DmaChannel1 dmaChannel1;
extern DmaChannel2 dmaChannel2;
extern DmaChannel3 dmaChannel3;
extern DmaChannel4 dmaChannel4;
extern DmaChannel5 dmaChannel5;
extern DmaChannel6 dmaChannel6;
extern DmaChannel7 dmaChannel7;
extern DmaChannel8 dmaChannel8;
extern DmaChannel9 dmaChannel9;
extern DmaChannel10 dmaChannel10;
extern DmaChannel11 dmaChannel11;
extern DmaChannel12 dmaChannel12;
extern DmaChannel13 dmaChannel13;
extern DmaChannel14 dmaChannel14;
extern DmaChannel15 dmaChannel15;
extern DmaChannel16 dmaChannel16;
#elif defined(__M4xx_FAMILY)
extern DmaChannel1 dmaChannel1;
extern DmaChannel2 dmaChannel2;
extern DmaChannel3 dmaChannel3;
extern DmaChannel4 dmaChannel4;
extern DmaChannel5 dmaChannel5;
extern DmaChannel6 dmaChannel6;
extern DmaChannel7 dmaChannel7;
extern DmaChannel8 dmaChannel8;
extern DmaChannel9 dmaChannel9;
#endif

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
#include "NuvotonEpwm.h"

extern Epwm epwm0;
extern Epwm epwm1;
#endif

extern Flash flash;

#include "class_gpio.h"
#if defined(PA)
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
#if defined(PI)
extern Gpio gpioI;
#endif
#if defined(PJ)
extern Gpio gpioJ;
#endif

#include "NuvotonHbi.h"
#if defined(HBI)
extern NuvotonHbi hbi;
#endif

#include "NuvotonI2c.h"
#if defined(I2C0)
extern NuvotonI2c i2c0;
#endif
#if defined(I2C1)
extern NuvotonI2c i2c1;
#endif
#if defined(I2C2)
extern NuvotonI2c i2c2;
#endif

#if defined(__M480_FAMILY)
#include "NuvotonI2sInSpi.h"

extern NuvotonI2sInSpi i2s0;
extern NuvotonI2sInSpi i2s1;
extern NuvotonI2sInSpi i2s2;
extern NuvotonI2sInSpi i2s3;
#elif defined(__M4xx_FAMILY)
#include "NuvotonI2sInSpi.h"

extern NuvotonI2sInSpi i2s0;
extern NuvotonI2sInSpi i2s1;
#endif

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
extern PwmCh1 pwm0;
extern PwmCh1 pwm1;
extern PwmCh1 pwm2;
extern PwmCh1 pwm3;
#endif

#if defined(__M46x_SUBFAMILY)
#include "NuvotonSdh.h"

extern NuvotonSdh sdh0;
extern NuvotonSdh sdh1;
#endif

#include "NuvotonSpi.h"
#if defined(__M480_FAMILY)
extern Spi spi0;
extern Spi spi1;
extern Spi spi2;
extern Spi spi3;
#elif defined(__M4xx_FAMILY)
extern NuvotonSpi spi0;
extern NuvotonSpi spi1;
#endif

#include "NuvotonTmr.h"

extern NuvotonTmr timer0;
extern NuvotonTmr timer1;
extern NuvotonTmr timer2;
extern NuvotonTmr timer3;

#if defined(__M480_FAMILY)
extern Uart uart0;
extern Uart uart1;
extern Uart uart2;
extern Uart uart3;
extern Uart uart4;
extern Uart uart5;
extern Uart uart6;
extern Uart uart7;
#elif defined(__M4xx_FAMILY)
#include "NuvotonUart.h"

extern NuvotonUart uart0;
extern NuvotonUart uart1;
extern NuvotonUart uart2;
extern NuvotonUart uart3;
#endif

#if defined(__M480_FAMILY) || defined(__M4xx_FAMILY)
extern Usbd usbd;
#endif

#endif

