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

INCLUDE += $(TOPDIR)/thirdparty/FreeRTOS/Source/include
INCLUDE += $(TOPDIR)/thirdparty/FreeRTOS/Source/portable/GCC/ARM_CM3

SOURCES += $(TOPDIR)/thirdparty/FreeRTOS/Source/croutine.c
SOURCES += $(TOPDIR)/thirdparty/FreeRTOS/Source/event_groups.c
SOURCES += $(TOPDIR)/thirdparty/FreeRTOS/Source/list.c
SOURCES += $(TOPDIR)/thirdparty/FreeRTOS/Source/queue.c
SOURCES += $(TOPDIR)/thirdparty/FreeRTOS/Source/tasks.c
SOURCES += $(TOPDIR)/thirdparty/FreeRTOS/Source/timers.c
SOURCES += $(TOPDIR)/thirdparty/FreeRTOS/Source/portable/MemMang/heap_1.c
SOURCES += $(TOPDIR)/thirdparty/FreeRTOS/Source/portable/GCC/ARM_CM3/port.c
