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

#include "console.h"
#include "board.h"

#include <string.h>

#include "pio.h"
#include "pmc.h"
#include "usart.h"

int console_init(void)
{
  // Enable the UART peripheral clock in the PMC.
  PMC_EnablePeripheral(CONSOLE_USART_ID);

  // Enable the required UART PIOs.
  PIO_Configure(&console, 1);

  // Initialize USART
  USART_Configure(CONSOLE_USART, USART_MODE_ASYNCHRONOUS,
                  CONSOLE_USART_BAUDRATE, BOARD_FREQ);

  // Enable TX & RX
  USART_SetTransmitterEnabled(CONSOLE_USART, 1);
  USART_SetReceiverEnabled(CONSOLE_USART, 1);

  return 0;
}

int console_putchar(int c)
{
  if (c == '\n') {
    USART_PutChar(CONSOLE_USART, '\r');
  }
  USART_PutChar(CONSOLE_USART, c);

  return 0;
}

void console_putstring(const char *s)
{
  int n = strlen(s);

  while(n) {
    console_putchar(*s++);
    n--;
  }
}
