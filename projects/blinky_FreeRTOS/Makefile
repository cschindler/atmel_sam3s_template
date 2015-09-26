# Written by Christopher Schindler
# Copyright (C) 2015 Christopher Schindler
#
# This library is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the Free
# Software Foundation, either version 3 of the License, or (at your option)
# any later version.
#
# This library is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
# or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
# for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program. If not, see <http://www.gnu.org/licenses/>.

TOPDIR = ../..
PROJECT_DIR = $(TOPDIR)/projects/blinky_FreeRTOS

GCC_DIR = $(TOPDIR)/gcc.mk
SAM3S_DIR = $(TOPDIR)/sam3s/sam3s.mk
BOARD_DIR = $(TOPDIR)/board/board.mk
FREERTOS_DIR = $(TOPDIR)/thirdparty/FreeRTOS.mk

# Project name
PROJECT_NAME = blinky_FreeRTOS

# MCU device
MCU_DEVICE = SAM3S4B
MCU_FREQ = MAIN_OSCILLATOR_64MHZ
# Board
BOARD = BOARD_OLIMEX_H256

# Project sources
INCLUDE += $(PROJECT_DIR)/include
SOURCES += $(PROJECT_DIR)/source/main.c

include $(SAM3S_DIR) $(BOARD_DIR) $(FREERTOS_DIR) $(GCC_DIR)
