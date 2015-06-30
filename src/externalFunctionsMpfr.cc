
//  ==========================================================================
/// @file   externalFunctionsMpfr.cc
/// @author Yann Kurzo
/// @date   May 28, 2015, 11:48 PM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  New function to be handled by the calculator can be declared here.
/// @note   This file defines the mpfr version.
//  ==========================================================================

#include "externalFunctionsMpfr.h"

#if(USE_MPFR_LIBRARY == 1)
    
#include "constant.h"

#include <cmath>
#include <string>

using namespace std;

void pi(mpfr_t n)
{
    mpfr_set_str(n, Constant::getConstant("pi").c_str(), 10, MPFR_RNDN);
}

void inf(mpfr_t n)
{
    mpfr_set_inf(n, 1);
}

#endif  /* USE_MPFR_LIBRARY */