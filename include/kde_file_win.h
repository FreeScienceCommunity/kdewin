/*
   This file is part of the KDE libraries
   Copyright (C) 2004 Jarosław Staniek <staniek@kde.org>

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

#ifndef KDE_FILE_WIN_H
#define KDE_FILE_WIN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include <ctype.h>

#include <kdewin_export.h> 

#ifdef __cplusplus
extern "C" {
#endif

/**
 Works like ::stat() but also:
  1) if @path is like "C:", '\' is appended
  2) else, '/' or '\' trailing characters are removed from @file_name
 */
KDEWIN_EXPORT int kdewin32_stat(const char *file_name, struct stat *buf);

#ifdef _MSC_VER
/**
 Like kdewin32_stat() but fills a wider struct, useful for filesizes > 2 GB
 use only when _MSC_VER is defined.
 */
KDEWIN_EXPORT int kdewin32_stat64(const char *file_name, struct _stat64 *buf);
#endif

/**
 Identical to kdewin32_stat()
 */
KDEWIN_EXPORT int kdewin32_lstat(const char *file_name, struct stat *buf);

/**
 Works like ::open() but also:
  - if @flags have not specified O_TEXT flag, O_BINARY flag is appended
    (because on win32 O_TEXT mode is the default, not O_BINARY like on unix)
 */
KDEWIN_EXPORT int kdewin32_open(const char *path, int flags, ... /*mode_t mode*/);

/*KDEWIN_EXPORT int kdewin32_open(const char *path, int flags);*/

/**
 Works like ::fopen() but also:
  - if @mode have specified neither "t" (text flag) or "b" (binary flag), 
    "b" (binary) flag is appended (or inserted before '+' character)
    (because on win32 text mode is the default, not binary like on unix)
 */
KDEWIN_EXPORT FILE *kdewin32_fopen(const char *path, const char *mode);

KDEWIN_EXPORT FILE *kdewin32_fdopen(int fd, const char *mode);

KDEWIN_EXPORT FILE *kdewin32_freopen(const char *path, const char *mode, FILE *stream);

/**
 Before calling ::rename(), tries to remove() it, is needed, 
 because win32 semantics doesn't allow files overwriting using ::rename().
*/
KDEWIN_EXPORT int kdewin32_rename(const char *src, const char *dest);

/**
 A wrapped for ::mkdir() used by KDE_mkdir().
*/
KDEWIN_EXPORT int kdewin32_mkdir(const char *path, mode_t mode);

#ifdef __cplusplus
}
#endif

#endif //KDE_FILE_WIN_H
