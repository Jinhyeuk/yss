/*
 * Copyright (c) 2015 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#ifndef YSS_GUI_FRAME_BUFFER__H_
#define YSS_GUI_FRAME_BUFFER__H_

#include <stdint.h>
#include "Size.h"

class FrameBuffer
{
public:
	FrameBuffer(void);

	virtual ~FrameBuffer(void);

	virtual uint8_t getPixelCapacity(void) = 0;

	void setSize(Size size);

	void setSize(uint16_t width, uint16_t height);

	void malloc(uint32_t points);

	uint8_t* getFrameBuffer(void);
	
protected:
	uint8_t *mFrameBuffer;
	bool mMallocFlag;
	Size mSize;
	uint32_t mMaxPoints;
};

#endif

