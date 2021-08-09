// Standard iostream objects -*- C++ -*-

// Copyright (C) 1997, 1998, 1999, 2001, 2002 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING.  If not, write to the Free
// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
// USA.

// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.

//
// ISO C++ 14882: 27.3  Standard iostream objects
//

/** @file iostream
 *  This is a Standard C++ Library header.  You should @c #include this header
 *  in your programs, rather than any of the "st[dl]_*.h" implementation files.
 */

#ifndef _GLIBCXX_IOSTREAM
#define _GLIBCXX_IOSTREAM 1

#pragma GCC system_header

#include <bits/c++config.h>
#include <ostream>
#include <istream>

namespace std 
{
  /**
   *  @name Standard Stream Objects
   *
   *  The &lt;iostream&gt; header declares the eight <em>standard stream
   *  objects</em>.  For other declarations, see
   *  http://gcc.gnu.org/onlinedocs/libstdc++/27_io/howto.html#10 and the
   *  @link s27_2_iosfwd I/O forward declarations @endlink
   *
   *  They are required by default to cooperate with the global C library's
   *  @c FILE streams, and to be available during program startup and
   *  termination.  For more information, see the HOWTO linked to above.
  */
  //@{
  extern istream cin;		///< Linked to standard input
  extern ostream cout;		///< Linked to standard output
  extern ostream cerr;		///< Linked to standard error (unbuffered)
  extern ostream clog;		///< Linked to standard error (buffered)

#ifdef _GLIBCXX_USE_WCHAR_T
  extern wistream wcin;		///< Linked to standard input
  extern wostream wcout;	///< Linked to standard output
  extern wostream wcerr;	///< Linked to standard error (unbuffered)
  extern wostream wclog;	///< Linked to standard error (buffered)
#endif
  //@}

  // For construction of filebuffers for cout, cin, cerr, clog et. al.
  static ios_base::Init __ioinit;
} // namespace std

#endif /* _GLIBCXX_IOSTREAM */

#include <iostream>
// -*- C++ -*- forwarding header.

// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003
// Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING.  If not, write to the Free
// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
// USA.

// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.

//
// ISO C++ 14882: 27.8.2  C Library files
//

/** @file cstdio
 *  This is a Standard C++ Library file.  You should @c #include this file
 *  in your programs, rather than any of the "*.h" implementation files.
 *
 *  This is the C++ version of the Standard C Library header @c stdio.h,
 *  and its contents are (mostly) the same as that header, but are all
 *  contained in the namespace @c std.
 */

#ifndef _GLIBCXX_CSTDIO
#define _GLIBCXX_CSTDIO 1

#pragma GCC system_header

#include <bits/c++config.h>
#include <cstddef>

#include <stdio.h>

// Get rid of those macros defined in <stdio.h> in lieu of real functions.
#undef clearerr
#undef fclose
#undef feof
#undef ferror
#undef fflush
#undef fgetc
#undef fgetpos
#undef fgets
#undef fopen
#undef fprintf
#undef fputc
#undef fputs
#undef fread
#undef freopen
#undef fscanf
#undef fseek
#undef fsetpos
#undef ftell
#undef fwrite
#undef getc
#undef getchar
#undef gets
#undef perror
#undef printf
#undef putc
#undef putchar
#undef puts
#undef remove
#undef rename
#undef rewind
#undef scanf
#undef setbuf
#undef setvbuf
#undef sprintf
#undef sscanf
#undef tmpfile
#undef tmpnam
#undef ungetc
#undef vfprintf
#undef vprintf
#undef vsprintf

namespace std
{
  using ::FILE;
  using ::fpos_t;

  using ::clearerr;
  using ::fclose;
  using ::feof;
  using ::ferror;
  using ::fflush;
  using ::fgetc;
  using ::fgetpos;
  using ::fgets;
  using ::fopen;
  using ::fprintf;
  using ::fputc;
  using ::fputs;
  using ::fread;
  using ::freopen;
  using ::fscanf;
  using ::fseek;
  using ::fsetpos;
  using ::ftell;
  using ::fwrite;
  using ::getc;
  using ::getchar;
  using ::gets;
  using ::perror;
  using ::printf;
  using ::putc;
  using ::putchar;
  using ::puts;
  using ::remove;
  using ::rename;
  using ::rewind;
  using ::scanf;
  using ::setbuf;
  using ::setvbuf;
  using ::sprintf;
  using ::sscanf;
  using ::tmpfile;
  using ::tmpnam;
  using ::ungetc;
  using ::vfprintf;
  using ::vprintf;
  using ::vsprintf;
}

#if _GLIBCXX_USE_C99

#undef snprintf
#undef vfscanf
#undef vscanf
#undef vsnprintf
#undef vsscanf

