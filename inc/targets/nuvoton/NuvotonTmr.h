/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_NUVOTON_DRV_TMR__H_
#define YSS_NUVOTON_DRV_TMR__H_

#include <drv/Timer.h>
#include <yss/error.h>

/*
	MCU의 기본 타이머를 사용하는 장치의 드라이버 입니다.
	MCU의 내장 장치로 향상된 타이머가 별도로 있는 경우 이 Timer에 포함되지 않습니다.
	향상된 타이머라고 하지만 타이머 기능에 대한 레지스터 맵이 동일할 경우는 포함될 수 있습니다.
*/
class NuvotonTmr : public Timer
{
public:
	virtual error_t initialize(uint32_t freq) __attribute__((optimize("-O1")));

	/*
		타이머를 1회만 동작하도록 설정합니다.
		initialize() 함수를 호출하기 전에 이 함수를 호출할 경우 효과가 무시 될 수 있습니다.
		그러므로 반드시 initialize() 함수를 호출하고 이후에 호출되야 합니다.
		initialize() 함수 호출후 기본값은 false 입니다.
		.
		@ en : 타이머를 1회 동작하도록 설정 할 경우 true를, 연속해서 계속 실행하게 할 경우 false를 설정합니다.
	*/
	virtual void setOnePulse(bool en) __attribute__((optimize("-O1")));
	
	/*
		타이머의 카운터를 시작합니다.
	*/
	virtual void start(void) __attribute__((optimize("-O1")));
	
	/*
		타이머의 카운터를 정지합니다.
	*/
	virtual void stop(void) __attribute__((optimize("-O1")));
	
	/*
		타이머의 동작 주파수를 변경합니다.
		타이머가 동작중에 주파수 변경이 가능합니다.
		MCU에 따라 일시적으로 함수 내부에서 장치를 멈추게 하는 경우도 있습니다.
		.
		@ freq : 타이머의 동작 주파수를 설정합니다. 타이머의 클럭 상황에 따라 주파수가 정확하게 나오지 않을 수 있습니다.
	*/
	virtual error_t changeFrequency(uint32_t freq) __attribute__((optimize("-O1")));

	virtual uint32_t getCounterValue(void) __attribute__((optimize("-O1")));

	// 아래 함수들은 시스템 함수로 사용자의 호출을 금지합니다.
	struct setup_t
	{
		TIMER_T *dev;
	};

	NuvotonTmr(const Drv::setup_t drvSetup, const setup_t setup) __attribute__((optimize("-O1")));

private :
	TIMER_T *mDev;
};

#endif

