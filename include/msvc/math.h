/*
   This file is part of the KDE libraries
   Copyright (C) 2005-2007 Christian Ehrlicher <Ch.Ehrlicher@gmx.de>
   Copyright (C) 2007 Jarosław Staniek <staniek@kde.org>

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

#if defined(_WIN32_WCE) || defined(_WIN64)
#define DONT_USE_ASM
#endif

#ifndef NO_KDEWIN
#ifndef _MSC_VER
# error This header is for msvc only!
#endif

// include everywhere
#include <sys/types.h>

#ifndef _USE_MATH_DEFINES
# define _USE_MATH_DEFINES
#endif
#endif /* NO_KDEWIN */

/* regular header from msvc includes */
#ifndef _WIN32_WCE
#if _MSC_VER >= 1900
#include <../ucrt/math.h>
#include <../ucrt/float.h>
#else
#include <../include/math.h>
#include <../include/float.h>
#endif
#else
#include <../wcecompat/math.h>
#include <../wcecompat/float.h>
#endif

#ifndef NO_KDEWIN
#ifndef KDEWIN_MATH_H
#define KDEWIN_MATH_H

#include <kdewin_export.h>

#include <errno.h>
#include <limits.h>

#ifdef __cplusplus
extern "C" {
#endif

// some definitions
extern KDEWIN_EXPORT float __INFF;
#ifndef HUGE_VALF
#define HUGE_VALF __INFF
#endif
extern KDEWIN_EXPORT long double  __INFL;
#ifndef HUGE_VALL
#define HUGE_VALL __INFL
#endif
#ifndef INFINITY
#define INFINITY HUGE_VALF
#endif
extern KDEWIN_EXPORT double __QNAN;
#ifndef NAN
#define NAN __QNAN
#endif

#if _MSC_VER < 1800
KDEWIN_EXPORT __inline int isnan(double num) { return _isnan(num); }
KDEWIN_EXPORT __inline int isinf(double num) { return !_finite(num) && !_isnan(num); }
KDEWIN_EXPORT __inline int finite(double num) { return _finite(num); }
KDEWIN_EXPORT __inline int signbit(double num) { return _copysign(1.0, num) < 0; }

KDEWIN_EXPORT double remainder(double x, double y);
#endif

// some functions which aren't available with msvc

/* 7.12.4 Trigonometric functions: Double in C89 */
// float sinf (float)
// double sinf (double)
// long double sinl (long double)

// float cosf (float)
// double cosf (double)
// long double cosl (long double)

// float tanf (float)
// double tanf (double)
// long double tanl (long double)

/* 7.12.5.1 */
// double acosh (double)
// float acoshf (float)
// long double acoshl (long double)

/* 7.12.5.2 */
// double asinh (double)
// float asinhf (float)
// long double asinhl (long double)

/* 7.12.5.3 */
// double atanh (double)
// float atanf (float)
// long double atanhl (long double)

/* Exponentials and logarithms  */
/* 7.12.6.1 Double in C89 */
// float expf (float)
// double expf (double)
// long double expl (long double)

/* 7.12.6.3 The expm1 functions */
// double expm1 (double)
// float expm1f (float)
// long double expm1l (long double)

/* 7.12.6.7 */
// float logf (float)
// double logf (double)
// long double logl (long double)

/* 7.12.6.8 */
// float log10f (float)
// double log10l (double)
// long double log10l (long double)

/* 7.12.6.9 */
// double log1p(double)
// float log1pf(float)
// long double log1pl(long double)

/* 7.12.8.1 The erf functions  */
// double erf (double)
// float erff (float)
// long double erfl (long double)

/* 7.12.8.2 The erfc functions  */
// double erfc (double)
// float erfcf (float)
// long double erfcl (long double)

/* 7.12.8.3 The lgamma functions */
// double lgamma (double)
// float lgammaf (float)
// long double lgammal (long double)

/* 7.12.8.4 The tgamma functions */
// double tgamma (double)
// float tgammaf (float)
// long double tgammal (long double)

/* 7.12.9.1 */
// float ceilf (float)
// double ceilf (double)
// long double ceill (long double)

/* 7.12.9.2 */
// float floorf (float)
// double floor (double)
// long double floorl (long double)

/* 7.12.9.3 */
// float nearbyintf(float)
// double nearbyint(double)
// long double nearbyintl(long double)

/* 7.12.9.4 */
// float rintf (float)
// double rint (double)
// long double rintl (long double)

/* 7.12.9.6 */
// float roundf (float)
// double round (double)
// long double roundl (long double)

/* 7.12.9.7 */
// long lroundf (float)
// long lround (double)
// long lroundl (long double)

/* 7.12.9.8 */
// float truncf(float)
// double trunc(double)
// long double truncl(long double)

/* 7.12.12.2 */
// double fmax (double, double)
// float fmaxf (float, float)
// long double fmaxl (long double, long double)

/* 7.12.12.3 */
// double fmin (double, double)
// float fminf (float, float)
// long double fminl (long double, long double)

#if _MSC_VER < 1800
/* 7.12.5.1 */
KDEWIN_EXPORT float acoshf (float);
KDEWIN_EXPORT double acosh (double);
KDEWIN_EXPORT long double acoshl (long double);

/* 7.12.5.2 */
KDEWIN_EXPORT float asinhf (float);
KDEWIN_EXPORT double asinh (double);
KDEWIN_EXPORT long double asinhl (long double);

/* 7.12.5.3 */
KDEWIN_EXPORT float atanhf (float);
KDEWIN_EXPORT double atanh (double);
KDEWIN_EXPORT long double atanhl (long double);

/* 7.12.6.3 The expm1 functions */
KDEWIN_EXPORT double expm1(double);
KDEWIN_EXPORT float expm1f(float);
KDEWIN_EXPORT long double expm1l(long double);

/* 7.12.6.9 */
KDEWIN_EXPORT double log1p(double);
KDEWIN_EXPORT float log1pf(float);
KDEWIN_EXPORT long double log1pl(long double);

/* 7.12.8.1 The erf functions  */
KDEWIN_EXPORT double erf (double);
KDEWIN_EXPORT float erff (float);
KDEWIN_EXPORT long double erfl (long double);

/* 7.12.8.2 The erfc functions  */
KDEWIN_EXPORT double erfc (double);
KDEWIN_EXPORT float erfcf (float);
KDEWIN_EXPORT long double erfcl (long double);

/* 7.12.8.3 The lgamma functions */
KDEWIN_EXPORT float lgammaf (float);
KDEWIN_EXPORT double lgamma (double);
KDEWIN_EXPORT long double lgammal (long double);

/* 7.12.8.4 The tgamma functions */
KDEWIN_EXPORT float tgammaf (float);
KDEWIN_EXPORT double tgamma (double);
KDEWIN_EXPORT long double tgammal (long double);
#endif

#if !defined __cplusplus && defined _MSC_VER && _MSC_VER < 1400
/* 7.12.6.1 */
KDEWIN_EXPORT __inline float expf(float x) {return ((float)exp((double)x)); }
/* 7.12.9.1 */
KDEWIN_EXPORT __inline float floorf(float x) {return ((float)floor((double)x)); }
KDEWIN_EXPORT __inline float ceilf(float x) {return ((float)ceil((double)x)); }
KDEWIN_EXPORT __inline float sinf(float x) {return ((float)sin((double)x)); }
KDEWIN_EXPORT __inline float cosf (float x) {return ((float)cos((double)x));}
KDEWIN_EXPORT __inline float tanf (float x) {return ((float)tan((double)x));}
/* 7.12.6.7 */
KDEWIN_EXPORT __inline float logf(float x) {return ((float)log((double)x)); }
KDEWIN_EXPORT __inline float powf(float x, float y) {return ((float)pow((double)x, (double)y)); }
/* 7.12.6.8 */
KDEWIN_EXPORT __inline float log10f (float x) {return ((float)log10((double)x));}
/* 7.12.7.2 */
KDEWIN_EXPORT __inline float fabsf (float x) {return ((float)fabs((double)x));}
#endif

#ifndef DONT_USE_ASM
/* 7.12.9.3 */
// this is a little bit more complicated - don't raise an exception
// -> set fpu control word bit 5 so it won't generate one
KDEWIN_EXPORT __inline float nearbyintf(float x)
{
    unsigned int tmpMSW1;
    unsigned int tmpMSW2;
    __asm {
        // get current state
        fnstcw tmpMSW1
    }
    // set bit 5
    tmpMSW2 = tmpMSW1 | 0x00000020;
	__asm {
        // and load
        fldcw tmpMSW2
        // do the job
        fld x
        frndint
        // clear exception
        fclex
        // restore old state
        fldcw tmpMSW1
    }
}

KDEWIN_EXPORT __inline double nearbyint(double x)
{
    unsigned int tmpMSW1;
    unsigned int tmpMSW2;
    __asm {
        // get current state
        fnstcw tmpMSW1
    }
    // set bit 5
    tmpMSW2 = tmpMSW1 | 0x00000020;
	__asm {
        // and load
        fldcw tmpMSW2
        // do the job
        fld x
        frndint
        // clear exception
        fclex
        // restore old state
        fldcw tmpMSW1
    }
}

KDEWIN_EXPORT __inline long double nearbyintl(long double x)
{
    unsigned int tmpMSW1;
    unsigned int tmpMSW2;
    __asm {
        // get current state
        fnstcw tmpMSW1
    }
    // set bit 5
    tmpMSW2 = tmpMSW1 | 0x00000020;
	__asm {
        // and load
        fldcw tmpMSW2
        // do the job
        fld x
        frndint
        // clear exception
        fclex
        // restore old state
        fldcw tmpMSW1
    }
}

/* 7.12.9.4 */
KDEWIN_EXPORT __inline float rintf( float x )
{
    __asm {
        fld x
        frndint
    }
}

KDEWIN_EXPORT __inline double rint( double x )
{
    __asm {
        fld x
        frndint
    }
}

KDEWIN_EXPORT __inline long double rintl( long double x )
{
    __asm {
        fld x
        frndint
    }
}
#endif


#if _MSC_VER < 1800
KDEWIN_EXPORT __inline long lroundf ( float x )
{
  /* Add +/- 0.5, then round towards zero.  */
  float tmp = floorf ( x );
  if (isnan (tmp)
      || tmp > (float)LONG_MAX
      || tmp < (float)LONG_MIN)
    {
      errno = ERANGE;
      /* Undefined behaviour, so we could return anything.  */
      /* return tmp > 0.0F ? LONG_MAX : LONG_MIN;  */
    }
  return (long)tmp;
}

/* 7.12.9.7 (before 7.12.9.6!)*/
KDEWIN_EXPORT __inline long lround ( double x )
{
  /* Add +/- 0.5 then then round towards zero.  */
  double tmp = floor ( x );
  if (isnan (tmp)
      || tmp > (double)LONG_MAX
      || tmp < (double)LONG_MIN)
    {
      errno = ERANGE;
      /* Undefined behaviour, so we could return anything.  */
      /* return tmp > 0.0 ? LONG_MAX : LONG_MIN;  */
    }
  return (long)tmp;
}

KDEWIN_EXPORT __inline long lroundl ( long double x )
{
  /* Add +/- 0.5, then round towards zero.  */
  long double tmp = floorl ( x );
  if (isnan (tmp)
      || tmp > (long double)LONG_MAX
      || tmp < (long double)LONG_MIN)
    {
      errno = ERANGE;
      /* Undefined behaviour, so we could return anything.  */
      /* return tmp > 0.0L ? LONG_MAX : LONG_MIN;  */
    }
  return (long)tmp;
}

/* 7.12.9.6 */
KDEWIN_EXPORT __inline float roundf ( float x )
{
  return (float)lroundf( x );
}

KDEWIN_EXPORT __inline double round ( double x )
{
  return (double)lround( x );
}

KDEWIN_EXPORT __inline long double roundl ( long double x )
{
  return (long double)lroundl( x );
}
#endif

#ifndef DONT_USE_ASM
/* 7.12.9.8 */
/* round towards zero, regardless of fpu control word settings */
KDEWIN_EXPORT __inline float truncf( float x )
{
    unsigned int tmpMSW1;
    unsigned int tmpMSW2;
    __asm {
        // get current state
        fnstcw tmpMSW1
    }
    // set bit 5
    tmpMSW2 = (tmpMSW1 & ~(0x0000 | 0x0400 | 0x0800 | 0x0c00))
                       | 0x0c00;
	__asm {
        // and load
        fldcw tmpMSW2
        // do the job
        fld x
        frndint
        // clear exception
        fclex
        // restore old state
        fldcw tmpMSW1
    }
}

KDEWIN_EXPORT __inline double trunc( double x )
{
    unsigned int tmpMSW1;
    unsigned int tmpMSW2;
    __asm {
        // get current state
        fnstcw tmpMSW1
    }
    // set bit 5
    tmpMSW2 = (tmpMSW1 & ~(0x0000 | 0x0400 | 0x0800 | 0x0c00))
                       | 0x0c00;
	__asm {
        // and load
        fldcw tmpMSW2
        // do the job
        fld x
        frndint
        // clear exception
        fclex
        // restore old state
        fldcw tmpMSW1
    }
}

KDEWIN_EXPORT __inline long double truncl( long double x )
{
    unsigned int tmpMSW1;
    unsigned int tmpMSW2;
    __asm {
        // get current state
        fnstcw tmpMSW1
    }
    // set bit 5
    tmpMSW2 = (tmpMSW1 & ~(0x0000 | 0x0400 | 0x0800 | 0x0c00))
                       | 0x0c00;
	__asm {
        // and load
        fldcw tmpMSW2
        // do the job
        fld x
        frndint
        // clear exception
        fclex
        // restore old state
        fldcw tmpMSW1
    }
}
#endif

/* 7.12.12.2 */
#if _MSC_VER < 1800
KDEWIN_EXPORT __inline double fmax (double a, double b)
{
    if(isnan(a))
        return b;
    if(isnan(b))
        return a;
    return a > b ? a : b;
}

KDEWIN_EXPORT __inline float fmaxf (float a, float b)
{
    if(isnan(a))
        return b;
    if(isnan(b))
        return a;
    return a > b ? a : b;
}

KDEWIN_EXPORT __inline long double fmaxl (long double a, long double b)
{
    if(isnan(a))
        return b;
    if(isnan(b))
        return a;
    return a > b ? a : b;
}

/* 7.12.12.3 */
KDEWIN_EXPORT __inline double fmin (double a, double b)
{
    if(isnan(a))
        return b;
    if(isnan(b))
        return a;
    return a < b ? a : b;
}

KDEWIN_EXPORT __inline float fminf (float a, float b)
{
    if(isnan(a))
        return b;
    if(isnan(b))
        return a;
    return a < b ? a : b;
}

KDEWIN_EXPORT __inline long double fminl (long double a, long double b)
{
    if(isnan(a))
        return b;
    if(isnan(b))
        return a;
    return a < b ? a : b;
}
#endif

#ifdef __cplusplus
}

#if _MSC_VER >= 1400 && _MSC_VER < 1700 && !defined(DONT_USE_ASM)
// convenience function to avoid useless casts from int to whatever
__inline long double sqrt(int x)
{
    return sqrt((long double)x);
}

__inline long double log(int x)
{
    return logl((long double)x);
}

__inline long double log10(int x)
{
    return log10((long double)x);
}

__inline long double floor(int x)
{
    return floor((long double)x);
}

/* msvc 7/7.1 has pow(int,int) */
__inline long double pow(int x, int y)
{
    return pow((long double)x, y);
}

__inline long double pow(int x, unsigned int y)
{
    return pow((long double)x, (long double)y);
}

__inline long double pow(int x, double y)
{
    return pow((double)x, y);
}

__inline long double pow(int x, long double y)
{
    return pow((long double)x, y);
}
#endif // _MSC_VER >= 1400
#endif // __cplusplus

#ifndef hypotf
# define hypotf _hypotf
#endif

#endif /* KDEWIN_MATH_H */
#endif /* NO_KDEWIN */