namespace __gnu_cxx
{
#if _GLIBCXX_USE_C99_CHECK || _GLIBCXX_USE_C99_DYNAMIC
  extern "C" int
    (snprintf)(char * restrict, size_t, const char * restrict, ...);
  extern "C" int
    (vfscanf)(FILE * restrict, const char * restrict, __gnuc_va_list);
  extern "C" int (vscanf)(const char * restrict, __gnuc_va_list);
  extern "C" int
    (vsnprintf)(char * restrict, size_t, const char * restrict, __gnuc_va_list);
  extern "C" int
    (vsscanf)(const char * restrict, const char * restrict, __gnuc_va_list);
#endif
#if !_GLIBCXX_USE_C99_DYNAMIC
  using ::snprintf;
  using ::vfscanf;
  using ::vscanf;
  using ::vsnprintf;
  using ::vsscanf;
#endif
}

namespace std
{
  using __gnu_cxx::snprintf;
  using __gnu_cxx::vfscanf;
  using __gnu_cxx::vscanf;
  using __gnu_cxx::vsnprintf;
  using __gnu_cxx::vsscanf;
}
#endif

#endif

// -*- C++ -*- forwarding header.

// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003
// Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING.  If not, write to the Free
// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
// USA.

// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.

//
// ISO C++ 14882: 20.4.6  C library
//

/** @file cstdlib
 *  This is a Standard C++ Library file.  You should @c #include this file
 *  in your programs, rather than any of the "*.h" implementation files.
 *
 *  This is the C++ version of the Standard C Library header @c stdlib.h,
 *  and its contents are (mostly) the same as that header, but are all
 *  contained in the namespace @c std.
 */

#ifndef _GLIBCXX_CSTDLIB
#define _GLIBCXX_CSTDLIB 1

#pragma GCC system_header

#include <bits/c++config.h>
#include <cstddef>

#include <stdlib.h>

// Get rid of those macros defined in <stdlib.h> in lieu of real functions.
#undef abort
#undef abs
#undef atexit
#undef atof
#undef atoi
#undef atol
#undef bsearch
#undef calloc
#undef div
#undef exit
#undef free
#undef getenv
#undef labs
#undef ldiv
#undef malloc
#undef mblen
#undef mbstowcs
#undef mbtowc
#undef qsort
#undef rand
#undef realloc
#undef srand
#undef strtod
#undef strtol
#undef strtoul
#undef system
#undef wcstombs
#undef wctomb

namespace std
{
  using ::div_t;
  using ::ldiv_t;

  using ::abort;
  using ::abs;
  using ::atexit;
  using ::atof;
  using ::atoi;
  using ::atol;
  using ::bsearch;
  using ::calloc;
  using ::div;
  using ::exit;
  using ::free;
  using ::getenv;
  using ::labs;
  using ::ldiv;
  using ::malloc;
#ifdef _GLIBCXX_HAVE_MBSTATE_T
  using ::mblen;
  using ::mbstowcs;
  using ::mbtowc;
#endif // _GLIBCXX_HAVE_MBSTATE_T
  using ::qsort;
  using ::rand;
  using ::realloc;
  using ::srand;
  using ::strtod;
  using ::strtol;
  using ::strtoul;
  using ::system;
#ifdef _GLIBCXX_USE_WCHAR_T
  using ::wcstombs;
  using ::wctomb;
#endif // _GLIBCXX_USE_WCHAR_T

  inline long
  abs(long __i) { return labs(__i); }

  inline ldiv_t
  div(long __i, long __j) { return ldiv(__i, __j); }
}

#if _GLIBCXX_USE_C99

#undef _Exit
#undef llabs
#undef lldiv
#undef atoll
#undef strtoll
#undef strtoull
#undef strtof
#undef strtold

namespace __gnu_cxx
{
#if !_GLIBCXX_USE_C99_LONG_LONG_DYNAMIC
  using ::lldiv_t;
#endif
#if _GLIBCXX_USE_C99_CHECK || _GLIBCXX_USE_C99_DYNAMIC
  extern "C" void (_Exit)(int);
#endif
#if !_GLIBCXX_USE_C99_DYNAMIC
  using ::_Exit;
#endif

  inline long long
  abs(long long __x) { return __x >= 0 ? __x : -__x; }

  inline long long
  llabs(long long __x) { return __x >= 0 ? __x : -__x; }

#if !_GLIBCXX_USE_C99_LONG_LONG_DYNAMIC
  inline lldiv_t
  div(long long __n, long long __d)
  { lldiv_t __q; __q.quot = __n / __d; __q.rem = __n % __d; return __q; }

