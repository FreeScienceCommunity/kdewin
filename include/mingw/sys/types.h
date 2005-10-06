/* This file is part of the KDE project
   Copyright (C) 2005 Ralf Habacker <ralf.habacker@freenet.de>

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

#ifndef KDE_SYS_TYPES_H_
#define KDE_SYS_TYPES_H_

#include_next <sys/types.h>

typedef unsigned int uid_t;
typedef	unsigned int gid_t;
typedef int caddr_t;

#ifndef KDEWIN32_EXPORT
#define KDEWIN32_EXPORT
#endif 

#endif 

