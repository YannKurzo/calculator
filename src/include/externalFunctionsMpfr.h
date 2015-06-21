
//  ==========================================================================
/// @file   externalFunctionsMpfr.h
/// @author Yann Kurzo
/// @date   May 28, 2015, 11:48 PM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  New function to be handled by the calculator can be declared here.
//  ==========================================================================

#ifndef EXTERNALFUNCTIONSMPFR_H
#define	EXTERNALFUNCTIONSMPFR_H

#include "config.h"

#if(USE_MPFR_LIBRARY == 1)

#include <mpfr.h>

/// @brief  Get pi (3.1415...)
/// @return 3.1315...
void pi(mpfr_t n);

/// @brief  Get INFINITY
/// @return INFINITY
void inf(mpfr_t n);

#endif


#endif	/* EXTERNALFUNCTIONSMPFR_H */

