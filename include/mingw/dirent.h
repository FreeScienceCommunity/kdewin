/* This file is part of the KDE project
   Copyright (C) 2006 Peter K�mmel

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

#ifndef KDEWIN_SYS_DIRENT_H
#define KDEWIN_SYS_DIRENT_H

// include everywhere
#include <sys/types.h>

#include <../include/dirent.h>

#ifdef __cplusplus
extern "C" {
#endif

// Implement readdir_r(). For now do not provide dummy function to avoid setting HAVE_READDIR_R.
// Code like DirectoryListThread::run() in kio/kio/kurlcompletion.cpp uses readdir() when !HAVE_READDIR_R.

// KDEWIN32_EXPORT struct dirent* readdir_r(DIR *dirp, struct dirent *entry, struct dirent **result);

#ifdef __cplusplus
}
#endif

#endif  // KDEWIN_SYS_DIRENT_H
