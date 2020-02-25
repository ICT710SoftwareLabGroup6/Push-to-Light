/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#include "mbed.h"


int main()
{
    // Initialise the digital pin LED1 as an output
    DigitalOut led(LED1);
    DigitalIn btn(PC_13);

    while (true) {
        led = !btn;
        
    }
}
