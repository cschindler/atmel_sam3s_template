# Getting started with Atmel SAMS3S

## Overview

This is a template for getting started with Atmel SAM3S ARM Cortex-M3.
It includes all you need to compile a basic blinky example.

## Setup of the toolchain (Linux and Mac OS)

First step, you must setup the pre-build toolchain for ARM Cortex-M.

	cd toolchain/
	make install

For Linux 64-bit machine, you should first install the following 32-bit libraries:

	sudo apt-get install lib32z1 lib32ncurses5 lib32bz2-1.0

## Build the blinky example

Now, you are ready to compile the simple blinky example.

	cd projects/blinky/
	make all

Or the blinky example using FreeRTOS.

	cd projects/blinky_FreeRTOS
	make all

## Upload binary (using BOSSA)

	make upload

## Documentation

Atmel SAM3S datasheet: http://www.atmel.com/Images/Atmel-6500-32-bit-Cortex-M3-Microcontroller-SAM3S4-SAM3S2-SAM3S1_Datasheet.pdf

Atmel SAM3S Getting Started: http://www.atmel.com/Images/Atmel-42152-Getting-Started-With-SAM3S-Microcontrollers_Application-Note_AT03499.pdf

GCC compiler for ARM Cortex: https://launchpad.net/gcc-arm-embedded

FreeRTOS: http://www.freertos.org/

BOSSA:
http://www.shumatech.com/web/products/bossa
https://github.com/shumatech/BOSSA

Olimex SAM3-H256 board:
https://www.olimex.com/Products/ARM/Atmel/SAM3-H256/

## Author

* Christopher Schindler
