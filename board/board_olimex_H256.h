/*
* Written by Christopher Schindler
* Copyright (C) 2015 Christopher Schindler
*
* This library is free software: you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the Free
* Software Foundation, either version 3 of the License, or (at your option)
* any later version.
*
* This library is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
* or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
* for more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __BOARD_OLIMEX_H256_H__
#define __BOARD_OLIMEX_H256_H__

#include "pio.h"
#include "usart.h"

// CONSOLE
#define CONSOLE_USART           USART0
#define CONSOLE_USART_ID        ID_USART0
#define CONSOLE_USART_BAUDRATE  115200

#define PIN_CONSOLE_USART       {PIO_PA5A_RXD0|PIO_PA6A_TXD0, PIOA, ID_PIOA, \
                                 PIO_PERIPH_A, PIO_DEFAULT}
extern const Pin console;

// LED
#define PIN_LED                 {PIO_PA8, PIOA, ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}
extern const Pin led;

#endif // __BOARD_OLIMEX_H256_H__