  inline lldiv_t
  lldiv(long long __n, long long __d)
  { lldiv_t __q; __q.quot = __n / __d; __q.rem = __n % __d; return __q; }
#endif

#if _GLIBCXX_USE_C99_LONG_LONG_CHECK || _GLIBCXX_USE_C99_LONG_LONG_DYNAMIC
  extern "C" long long int (atoll)(const char *);
  extern "C" long long int
    (strtoll)(const char * restrict, char ** restrict, int);
  extern "C" unsigned long long int
    (strtoull)(const char * restrict, char ** restrict, int);
#endif
#if !_GLIBCXX_USE_C99_LONG_LONG_DYNAMIC
  using ::atoll;
  using ::strtoll;
  using ::strtoull;
#endif
  using ::strtof;
  using ::strtold;
}

namespace std
{
#if !_GLIBCXX_USE_C99_LONG_LONG_DYNAMIC
  using __gnu_cxx::lldiv_t;
#endif
  using __gnu_cxx::_Exit;
  using __gnu_cxx::abs;
  using __gnu_cxx::llabs;
#if !_GLIBCXX_USE_C99_LONG_LONG_DYNAMIC
  using __gnu_cxx::div;
  using __gnu_cxx::lldiv;
#endif
  using __gnu_cxx::atoll;
  using __gnu_cxx::strtof;
  using __gnu_cxx::strtoll;
  using __gnu_cxx::strtoull;
  using __gnu_cxx::strtold;
}
#endif

#endif

// -*- C++ -*- C forwarding header.

// Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002, 2003
// Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING.  If not, write to the Free
// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
// USA.

// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.

//
// ISO C++ 14882: 26.5  C library
//

/** @file cmath
 *  This is a Standard C++ Library file.  You should @c #include this file
 *  in your programs, rather than any of the "*.h" implementation files.
 *
 *  This is the C++ version of the Standard C Library header @c math.h,
 *  and its contents are (mostly) the same as that header, but are all
 *  contained in the namespace @c std.
 */

#ifndef _GLIBCXX_CMATH
#define _GLIBCXX_CMATH 1

#pragma GCC system_header

#include <bits/c++config.h>
#include <bits/cpp_type_traits.h>

#include <math.h>

// Get rid of those macros defined in <math.h> in lieu of real functions.
#undef abs
#undef div
#undef acos
#undef asin
#undef atan
#undef atan2
#undef ceil
#undef cos
#undef cosh
#undef exp
#undef fabs
#undef floor
#undef fmod
#undef frexp
#undef ldexp
#undef log
#undef log10
#undef modf
#undef pow
#undef sin
#undef sinh
#undef sqrt
#undef tan
#undef tanh


namespace std
{
  // Forward declaration of a helper function.  This really should be
  // an `exported' forward declaration.
  template<typename _Tp> _Tp __cmath_power(_Tp, unsigned int);

  inline double
  abs(double __x)
  { return __builtin_fabs(__x); }

  inline float
  abs(float __x)
  { return __builtin_fabsf(__x); }

  inline long double
  abs(long double __x)
  { return __builtin_fabsl(__x); }

  using ::acos;

  inline float
  acos(float __x)
  { return __builtin_acosf(__x); }

  inline long double
  acos(long double __x)
  { return __builtin_acosl(__x); }

  template<typename _Tp>
    inline typename __enable_if<double, __is_integer<_Tp>::_M_type>::_M_type
    acos(_Tp __x)
    {
      return __builtin_acos(__x);
    }

  using ::asin;

  inline float
  asin(float __x)
  { return __builtin_asinf(__x); }

  inline long double
  asin(long double __x)
  { return __builtin_asinl(__x); }

  template<typename _Tp>
    inline typename __enable_if<double, __is_integer<_Tp>::_M_type>::_M_type
    asin(_Tp __x)
    { return __builtin_asin(__x); }

  using ::atan;

  inline float
  atan(float __x)
  { return __builtin_atanf(__x); }

  inline long double
  atan(long double __x)
  { return __builtin_atanl(__x); }

  template<typename _Tp>
    inline typename __enable_if<double, __is_integer<_Tp>::_M_type>::_M_type
    atan(_Tp __x)
    { return __builtin_atan(__x); }

  using ::atan2;

  inline float
  atan2(float __y, float __x)
  { return __builtin_atan2f(__y, __x); }

  inline long double
  atan2(long double __y, long double __x)
  { return __builtin_atan2l(__y, __x); }

  template<typename _Tp, typename _Up>
    inline typename __enable_if<double, __is_integer<_Tp>::_M_type
                                        && __is_integer<_Up>::_M_type>::_M_type
    atan2(_Tp __y, _Up __x)
    { return __builtin_atan2(__y, __x); }

  using ::ceil;

  inline float
  ceil(float __x)
  { return __builtin_ceilf(__x); }

  inline long double
  ceil(long double __x)
  { return __builtin_ceill(__x); }

