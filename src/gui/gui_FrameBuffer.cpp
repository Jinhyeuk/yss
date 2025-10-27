/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <gui/FrameBuffer.h>
#include <gui/Size.h>
#include <cmsis/cmsis_compiler.h>
#include <config.h>
#include <std_ext/malloc.h>

FrameBuffer::FrameBuffer(void)
{
	mMallocFlag = false;
	mFrameBuffer = nullptr;
	mMaxPoints = 0;
}

FrameBuffer::FrameBuffer::~FrameBuffer(void)
{
	if(mMallocFlag)
#if YSS_L_HEAP_USE
		lfree(mFrameBuffer);
#else
		free(mFrameBuffer);
#endif
}

void FrameBuffer::setSize(Size size)
{
	if(size.getWidth() * size.getHeight() <= mMaxPoints)
		mSize = size;
}

void FrameBuffer::setSize(uint16_t width, uint16_t height)
{
	if(width * height <= mMaxPoints)
		mSize.setSize(width, height);
}

void FrameBuffer::malloc(uint32_t points)
{
	uint32_t size = getPixelCapacity();

	if(mMallocFlag)
#if YSS_L_HEAP_USE
		lfree(mFrameBuffer);
#else
		free(mFrameBuffer);
#endif

	size *= points;
#if YSS_L_HEAP_USE
	mFrameBuffer = (uint8_t*)lmalloc(size);
#else
	mFrameBuffer = (uint8_t*)malloc(size);
#endif

	if(mFrameBuffer != nullptr)
	{
		mMaxPoints = points;
		mMallocFlag = true;
	}
	else
		mMallocFlag = false;
}

uint8_t* FrameBuffer::getFrameBuffer(void)
{
	return mFrameBuffer;
}

