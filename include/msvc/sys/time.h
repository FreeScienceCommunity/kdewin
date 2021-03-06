/* This file is part of the KDE project
   Copyright (C) 2003-2004 Jarosław Staniek <staniek@kde.org>

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this program; see the file COPYING.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#ifndef NO_KDEWIN
#ifndef KDEWIN_SYS_TIME_H
#define KDEWIN_SYS_TIME_H

// include everywhere
#include <sys/types.h>

#include <winsock2.h>
#include "fixwinh.h"

struct itimerval {
	struct timeval it_interval; /**< reset value*/
	struct timeval it_value;    /**< current value*/
};

#ifdef __cplusplus
extern "C" {
#endif

#ifndef WIN32_WCE // function is contained in wcecompat
KDEWIN_EXPORT int gettimeofday(struct timeval *__p, void *__t);
#endif

//errno==EACCES on read-only devices
KDEWIN_EXPORT int utimes(const char *filename, const struct timeval times[2]);

// this is no posix function
//KDEWIN_EXPORT int settimeofday(const struct timeval *, const struct timezone *); 

#if _MSC_VER >= 1900
#define tzname _tzname
#define tzset _tzset
#endif

/* Convenience macros for operations on timevals.
   NOTE: `timercmp' does not work for >= or <=.
*/
#ifndef timerisset
# define timerisset(tvp)        ((tvp)->tv_sec || (tvp)->tv_usec)
#endif

#ifndef timerclear
# define timerclear(tvp)        ((tvp)->tv_sec = (tvp)->tv_usec = 0)
#endif

#ifndef timercmp
# define timercmp(a, b, CMP)                                                  \
  (((a)->tv_sec == (b)->tv_sec) ?                                             \
   ((a)->tv_usec CMP (b)->tv_usec) :                                          \
   ((a)->tv_sec CMP (b)->tv_sec))
#endif

#ifndef timeradd
# define timeradd(a, b, result)                                               \
  do {                                                                        \
    (result)->tv_sec = (a)->tv_sec + (b)->tv_sec;                             \
    (result)->tv_usec = (a)->tv_usec + (b)->tv_usec;                          \
    if ((result)->tv_usec >= 1000000)                                         \
      {                                                                       \
        ++(result)->tv_sec;                                                   \
        (result)->tv_usec -= 1000000;                                         \
      }                                                                       \
  } while (0)
#endif

#ifndef timersub
# define timersub(a, b, result)                                               \
  do {                                                                        \
    (result)->tv_sec = (a)->tv_sec - (b)->tv_sec;                             \
    (result)->tv_usec = (a)->tv_usec - (b)->tv_usec;                          \
    if ((result)->tv_usec < 0) {                                              \
      --(result)->tv_sec;                                                     \
      (result)->tv_usec += 1000000;                                           \
    }                                                                         \
  } while (0)
#endif

#ifdef __cplusplus
}
#endif

#endif // KDEWIN_SYS_TIME_H
#endif /* NO_KDEWIN */