  template<typename _Tp>
    inline typename __enable_if<double, __is_integer<_Tp>::_M_type>::_M_type
    ceil(_Tp __x)
    { return __builtin_ceil(__x); }

  using ::cos;

  inline float
  cos(float __x)
  { return __builtin_cosf(__x); }

  inline long double
  cos(long double __x)
  { return __builtin_cosl(__x); }

  template<typename _Tp>
    inline typename __enable_if<double, __is_integer<_Tp>::_M_type>::_M_type
    cos(_Tp __x)
    { return __builtin_cos(__x); }

  using ::cosh;

  inline float
  cosh(float __x)
  { return __builtin_coshf(__x); }

  inline long double
  cosh(long double __x)
  { return __builtin_coshl(__x); }

  template<typename _Tp>
    inline typename __enable_if<double, __is_integer<_Tp>::_M_type>::_M_type
    cosh(_Tp __x)
    { return __builtin_cosh(__x); }

  using ::exp;

  inline float
  exp(float __x)
  { return __builtin_expf(__x); }

  inline long double
  exp(long double __x)
  { return __builtin_expl(__x); }

  template<typename _Tp>
    inline typename __enable_if<double, __is_integer<_Tp>::_M_type>::_M_type
    exp(_Tp __x)
    { return __builtin_exp(__x); }

  using ::fabs;

  inline float
  fabs(float __x)
  { return __builtin_fabsf(__x); }

  inline long double
  fabs(long double __x)
  { return __builtin_fabsl(__x); }

  template<typename _Tp>
    inline typename __enable_if<double, __is_integer<_Tp>::_M_type>::_M_type
    fabs(_Tp __x)
    { return __builtin_fabs(__x); }

  using ::floor;

  inline float
  floor(float __x)
  { return __builtin_floorf(__x); }

  inline long double
  floor(long double __x)
  { return __builtin_floorl(__x); }

  template<typename _Tp>
    inline typename __enable_if<double, __is_integer<_Tp>::_M_type>::_M_type
    floor(_Tp __x)
    { return __builtin_floor(__x); }

  using ::fmod;

  inline float
  fmod(float __x, float __y)
  { return __builtin_fmodf(__x, __y); }

  inline long double
  fmod(long double __x, long double __y)
  { return __builtin_fmodl(__x, __y); }

  using ::frexp;

  inline float
  frexp(float __x, int* __exp)
  { return __builtin_frexpf(__x, __exp); }

  inline long double
  frexp(long double __x, int* __exp)
  { return __builtin_frexpl(__x, __exp); }

  template<typename _Tp>
    inline typename __enable_if<double, __is_integer<_Tp>::_M_type>::_M_type
    frexp(_Tp __x, int* __exp)
    { return __builtin_frexp(__x, __exp); }

  using ::ldexp;

  inline float
  ldexp(float __x, int __exp)
  { return __builtin_ldexpf(__x, __exp); }

  inline long double
  ldexp(long double __x, int __exp)
  { return __builtin_ldexpl(__x, __exp); }

  template<typename _Tp>
  inline typename __enable_if<double, __is_integer<_Tp>::_M_type>::_M_type
  ldexp(_Tp __x, int __exp)
  { return __builtin_ldexp(__x, __exp); }

  using ::log;

  inline float
  log(float __x)
  { return __builtin_logf(__x); }

  inline long double
  log(long double __x)
  { return __builtin_logl(__x); }

  template<typename _Tp>
    inline typename __enable_if<double, __is_integer<_Tp>::_M_type>::_M_type
    log(_Tp __x)
    { return __builtin_log(__x); }

  using ::log10;

  inline float
  log10(float __x)
  { return __builtin_log10f(__x); }

  inline long double
  log10(long double __x)
  { return __builtin_log10l(__x); }

  template<typename _Tp>
    inline typename __enable_if<double, __is_integer<_Tp>::_M_type>::_M_type
    log10(_Tp __x)
    { return __builtin_log10(__x); }

  using ::modf;

  inline float
  modf(float __x, float* __iptr)
  { return __builtin_modff(__x, __iptr); }

  inline long double
  modf(long double __x, long double* __iptr)
  { return __builtin_modfl(__x, __iptr); }

  template<typename _Tp>
    inline _Tp
    __pow_helper(_Tp __x, int __n)
    {
      return __n < 0
        ? _Tp(1)/__cmath_power(__x, -__n)
        : __cmath_power(__x, __n);
    }

  using ::pow;

  inline float
  pow(float __x, float __y)
  { return __builtin_powf(__x, __y); }

  inline long double
  pow(long double __x, long double __y)
  { return __builtin_powl(__x, __y); }

  inline double
  pow(double __x, int __i)
  { return __pow_helper(__x, __i); }

  inline float
  pow(float __x, int __n)
  { return __pow_helper(__x, __n); }

