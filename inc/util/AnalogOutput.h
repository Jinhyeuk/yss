/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef	YSS_UTIL_ANALOG_OUTPUT__H_
#define	YSS_UTIL_ANALOG_OUTPUT__H_

#include <stdint.h>

class AnalogOutput
{
	float mDacMax, mRef, mErrorP1, mErrorP2, mValueP1, mValueP2, mReferenceDacP1, mReferenceDacP2, mReferenceOffset, mErrorOffset;
public:
	AnalogOutput(void);

	void setup(uint8_t dacBit, float referenceValueP1, float referenceValueP2, float minValue, float maxValue);
	
	void setErrorP1(float val);

	void setErrorP2(float val);

	uint32_t getReferenceDacP1(void);

	uint32_t getReferenceDacP2(void);

	float calculate(float value);

private :
	void update(void);
};

#endif