/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MUTEX__H_
#define YSS_MUTEX__H_	`

#include <stdint.h>
#include <drv/peripheral.h>

class Mutex
{
public:

	/*
		뮤텍스를 잠그고 다른 쓰레드의 진입을 막습니다.
		.
		@ return : 현재의 lock key 값을 반환합니다.
	*/
	uint32_t lock(void) __attribute__((optimize("-O1")));
	
	/*
		뮤텍스를 잠글 수 있는지 확인합니다. 만약 잠글 수 있다면 잠급니다.
		.
		@ return : 잠금 상태를 반환합니다. 다른 쓰레드에 의해 잠겨지지 않았다면 잠그고 true를 반환합니다. 다른 쓰레드에 의해 잠겨 있어, 잠글 수 없다면 false를 반환합니다.
	*/
	bool check(void) __attribute__((optimize("-O1")));
	
	/*
		 현재 잠궈놓은 뮤텍스의 잠금을 해제합니다. 만약 잠그지 않은 뮤텍스를 해제할 경우 의도치 않은 동작을 일으킵니다.
		 잠금과 해제에 대한 쌍의 숫자관리가 중요합니다. 
	*/
	void unlock(void) __attribute__((optimize("-O1")));
	
	/* 
		현재 뮤텍스가 다른 쓰래드의 진입을 막을 때, 함께 막을 인터럽트의 IRQ를 설정합니다. 	
		unlock()을 호출 할 경우, IRQ도 동시에 잠금이 해제됩니다.
		.
		@ irq : 뮤텍스가 같이 잠글 IRQ의 번호를 설정합니다.
	*/
	void setIrq(IRQn_Type irq) __attribute__((optimize("-O1")));

	// 아래 함수는 시스템 함수로 사용자 호출을 금지합니다.
	Mutex(void) __attribute__((optimize("-O1")));

	void initializeMutex(void) __attribute__((optimize("-O1")));

private:
	uint32_t mWaitNum, mCurrentNum;
	IRQn_Type mIrqNum;
	static bool mInit;
};

#endif