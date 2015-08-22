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

ifeq ($(MCU_DEVICE), SAM3S1A)
MCU_SERIES = sam3s1
else ifeq ($(MCU_DEVICE), SAM3S1B)
MCU_SERIES = sam3s1
else ifeq ($(MCU_DEVICE), SAM3S1C)
MCU_SERIES = sam3s1
else ifeq ($(MCU_DEVICE), SAM3S2A)
MCU_SERIES = sam3s2
else ifeq ($(MCU_DEVICE), SAM3S2B)
MCU_SERIES = sam3s2
else ifeq ($(MCU_DEVICE), SAM3S2C)
MCU_SERIES = sam3s2
else ifeq ($(MCU_DEVICE), SAM3S4A)
MCU_SERIES = sam3s4
else ifeq ($(MCU_DEVICE), SAM3S4B)
MCU_SERIES = sam3s4
else ifeq ($(MCU_DEVICE), SAM3S4C)
MCU_SERIES = sam3s4
else
$(error MCU not supported)
endif

# Linker script
LINKER_SCRIPT = $(TOPDIR)/Atmel/sam3s/linker_scripts/gcc/$(MCU_SERIES)/flash.ld

# Bootstrap
INCLUDE += $(TOPDIR)/Atmel/sam3s
INCLUDE += $(TOPDIR)/Atmel/sam3s/cmsis
SOURCES += $(TOPDIR)/Atmel/sam3s/startup.c
SOURCES += $(TOPDIR)/Atmel/sam3s/lowlevel.c
SOURCES += $(TOPDIR)/Atmel/sam3s/exceptions.c

# Atmel drivers
INCLUDE += $(TOPDIR)/Atmel/sam3s/drivers/include
SOURCES += $(TOPDIR)/Atmel/sam3s/drivers/source/pio.c
SOURCES += $(TOPDIR)/Atmel/sam3s/drivers/source/pmc.c
SOURCES += $(TOPDIR)/Atmel/sam3s/drivers/source/wdt.c
SOURCES += $(TOPDIR)/Atmel/sam3s/drivers/source/usart.c

# Core
INCLUDE += $(TOPDIR)/core
SOURCES += $(TOPDIR)/core/printf-stdarg.c
SOURCES += $(TOPDIR)/sam3s/console_usart.c
