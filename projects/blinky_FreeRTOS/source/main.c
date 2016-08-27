/* Blinky LED example using FreeRTOS.
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

#include "trace.h"
#include "board.h"

#include "FreeRTOS.h"
#include "task.h"

#include "pio.h"
#include "pmc.h"

void blinkyTask (void *pvParameters)
{
  // Configure LED
  PMC_EnablePeripheral(ID_PIOA);
  PIO_Configure(&led, 1);

  for(;;)
  {
    PIO_Set(&led);
    TRACE_DEBUG("LED ON\n");
    vTaskDelay(1000);
    PIO_Clear(&led);
    TRACE_DEBUG("LED OFF\n");
    vTaskDelay(1000);
  }
}

int main(void)
{
  // Initialize board
  board_init();

  TRACE_INFO("Blinky_FreeRTOS\n");
  TRACE_INFO("Compiled on %s at %s\n", __DATE__, __TIME__);

  xTaskCreate(blinkyTask, "BLK", 0x100, NULL, tskIDLE_PRIORITY, NULL);
  vTaskStartScheduler();

  for(;;) ;
}
