/* This file is part of the KDE project
   Copyright (C) 2006 Ralf Habacker

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

#ifndef KDEWIN_BASETYPS_H
#define KDEWIN_BASETYPS_H

/* W32API */ 

/* (rh) w32api basetyps.h defines interface to struct, which is very annoying 
   because interface couldn't be used as method name or parameter. To avoid this
   the name interface is mapped to w32api_interface in every w32api system header 
   but elsewhere undefined.  
*/ 
#define w32api_interface struct
#define interface w32api_interface
#include <../include/basetyps.h>
#undef interface

#endif
