
//  ==========================================================================
/// @file   constant.h
/// @author Yann Kurzo
/// @date   May 26, 2015, 9:30 PM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  This file defines the Constant class.
//  ==========================================================================

#ifndef CONSTANT_H
#define	CONSTANT_H

#include "mpfrInterface.h"

#include <string>
#include <cstdlib>
#include <map>

/// @brief  Macro to easily add a new constant
/// @param  str Name of the constant used by the user
/// @param  doubleValue Value as double
/// @param  mpfrValue Value as string
/// @param  help Help notice for this function
#if(USE_DOUBLE_TYPE == 1)
#define ADD_CONSTANT(str, doubleValue, mpfrValue, help) {str, {doubleValue, help}}
#elif(USE_MPFR_LIBRARY == 1)
#define ADD_CONSTANT(str, doubleValue, mpfrValue, help) {str, {mpfrValue, help}}
#endif

/// @brief  Structure to hold a constant
typedef struct
{
#if(USE_DOUBLE_TYPE == 1)
    double value;       ///< 
#elif(USE_MPFR_LIBRARY == 1)
    std::string value;       ///< 
#endif
    std::string help;           ///< Help notice
}constant_t;

/// @brief  Map to store the constants
typedef std::map<std::string,constant_t> constantMap_t;

/// @brief  Iterator on functionMap_t
typedef constantMap_t::iterator constantMapIterator_t;

/// @brief  Map to store every function
/// @note   The function is stored in a map to be able to find which function
///         should be called depending on its name.
static constantMap_t constants_m = 
{
    // Physical constants
    ADD_CONSTANT("c"    , 299792458., "299792458",   "Speed of light in vacuum")
};

/// @brief  This class is used to handle constants.
/// @note   New constants can be easily added with the ADD_CONSTANT macro.
class Constant
{
    public:
        
        /// @brief  Get a constant
        /// @param  str Name of the constant
        /// @return Value of the constant
#if(USE_DOUBLE_TYPE == 1)
        static double getConstant(const std::string &str);
#elif(USE_MPFR_LIBRARY == 1)
        static std::string getConstant(const std::string &str);
#endif
        
        /// @brief  Get a string containing the list of implemented constants
        /// @return Constants list
        static std::string getConstantList(void);
};


#endif	/* CONSTANT_H */

