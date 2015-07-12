
//  ==================================================================
/// @file   config.h
/// @author Yann Kurzo
/// @date   June 17, 2015, 8:32 PM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  This file contains all the possible configurations.
//  ==================================================================

#ifndef CONFIG_H
#define	CONFIG_H

/// @brief  Use double to make calculations when defined to 1
/// @note   When defined to 1, USE_MPFR_LIBRARY must be defined to 0
#define USE_DOUBLE_TYPE         1

/// @brief  Use MPFR library to make calculations when defined to 1
/// @note   When defined to 1, USE_DOUBLE_TYPE must be defined to 0
#define USE_MPFR_LIBRARY        0

//  ==================================================================

/// @brief  Defined to 1 to display the operation steps
#define DISPLAY_OPERATIONS      0

/// @brief  Maximum number of parameters for the functions
/// @note   When it is changed, other parts of the code must be adapted.
#define MAX_NUMBER_PARAMETERS   3

/// @brief  Define to 1 to show the vector of tokens after the lexer process
#define ANALYSE_DEBUG           0

//  ==================================================================

// Check library configuration
#if(USE_DOUBLE_TYPE == 1 && USE_MPFR_LIBRARY == 1)
    #error "Choose either double or mpfr types!"
#elif(USE_DOUBLE_TYPE == 0 && USE_MPFR_LIBRARY == 0)
    #error "Choose either double or mpfr types!"
#endif

#endif	/* CONFIG_H */
