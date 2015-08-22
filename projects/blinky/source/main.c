/* Blinky LED example.
*
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

#include <stdint.h>
#include "trace.h"
#include "board.h"

#include "SAM3S.h"
#include "pio.h"
#include "pmc.h"

volatile uint32_t msTicks = 0;

void SysTick_Handler(void) {
  msTicks++;
}

void delay_ms(uint32_t ms) {
  uint32_t now = msTicks;
  while ((msTicks-now) < ms){}
}

int main(void)
{
  // Initialize board
  board_init();

  // Configure System Tick
  SysTick_Config(BOARD_FREQ / 1000); //1ms per interrupt

  // Configure LED
  PMC_EnablePeripheral(ID_PIOA);
  PIO_Configure(&led, 1);

  TRACE_INFO("Compiled on %s at %s\n", __DATE__, __TIME__);

  while(1)
  {
    PIO_Set(&led);
    TRACE_DEBUG("LED ON\n");
    delay_ms(1000);
    PIO_Clear(&led);
    TRACE_DEBUG("LED OFF\n");
    delay_ms(1000);
  }
}
