
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
/// @param  help Help notice for this constant
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

/// @brief  Iterator on constantMap_t
typedef constantMap_t::iterator constantMapIterator_t;

/// @brief  Map to store every constant
/// @note   The constant is stored in a map to be able to find which constant
///         should be called depending on its name.
static constantMap_t constants_m = 
{
    // Physical constants
    ADD_CONSTANT("c"    , 299792458.,       "299792458",        "Speed of light in vacuum"),
    ADD_CONSTANT("G"    , 6.67384e-7,       "6.67384e-7",       "Gravitational constant"),
    ADD_CONSTANT("e"    , 1.602176565e-19,  "1.602176565e-19",  "Elementary charge"),
    ADD_CONSTANT("NA"   , 6.02214129e23,    "6.02214129e23",    "Avogadro's constant"),
    ADD_CONSTANT("k"    , 1.3806488e23,     "1.3806488e23",     "Boltmann's constant"),
    ADD_CONSTANT("R"    , 8.3144621.,       "8.3144621",        "Gas constant"),
    ADD_CONSTANT("g"    , 9.80665.,         "9.80665",          "Standard gravity"),
    
    // Mathematical constants
    ADD_CONSTANT("pi"   , 3.14159265358979323.,
        "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679"
        "8214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196"
        "4428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273",
        "Speed of light in vacuum")
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

        /// @brief  Check if a constant exists
        /// @return true if it exists, false otherwise
        static bool exist(const std::string &str);
        
        /// @brief  Get a string containing the list of implemented constants
        /// @return Constants list
        static std::string getConstantList(void);
};


#endif	/* CONSTANT_H */

