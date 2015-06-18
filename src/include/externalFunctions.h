
//  ==========================================================================
/// @file   externalFunctions.h
/// @author Yann Kurzo
/// @date   May 28, 2015, 11:48 PM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  New function to be handled by the calculator can be declared here.
//  ==========================================================================

#ifndef EXTERNALFUNCTIONS_H
#define	EXTERNALFUNCTIONS_H

#include "mpfrInterface.h"

/// @brief  Get pi (3.1415...)
/// @return 3.1315...
calculType_t pi(calculType_t res);

/// @brief  Get NAN
/// @return NAN
calculType_t NaN(void);

/// @brief  Get INFINITY
/// @return INFINITY
calculType_t inf(void);


#endif	/* EXTERNALFUNCTIONS_H */