  inline long double
  pow(long double __x, int __n)
  { return __pow_helper(__x, __n); }

  using ::sin;

  inline float
  sin(float __x)
  { return __builtin_sinf(__x); }

  inline long double
  sin(long double __x)
  { return __builtin_sinl(__x); }

  template<typename _Tp>
    inline typename __enable_if<double, __is_integer<_Tp>::_M_type>::_M_type
    sin(_Tp __x)
    { return __builtin_sin(__x); }

  using ::sinh;

  inline float
  sinh(float __x)
  { return __builtin_sinhf(__x); }

  inline long double
  sinh(long double __x)
  { return __builtin_sinhl(__x); }

  template<typename _Tp>
    inline typename __enable_if<double, __is_integer<_Tp>::_M_type>::_M_type
    sinh(_Tp __x)
    { return __builtin_sinh(__x); }

  using ::sqrt;

  inline float
  sqrt(float __x)
  { return __builtin_sqrtf(__x); }

  inline long double
  sqrt(long double __x)
  { return __builtin_sqrtl(__x); }

  template<typename _Tp>
    inline typename __enable_if<double, __is_integer<_Tp>::_M_type>::_M_type
    sqrt(_Tp __x)
    { return __builtin_sqrt(__x); }

  using ::tan;

  inline float
  tan(float __x)
  { return __builtin_tanf(__x); }

  inline long double
  tan(long double __x)
  { return __builtin_tanl(__x); }

  template<typename _Tp>
    inline typename __enable_if<double, __is_integer<_Tp>::_M_type>::_M_type
    tan(_Tp __x)
    { return __builtin_tan(__x); }

  using ::tanh;

  inline float
  tanh(float __x)
  { return __builtin_tanhf(__x); }

  inline long double
  tanh(long double __x)
  { return __builtin_tanhl(__x); }

  template<typename _Tp>
    inline typename __enable_if<double, __is_integer<_Tp>::_M_type>::_M_type
    tanh(_Tp __x)
    { return __builtin_tanh(__x); }
}

#if _GLIBCXX_USE_C99_MATH
#if !_GLIBCXX_USE_C99_FP_MACROS_DYNAMIC
// These are possible macros imported from C99-land. For strict
// conformance, remove possible C99-injected names from the global
// namespace, and sequester them in the __gnu_cxx extension namespace.
namespace __gnu_cxx
{
  template<typename _Tp>
    int
    __capture_fpclassify(_Tp __f) { return fpclassify(__f); }

  template<typename _Tp>
    int
    __capture_isfinite(_Tp __f) { return isfinite(__f); }

  template<typename _Tp>
    int
    __capture_isinf(_Tp __f) { return isinf(__f); }

  template<typename _Tp>
    int
    __capture_isnan(_Tp __f) { return isnan(__f); }

  template<typename _Tp>
    int
    __capture_isnormal(_Tp __f) { return isnormal(__f); }

  template<typename _Tp>
    int
    __capture_signbit(_Tp __f) { return signbit(__f); }

  template<typename _Tp>
    int
    __capture_isgreater(_Tp __f1, _Tp __f2)
    { return isgreater(__f1, __f2); }

  template<typename _Tp>
     int
     __capture_isgreaterequal(_Tp __f1, _Tp __f2)
     { return isgreaterequal(__f1, __f2); }

  template<typename _Tp>
     int
     __capture_isless(_Tp __f1, _Tp __f2) { return isless(__f1, __f2); }

  template<typename _Tp>
     int
     __capture_islessequal(_Tp __f1, _Tp __f2)
     { return islessequal(__f1, __f2); }

  template<typename _Tp>
     int
     __capture_islessgreater(_Tp __f1, _Tp __f2)
     { return islessgreater(__f1, __f2); }

  template<typename _Tp>
     int
     __capture_isunordered(_Tp __f1, _Tp __f2)
     { return isunordered(__f1, __f2); }
}

// Only undefine the C99 FP macros, if actually captured for namespace movement
#undef fpclassify
#undef isfinite
#undef isinf
#undef isnan
#undef isnormal
#undef signbit
#undef isgreater
#undef isgreaterequal
#undef isless
#undef islessequal
#undef islessgreater
#undef isunordered
#endif /* _GLIBCXX_USE_C99_FP_MACROS_DYNAMIC */
#endif

#if _GLIBCXX_USE_C99_MATH
#if !_GLIBCXX_USE_C99_FP_MACROS_DYNAMIC
namespace __gnu_cxx
{
  template<typename _Tp>
    int
    fpclassify(_Tp __f) { return __capture_fpclassify(__f); }

  template<typename _Tp>
    int
    isfinite(_Tp __f) { return __capture_isfinite(__f); }

  template<typename _Tp>
    int
    isinf(_Tp __f) { return __capture_isinf(__f); }

