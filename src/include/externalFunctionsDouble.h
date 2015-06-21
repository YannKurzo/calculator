
//  ==========================================================================
/// @file   externalFunctionsDouble.h
/// @author Yann Kurzo
/// @date   May 28, 2015, 11:48 PM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  New function to be handled by the calculator can be declared here.
/// @note   This file defines the double version.
//  ==========================================================================

#ifndef EXTERNALFUNCTIONSDOUBLE_H
#define	EXTERNALFUNCTIONSDOUBLE_H

#include "config.h"

#if(USE_DOUBLE_TYPE == 1)

/// @brief  Get pi (3.1415...)
/// @return 3.1315...
double pi(void);

/// @brief  Get INFINITY
/// @return INFINITY
double inf(void);

#endif  /* USE_DOUBLE_TYPE */

#endif	/* EXTERNALFUNCTIONSDOUBLE_H */

