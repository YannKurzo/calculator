
//  ==========================================================================
/// @file   externalFunctions.cc
/// @author Yann Kurzo
/// @date   May 28, 2015, 11:48 PM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  New function to be handled by the calculator can be declared here.
//  ==========================================================================

#include "externalFunctions.h"

#include <cmath>

calculType_t pi(calculType_t res)
{
#if(USE_DOUBLE_TYPE == 1)
    res = calculType_t(3.14159265358979323);
#elif(USE_MPFR_LIBRARY == 1)
    res.n_m = calculType_t(
            "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679"
            "8214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196"
            "4428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273");
#endif
    return res;
}

calculType_t NaN(void)
{
    calculType_t res = NAN;
    return res;
}

calculType_t inf(void)
{
    calculType_t res = INFINITY;
    return res;
}