  template<typename _Tp>
    int
    isnan(_Tp __f) { return __capture_isnan(__f); }

  template<typename _Tp>
    int
    isnormal(_Tp __f) { return __capture_isnormal(__f); }

  template<typename _Tp>
    int
    signbit(_Tp __f) { return __capture_signbit(__f); }

  template<typename _Tp>
    int
    isgreater(_Tp __f1, _Tp __f2) { return __capture_isgreater(__f1, __f2); }

  template<typename _Tp>
    int
    isgreaterequal(_Tp __f1, _Tp __f2)
    { return __capture_isgreaterequal(__f1, __f2); }

  template<typename _Tp>
    int
    isless(_Tp __f1, _Tp __f2) { return __capture_isless(__f1, __f2); }

  template<typename _Tp>
    int
    islessequal(_Tp __f1, _Tp __f2)
    { return __capture_islessequal(__f1, __f2); }

  template<typename _Tp>
    int
    islessgreater(_Tp __f1, _Tp __f2)
    { return __capture_islessgreater(__f1, __f2); }

  template<typename _Tp>
    int
    isunordered(_Tp __f1, _Tp __f2)
    { return __capture_isunordered(__f1, __f2); }
}

namespace std
{
  using __gnu_cxx::fpclassify;
  using __gnu_cxx::isfinite;
  using __gnu_cxx::isinf;
  using __gnu_cxx::isnan;
  using __gnu_cxx::isnormal;
  using __gnu_cxx::signbit;
  using __gnu_cxx::isgreater;
  using __gnu_cxx::isgreaterequal;
  using __gnu_cxx::isless;
  using __gnu_cxx::islessequal;
  using __gnu_cxx::islessgreater;
  using __gnu_cxx::isunordered;
}
#endif /* _GLIBCXX_USE_C99_FP_MACROS_DYNAMIC */
#endif

#ifndef _GLIBCXX_EXPORT_TEMPLATE
# include <bits/cmath.tcc>
#endif

#endif

/*
 * string.h
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is a part of the mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within the package.
 *
 * Definitions for memory and string functions.
 *
 */

#ifndef _STRING_H_
#define	_STRING_H_

/* All the headers include this file. */
#include <_mingw.h>

/*
 * Define size_t, wchar_t and NULL
 */
#define __need_size_t
#define __need_wchar_t
#define	__need_NULL
#ifndef RC_INVOKED
#include <stddef.h>
#endif	/* Not RC_INVOKED */

#ifndef RC_INVOKED

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Prototypes of the ANSI Standard C library string functions.
 */
_CRTIMP void* __cdecl	memchr (const void*, int, size_t) __MINGW_ATTRIB_PURE;
_CRTIMP int __cdecl 	memcmp (const void*, const void*, size_t) __MINGW_ATTRIB_PURE;
_CRTIMP void* __cdecl 	memcpy (void*, const void*, size_t);
_CRTIMP void* __cdecl	memmove (void*, const void*, size_t);
_CRTIMP void* __cdecl	memset (void*, int, size_t);
_CRTIMP char* __cdecl	strcat (char*, const char*);
_CRTIMP char* __cdecl	strchr (const char*, int)  __MINGW_ATTRIB_PURE;
_CRTIMP int __cdecl	strcmp (const char*, const char*)  __MINGW_ATTRIB_PURE;
_CRTIMP int __cdecl	strcoll (const char*, const char*);	/* Compare using locale */
_CRTIMP char* __cdecl	strcpy (char*, const char*);
_CRTIMP size_t __cdecl	strcspn (const char*, const char*)  __MINGW_ATTRIB_PURE;
_CRTIMP char* __cdecl	strerror (int); /* NOTE: NOT an old name wrapper. */

_CRTIMP size_t __cdecl	strlen (const char*)  __MINGW_ATTRIB_PURE;
_CRTIMP char* __cdecl	strncat (char*, const char*, size_t);
_CRTIMP int __cdecl	strncmp (const char*, const char*, size_t)  __MINGW_ATTRIB_PURE;
_CRTIMP char* __cdecl	strncpy (char*, const char*, size_t);
_CRTIMP char* __cdecl	strpbrk (const char*, const char*)  __MINGW_ATTRIB_PURE;
_CRTIMP char* __cdecl	strrchr (const char*, int)  __MINGW_ATTRIB_PURE;
_CRTIMP size_t __cdecl	strspn (const char*, const char*)  __MINGW_ATTRIB_PURE;
_CRTIMP char* __cdecl	strstr (const char*, const char*)  __MINGW_ATTRIB_PURE;
_CRTIMP char* __cdecl	strtok (char*, const char*);
_CRTIMP size_t __cdecl	strxfrm (char*, const char*, size_t);

