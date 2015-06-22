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
    [config.h]
)
AC_CONFIG_FILES(
    [Makefile
    src/Makefile]
)

# ------------------------------------------------
# Check if mpfr library is installed
# ------------------------------------------------

AC_SEARCH_LIBS(
    [mpfr_init],
    [mpfr],
    [AC_MSG_RESULT([yes])],
    [AC_MSG_WARN([
    The mpfr library is not installed!
    Check the src/include/config.h file to set the right configuration to compile without mpfr library!
    ])]
)

#AC_COMPILE_IFELSE(
#    [AC_LANG_SOURCE(
#        [[
#        #include "../calculator/src/include/config.h"
#        
#        #if(USE_MPFR_LIBRARY != 1)
#          #error Using double library
#        #endif
#        ]]
#        )
#    ],              
#    AC_SEARCH_LIBS(
#        [mpfr_init],
#        [mpfr],
#        [AC_MSG_NOTICE([Using mpfr library for calculation])],
#        [AC_MSG_ERROR([You need the mpfr library to compile with this configuration. 
#            Check the src/include/config.h file to modify the configuration!])]
#    ),
#    [AC_MSG_NOTICE([Using double for calculation])]
#)
     
# ------------------------------------------------
# Output
# ------------------------------------------------

AC_OUTPUT
