/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_MOD_AUDIO_CS43L22__H_
#define YSS_MOD_AUDIO_CS43L22__H_

#include <yss/instance.h>

#if !defined(YSS_DRV_I2C_UNSUPPORTED) || !defined(YSS_DRV_I2S_UNSUPPORTED)

/*
	Audio용 DAC IC인 CS43L22의 드라이버 입니다.
	이 칩의 제조사는 Cirrus Logic입니다.
	I2S와 I2C 장치가 먼저 초기화가 완료된 상태에서 이 IC의 초기화를 진행하면 I2S에 설정된 값을 참조하여 DAC의 설정을 진행합니다.
*/
class CS43L22
{
public:
	typedef enum
	{
		AD0_LOW = 0x94,
		AD0_HIGH = 0x96
	}ad0_t;

	typedef enum
	{
		MODE_MAIN = 0,
		MODE_SUB
	}mode_t;

	typedef struct 
	{
		I2c &i2c;
		I2s &i2s;
		pin_t resetPin;
		ad0_t ad0;
	}config_t;

	CS43L22(void);
	
	/*
		DAC IC를 config_t에 설정된 값으로 초기화 합니다.
		이 IC를 초기화 하기 전에 먼저 I2S와 I2C의 초기화가 완료되야 합니다.
		.
		@ return : 발생한 error를 반환합니다.
		.
		@ &config : 필요한 IC의 설정을 지정합니다.
	*/
	error_t initialize(config_t config);

private :
	I2c *mI2c;
	I2s *mI2s;
	pin_t mResetPin;
	uint8_t mAddr;
	uint16_t mOutputValue[4];
};

/*
	// 아래는 설정의 예입니다.
	// CS43L22 초기화
	gpioD.setAsOutput(4);
	
	CS43L22::config_t dacConfig = 
	{
		i2c1,				//I2c &i2c;
		i2s3,				//I2s &i2s;
		{&gpioD, 4},		//pin_t resetPin;
		CS43L22::AD0_LOW	//ad0_t ad0;
	};
	
	dac.initialize(dacConfig);
*/

#endif

#endif