#ifndef __STRICT_ANSI__
/*
 * Extra non-ANSI functions provided by the CRTDLL library
 */
_CRTIMP char* __cdecl	_strerror (const char *);
_CRTIMP void* __cdecl	_memccpy (void*, const void*, int, size_t);
_CRTIMP int __cdecl 	_memicmp (const void*, const void*, size_t);
_CRTIMP char* __cdecl 	_strdup (const char*) __MINGW_ATTRIB_MALLOC;
_CRTIMP int __cdecl	_strcmpi (const char*, const char*);
_CRTIMP int __cdecl	_stricmp (const char*, const char*);
_CRTIMP int __cdecl	_stricoll (const char*, const char*);
_CRTIMP char* __cdecl	_strlwr (char*);
_CRTIMP int __cdecl	_strnicmp (const char*, const char*, size_t);
_CRTIMP char* __cdecl	_strnset (char*, int, size_t);
_CRTIMP char* __cdecl	_strrev (char*);
_CRTIMP char* __cdecl	_strset (char*, int);
_CRTIMP char* __cdecl	_strupr (char*);
_CRTIMP void __cdecl	_swab (const char*, char*, size_t);

#ifdef __MSVCRT__
_CRTIMP int __cdecl  _strncoll(const char*, const char*, size_t);
_CRTIMP int __cdecl  _strnicoll(const char*, const char*, size_t);
#endif

#ifndef	_NO_OLDNAMES
/*
 * Non-underscored versions of non-ANSI functions. They live in liboldnames.a
 * and provide a little extra portability. Also a few extra UNIX-isms like
 * strcasecmp.
 */
_CRTIMP void* __cdecl	memccpy (void*, const void*, int, size_t);
_CRTIMP int __cdecl	memicmp (const void*, const void*, size_t);
_CRTIMP char* __cdecl	strdup (const char*) __MINGW_ATTRIB_MALLOC;
_CRTIMP int __cdecl	strcmpi (const char*, const char*);
_CRTIMP int __cdecl	stricmp (const char*, const char*);
__CRT_INLINE int __cdecl
strcasecmp (const char * __sz1, const char * __sz2)
  {return _stricmp (__sz1, __sz2);}
_CRTIMP int __cdecl	stricoll (const char*, const char*);
_CRTIMP char* __cdecl	strlwr (char*);
_CRTIMP int __cdecl	strnicmp (const char*, const char*, size_t);
__CRT_INLINE int __cdecl
strncasecmp (const char * __sz1, const char * __sz2, size_t __sizeMaxCompare)
  {return _strnicmp (__sz1, __sz2, __sizeMaxCompare);}
_CRTIMP char* __cdecl	strnset (char*, int, size_t);
_CRTIMP char* __cdecl	strrev (char*);
_CRTIMP char* __cdecl	strset (char*, int);
_CRTIMP char* __cdecl	strupr (char*);
#ifndef _UWIN
_CRTIMP void __cdecl	swab (const char*, char*, size_t);
#endif /* _UWIN */
#endif /* _NO_OLDNAMES */

#endif	/* Not __STRICT_ANSI__ */

#ifndef _WSTRING_DEFINED
/*
 * Unicode versions of the standard calls.
 * Also in wchar.h, where they belong according to ISO standard.
 */
_CRTIMP wchar_t* __cdecl wcscat (wchar_t*, const wchar_t*);
_CRTIMP wchar_t* __cdecl wcschr (const wchar_t*, wchar_t);
_CRTIMP int __cdecl	wcscmp (const wchar_t*, const wchar_t*);
_CRTIMP int __cdecl	wcscoll (const wchar_t*, const wchar_t*);
_CRTIMP wchar_t* __cdecl wcscpy (wchar_t*, const wchar_t*);
_CRTIMP size_t __cdecl	wcscspn (const wchar_t*, const wchar_t*);
/* Note:  _wcserror requires __MSVCRT_VERSION__ >= 0x0700.  */
_CRTIMP size_t __cdecl	wcslen (const wchar_t*);
_CRTIMP wchar_t* __cdecl wcsncat (wchar_t*, const wchar_t*, size_t);
_CRTIMP int __cdecl	wcsncmp(const wchar_t*, const wchar_t*, size_t);
_CRTIMP wchar_t* __cdecl wcsncpy(wchar_t*, const wchar_t*, size_t);
_CRTIMP wchar_t* __cdecl wcspbrk(const wchar_t*, const wchar_t*);
_CRTIMP wchar_t* __cdecl wcsrchr(const wchar_t*, wchar_t);
_CRTIMP size_t __cdecl	wcsspn(const wchar_t*, const wchar_t*);
_CRTIMP wchar_t* __cdecl wcsstr(const wchar_t*, const wchar_t*);
_CRTIMP wchar_t* __cdecl wcstok(wchar_t*, const wchar_t*);
_CRTIMP size_t __cdecl	wcsxfrm(wchar_t*, const wchar_t*, size_t);

