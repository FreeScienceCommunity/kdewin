/*
   This file is part of the KDE libraries
   Copyright (C) 2003-2004 Jarosław Staniek <staniek@kde.org>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License version 2 as published by the Free Software Foundation.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
*/

#ifndef NO_KDEWIN
#ifndef KDEWIN_STRINGS_H
#define KDEWIN_STRINGS_H

// include everywhere
#include <sys/types.h>

// str(n)casecmp is sometimes defined in string.h and sometimes strings.h ...
#include <string.h>

void bzero(void *s, size_t n)
{
	memset(s,0,n);
}


#endif KDEWIN_STRINGS_H
#endif /* NO_KDEWIN */