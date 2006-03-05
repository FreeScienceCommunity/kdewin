/* This file is part of the KDE project

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

#ifndef KDEWIN_ARPA_INET_H
#define KDEWIN_ARPA_INET_H

// include everywhere
#include <sys/types.h>

#include <netinet/in.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef unsigned int in_addr_t;

KDEWIN32_EXPORT const char *inet_ntop(int af, const void * src, char * dst, size_t size);
KDEWIN32_EXPORT int inet_pton(int af, const char * src, void * dst);
KDEWIN32_EXPORT int inet_aton(const char *src, struct in_addr *addr);

// FIXME - move to sys/errno.h
#ifndef EAFNOSUPPORT
#define EAFNOSUPPORT 106
#endif

#ifdef __cplusplus
};
#endif

#endif // KDEWIN_ARPA_INET_H
