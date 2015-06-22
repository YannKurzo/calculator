
//  ==========================================================================
/// @file   externalFunctionsDouble.cc
/// @author Yann Kurzo
/// @date   May 28, 2015, 11:48 PM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  New function to be handled by the calculator can be declared here.
/// @note   This file defines the double version.
//  ==========================================================================

#include "externalFunctionsDouble.h"

#if(USE_DOUBLE_TYPE == 1)

#include <cmath>

double pi(void)
{
    return 3.14159265358979323;
}

double inf(void)
{
    return INFINITY;
}

#endif  /* USE_DOUBLE_TYPE */