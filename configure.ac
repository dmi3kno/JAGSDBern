dnl Process this file with Autoconf to produce a configure script

AC_PREPREQ([2.68])

AC_INIT([JAGS-BERN], [1.1], [dperepolkin@gmail.com], [JAGS-BERN-MODULE])

JAGS_MAJOR=4
JAGS_MINOR=3
JAGS_PATCH=0

AC_SUBST(JAGS_MAJOR)
AC_SUBST(JAGS_MINOR)

AC_CANONICAL_HOST

dnl the following files check if the required files exist
AC_CONFIG_SRCDIR([src/distributions/DBern.cc])
AC_CONFIG_SRCDIR([src/functions/LogBernFun.cc])
AC_CONFIG_MACRO_DIR([m4])

dnl The configure process creates a header file called config.h. Added the subdir-objects
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([subdir-objects])

dnl libtool and ltdl configuration
LT_PREREQ(2.2.6)
LT_CONFIG_LTDL_DIR([libltdl])
LT_INIT([dlopen disable-static win32-dll])
LTDL_INIT([recursive])

dnl Indicate C++
AC_PROG_CXX

dnl Optionally, reference the Rmath library
AC_DEFINE(MATHLIB_STANDALONE, 1, [Define if you have standalone R math library])

case "${host_os}" in
  mingw*)
    win=true ;;
  *)
    win=false ;;
esac
AM_CONDITIONAL(WINDOWS, text x$win = xtrue)

jagsmoddir=${libdir}/JAGS/modules-${JAGS_MAJOR}
AC_SUBST(jagsmoddir)

AC_CONFIG_FILES([
   Makefile
   libltdl/Makefile
   src/Makefile
   src/distributions/Makefile
   src/functions/Makefile
])
AC_OUTPUT
