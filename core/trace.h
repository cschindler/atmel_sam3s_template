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

#define TRACE_LEVEL_DEBUG     4
#define TRACE_LEVEL_INFO      3
#define TRACE_LEVEL_WARNING   2
#define TRACE_LEVEL_ERROR     1
#define TRACE_LEVEL_NO_TRACE  0

#ifndef TRACE_LEVEL
#define TRACE_LEVEL TRACE_LEVEL_DEBUG
#endif // TRACE_LEVEL

#ifdef NO_TRACE
#define TRACE_DEBUG(...)    ()
#define TRACE_INFO(...)     ()
#define TRACE_WARNING(...)  ()
#define TRACE_ERROR(...)    ()
#define TRACE(...)          ()
#else // NO_TRACE

#ifdef NO_TRACE_COLOR
#define ANSI_RED     ""
#define ANSI_GREEN   ""
#define ANSI_YELLOW  ""
#define ANSI_RESET   ""
#else // NO_TRACE_COLOR
#define ANSI_RED     "\x1b[31;1m"
#define ANSI_GREEN   "\x1b[32;1m"
#define ANSI_YELLOW  "\x1b[33;1m"
#define ANSI_RESET   "\x1b[0m"
#endif

#if (TRACE_LEVEL >= TRACE_LEVEL_DEBUG)
#define TRACE_DEBUG(...)  _printf("[DEBUG] (%s:%d) ", __FILE__, __LINE__); _printf(__VA_ARGS__);
#else
#define TRACE_DEBUG(...)  ()
#endif

#if (TRACE_LEVEL >= TRACE_LEVEL_INFO)
#define TRACE_INFO(...)  _printf(ANSI_GREEN "[INFO] " ANSI_RESET __VA_ARGS__);
#else
#define TRACE_INFO(...)  ()
#endif

#if (TRACE_LEVEL >= TRACE_LEVEL_WARNING)
#define TRACE_WARNING(...)  _printf(ANSI_YELLOW "[WARNING] " ANSI_RESET __VA_ARGS__);
#else
#define TRACE_WARNING(...)  ()
#endif

#if (TRACE_LEVEL >= TRACE_LEVEL_ERROR)
#define TRACE(...)        _printf(__VA_ARGS__);
#define TRACE_ERROR(...)  _printf(ANSI_RED "[ERROR] " ANSI_RESET __VA_ARGS__);
#else
#define TRACE(...)        ()
#define TRACE_ERROR(...)  ()
#endif

#endif // NO_TRACE

#endif // __TRACE_H__
