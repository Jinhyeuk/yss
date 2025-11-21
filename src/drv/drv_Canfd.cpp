/*
 * Copyright (c) 2025 Yoon-Ki Hong
 *
 * This file is subject to the terms and conditions of the MIT License.
 * See the file "LICENSE" in the main directory of this archive for more details.
 */

#include <drv/CanFd.h>

const uint8_t CanFd::mDlcTable[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 12, 16, 20, 24, 32, 48, 64};

CanFd::CanFd(const Drv::setup_t drvSetup) : Can(drvSetup)
{

}