#ifndef	__STRICT_ANSI__
/*
 * Unicode versions of non-ANSI string functions provided by CRTDLL.
 */

/* NOTE: _wcscmpi not provided by CRTDLL, this define is for portability */
#define		_wcscmpi	_wcsicmp

_CRTIMP wchar_t* __cdecl _wcsdup (const wchar_t*);
_CRTIMP int __cdecl	_wcsicmp (const wchar_t*, const wchar_t*);
_CRTIMP int __cdecl	_wcsicoll (const wchar_t*, const wchar_t*);
_CRTIMP wchar_t* __cdecl _wcslwr (wchar_t*);
_CRTIMP int __cdecl	_wcsnicmp (const wchar_t*, const wchar_t*, size_t);
_CRTIMP wchar_t* __cdecl _wcsnset (wchar_t*, wchar_t, size_t);
_CRTIMP wchar_t* __cdecl _wcsrev (wchar_t*);
_CRTIMP wchar_t* __cdecl _wcsset (wchar_t*, wchar_t);
_CRTIMP wchar_t* __cdecl _wcsupr (wchar_t*);

#ifdef __MSVCRT__
_CRTIMP int __cdecl  _wcsncoll(const wchar_t*, const wchar_t*, size_t);
_CRTIMP int   __cdecl _wcsnicoll(const wchar_t*, const wchar_t*, size_t);
#if __MSVCRT_VERSION__ >= 0x0700
_CRTIMP  wchar_t* __cdecl _wcserror(int);
_CRTIMP  wchar_t* __cdecl __wcserror(const wchar_t*);
#endif
#endif

#ifndef	_NO_OLDNAMES
/* NOTE: There is no _wcscmpi, but this is for compatibility. */
int __cdecl wcscmpi (const wchar_t * __ws1, const wchar_t * __ws2);
__CRT_INLINE int __cdecl
wcscmpi (const wchar_t * __ws1, const wchar_t * __ws2)
  {return _wcsicmp (__ws1, __ws2);}
_CRTIMP wchar_t* __cdecl wcsdup (const wchar_t*);
_CRTIMP int __cdecl	wcsicmp (const wchar_t*, const wchar_t*);
_CRTIMP int __cdecl	wcsicoll (const wchar_t*, const wchar_t*);
_CRTIMP wchar_t* __cdecl wcslwr (wchar_t*);
_CRTIMP int __cdecl	wcsnicmp (const wchar_t*, const wchar_t*, size_t);
_CRTIMP wchar_t* __cdecl wcsnset (wchar_t*, wchar_t, size_t);
_CRTIMP wchar_t* __cdecl wcsrev (wchar_t*);
_CRTIMP wchar_t* __cdecl wcsset (wchar_t*, wchar_t);
_CRTIMP wchar_t* __cdecl wcsupr (wchar_t*);
#endif	/* Not _NO_OLDNAMES */

#endif	/* Not strict ANSI */

#define _WSTRING_DEFINED
#endif  /* _WSTRING_DEFINED */

#ifdef __cplusplus
}
#endif

#endif	/* Not RC_INVOKED */

#endif	/* Not _STRING_H_ */

/* 
 * assert.h
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is a part of the mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within the package.
 *
 * Define the assert macro for debug output.
 *
 */

#ifndef _ASSERT_H_
#define	_ASSERT_H_

/* All the headers include this file. */
#include <_mingw.h>

#ifndef RC_INVOKED

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef NDEBUG

/*
 * If not debugging, assert does nothing.
 */
#define assert(x)	((void)0)

#else /* debugging enabled */

/*
 * CRTDLL nicely supplies a function which does the actual output and
 * call to abort.
 */
_CRTIMP void __cdecl _assert (const char*, const char*, int)
#ifdef	__GNUC__
	__attribute__ ((noreturn))
#endif
	;

/*
 * Definition of the assert macro.
 */
#define assert(e)       ((e) ? (void)0 : _assert(#e, __FILE__, __LINE__))
#endif	/* NDEBUG */

#ifdef	__cplusplus
}
#endif

#endif /* Not RC_INVOKED */

#endif /* Not _ASSERT_H_ */


using namespace std;

class Width
{
	// 请补充
public:
	static int count;
	Width(){++count;}
	~Width(){--count;}
};
int Width::count=0;

	int main()
	{  
		Width w, x;
		cout << "#objects = " << w.count << endl;
		{ 
			Width w, x, y, z;
			cout << "#objects = " << w.count << endl;
		}
		cout << "#objects = " << w.count << endl;

		Width y;
		cout << "#objects = " << w.count << endl;

		return 0;
	}
