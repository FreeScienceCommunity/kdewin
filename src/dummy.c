/*
   This file is part of the KDE libraries
   Copyright (C) 2008 Jaroslaw Staniek <staniek@kde.org>

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

#include <kdewin_export.h>
#include "dirent.h"

/* TODO implement if possible in dirent.c */
KDEWIN_EXPORT struct dirent* readdir_r(DIR *dirp, struct dirent *entry, struct dirent **result)
{
	result = 0;
	return 0;
}

/* TODO implement if possible in fcntl.c */
KDEWIN_EXPORT int fcntl(int fd, int cmd,...)
{
	/*! @todo */
	return -1;
}
