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

LINUX = "https://launchpad.net/gcc-arm-embedded/4.9/4.9-2014-q4-major/+download/gcc-arm-none-eabi-4_9-2014q4-20141203-linux.tar.bz2"

MACOS = "https://launchpad.net/gcc-arm-embedded/4.9/4.9-2014-q4-major/+download/gcc-arm-none-eabi-4_9-2014q4-20141203-mac.tar.bz2"

OS = $(shell uname)

ifeq ($(OS), Linux)
URL = $(LINUX)
endif
ifeq ($(OS), Darwin) # MAC OS
URL = $(MACOS)
endif

all: install

install:
	curl -L -O $(URL)
	tar vxjf *.tar.bz2
	rm -rf *.tar.bz2

clean:
	@echo "[Clean]"
	@rm -rf */
