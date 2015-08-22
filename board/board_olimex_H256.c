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

#include "board_olimex_H256.h"

#include "console.h"
#include "wdt.h"

// Console
const Pin console = PIN_CONSOLE_USART;
// LED
const Pin led = PIN_LED;

int board_init(void)
{
  // Disable watchdog
  WDT_Disable(WDT);
  // Initialize console
  console_init();

  return 0;
}
