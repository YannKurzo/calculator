# ------------------------------------------------
# Init
# ------------------------------------------------

AC_INIT([calculator], [1.0], [bug-automake@gnu.org])
AM_INIT_AUTOMAKE(
    [-Wall -Werror foreign]
)
AC_PROG_CXX
AC_LANG(C++)
AC_CONFIG_HEADERS(
    [autoConfig.h]
)
AC_CONFIG_FILES(
    [Makefile
    src/Makefile]
)

# ------------------------------------------------
# Check for header files for getch
# ------------------------------------------------

AC_CHECK_HEADERS(
    [conio.h],
    [ AC_DEFINE([ HAVE_CONIO ], [ 1 ]) ],
    [ AC_DEFINE([ HAVE_CONIO ], [ 0 ]) ]
)

AC_CHECK_HEADERS(
    [sys/ioctl.h],
    [ AC_DEFINE([ HAVE_IOCTL ], [ 1 ]) ],
    [ AC_DEFINE([ HAVE_IOCTL ], [ 0 ]) ]
)

# ------------------------------------------------
# Check if mpfr library is installed
# ------------------------------------------------

AC_SEARCH_LIBS(
    [mpfr_init],
    [mpfr],
    [ mpfrInstalled=true; ],
    [ mpfrInstalled=false; ]
)
# Pass to Makefile.am
AM_CONDITIONAL([MPFRINSTALLED], [test x$mpfrInstalled = xtrue])
     
# ------------------------------------------------
# Output
# ------------------------------------------------

AC_OUTPUT

# Show warning if mpfr is not installed
if test $mpfrInstalled = false; then
    AC_MSG_WARN([
    The mpfr library is not installed!
    Either:
      - Install the mpfr library and rerun configure, or 
      - Set the right configuration to compile without mpfr library 
        in the src/include/config.h file!
        (see README.md in compilation section for more information)
    ])
fi
