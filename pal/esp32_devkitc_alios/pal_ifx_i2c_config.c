/**
* \copyright
* MIT License
*
* Copyright (c) 2020 Infineon Technologies AG
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE
*
* \endcopyright
*
* \author Infineon Technologies AG
*
* \file pal_ifx_i2c_config.c
*
* \brief   This file implements platform abstraction layer configurations for ifx i2c protocol.
*
* \ingroup  grPAL
*
* @{
*/

#include "optiga/pal/pal_gpio.h"
#include "optiga/pal/pal_i2c.h"
#include "optiga/ifx_i2c/ifx_i2c_config.h"
#include <aos/hal/gpio.h>
#include "aos/hal/i2c.h"
#include "aos/kernel.h"

extern gpio_dev_t gpio_reset;
extern gpio_dev_t gpio_vdd;

i2c_dev_t i2c_0 = {
    .port                 = 0,
    .config.address_width = I2C_HAL_ADDRESS_WIDTH_7BIT,
    .config.freq          = I2C_BUS_BIT_RATES_400K,
    .config.mode          = I2C_MODE_MASTER,
    .config.dev_addr      = 0x30 << 1
};

/**
 * \brief PAL I2C configuration for OPTIGA. 
 */
pal_i2c_t optiga_pal_i2c_context_0 =
{
    /// Pointer to I2C master platform specific context
    &i2c_0,
    /// Slave address
    0x30,
    /// Upper layer context
    NULL,
    /// Callback event handler
    NULL
};

/**
* \brief PAL vdd pin configuration for OPTIGA. 
 */
pal_gpio_t optiga_vdd_0 =
{
    // Platform specific GPIO context for the pin used to toggle Vdd.
	(void*)&gpio_vdd
};

/**
 * \brief PAL reset pin configuration for OPTIGA.
 */
pal_gpio_t optiga_reset_0 =
{
    // Platform specific GPIO context for the pin used to toggle Reset.
    (void*)&gpio_reset
};

/**
* @}
*/
