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

#ifndef __TRACE_H__
#define __TRACE_H__

#include "printf.h"

#define TRACE_LEVEL_DEBUG     5
#define TRACE_LEVEL_INFO      4
#define TRACE_LEVEL_WARNING   3
#define TRACE_LEVEL_ERROR     2
#define TRACE_LEVEL_FATAL     1
#define TRACE_LEVEL_NO_TRACE  0

#ifndef TRACE_LEVEL
#define TRACE_LEVEL TRACE_LEVEL_DEBUG
#endif // TRACE_LEVEL

#ifdef NO_TRACE
#define TRACE_DEBUG(...)    ()
#define TRACE_INFO(...)     ()
#define TRACE_WARNING(...)  ()
#define TRACE_ERROR(...)    ()
#define TRACE_FATAL(...)    ()
#else // NO_TRACE

#if (TRACE_LEVEL >= TRACE_LEVEL_DEBUG)
#define TRACE_DEBUG(...)  _printf("[DEBUG] " __VA_ARGS__)
#else
#define TRACE_DEBUG(...)  ()
#endif

#if (TRACE_LEVEL >= TRACE_LEVEL_INFO)
#define TRACE_INFO(...)  _printf("[INFO] " __VA_ARGS__)
#else
#define TRACE_INFO(...)  ()
#endif

#if (TRACE_LEVEL >= TRACE_LEVEL_WARNING)
#define TRACE_WARNING(...)  _printf("[WARNING] " __VA_ARGS__)
#else
#define TRACE_WARNING(...)  ()
#endif

#if (TRACE_LEVEL >= TRACE_LEVEL_ERROR)
#define TRACE_ERROR(...)  _printf("[ERROR] " __VA_ARGS__)
#else
#define TRACE_ERROR(...)  ()
#endif

#if (TRACE_LEVEL >= TRACE_LEVEL_FATAL)
#define TRACE_FATAL(...)  _printf("[FATAL] " __VA_ARGS__)
#else
#define TRACE_FATAL(...)  ()
#endif

#endif // NO_TRACE

#endif // __TRACE_H__
