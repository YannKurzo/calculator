
//  ==========================================================================
/// @file   externalFunctions.cc
/// @author Yann Kurzo
/// @date   May 28, 2015, 11:48 PM
/// @license GPL2
/// @brief  New function to be handled by the calculator can be declared here.
//  ==========================================================================

#include "externalFunctions.h"

#include <cmath>

double pi(void)
{
    return 3.14159265359;
}

double NaN(void)
{
    return NAN;
}

double inf(void)
{
    return INFINITY;
}