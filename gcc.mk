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

TOOLCHAIN = $(TOPDIR)/toolchain/gcc-arm-none-eabi-4_9-2014q4/bin/arm-none-eabi-

CC = $(TOOLCHAIN)gcc
LD = $(TOOLCHAIN)gcc
CP = $(TOOLCHAIN)objcopy

OPTIMIZATION = -Os

CCFLAGS += -c -Wall
CCFLAGS += -mcpu=cortex-m3 -mthumb -mlittle-endian -mlong-calls
CCFLAGS += -ffunction-sections
CCFLAGS += --specs=nano.specs
CCFLAGS += $(OPTIMIZATION)
CCFLAGS += -D$(BOARD)
CCFLAGS += -D$(MCU_SERIES)
CCFLAGS += -D$(MCU_FREQ)

LDFLAGS += -mthumb -Wl,--start-group -Wl,--end-group -Wl,--gc-sections -mcpu=cortex-m3
LDFLAGS += -Wl,-Map=$(PROJECT_NAME).map
LDFLAGS += -T$(LINKER_SCRIPT)
LDFLAGS += $(OPTIMIZATION)

CPFLAGS += -Obinary

OS = $(shell uname)
ifeq ($(OS), Linux)
SIZE = $(shell stat --format='%s' $(PROJECT_NAME).bin)
endif
ifeq ($(OS), Darwin) # MAC OS
SIZE = $(shell stat -f %z $(PROJECT_NAME).bin)
endif

INC  = $(addprefix -I, $(INCLUDE))
OBJS = $(SOURCES:.c=.o)

all: $(PROJECT_NAME)

$(PROJECT_NAME): $(PROJECT_NAME).bin
	@echo "[OUT] $(PROJECT_NAME).bin ($(SIZE) bytes)"

$(PROJECT_NAME).bin: $(PROJECT_NAME).elf
	@$(CP) $(CPFLAGS) $(PROJECT_NAME).elf $@

$(PROJECT_NAME).elf: $(OBJS)
	@$(LD) $(LDFLAGS) -o $@ $(OBJS)

%.o: %.c
	@echo "[GCC]" $@
	@$(CC) $(CCFLAGS) $(INC) $< -o $@

upload:
	bossac -e -w -v -b $(PROJECT_NAME).bin

clean:
	@echo "[CLEAN] *.o *.elf *.bin *.map"
	@rm -rf *.o *.elf *.bin *.map obj/ bin/
	@rm -rf $(OBJS)
