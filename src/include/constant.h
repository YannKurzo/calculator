
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
    double value;               ///< Value in double format
#elif(USE_MPFR_LIBRARY == 1)
    std::string value;          ///< Value in string format
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
    ADD_CONSTANT("c"    , 299792458.,       "299792458",        "Speed of light in vacuum [m/s]"),
    ADD_CONSTANT("G"    , 6.67384e-7,       "6.67384e-7",       "Gravitational constant [N m²/kg²]"),
    // ADD_CONSTANT("e"    , 1.602176565e-19,  "1.602176565e-19",  "Elementary charge"),
    ADD_CONSTANT("NA"   , 6.02214129e23,    "6.02214129e23",    "Avogadro's constant [1/mol]"),
    ADD_CONSTANT("k"    , 1.3806488e23,     "1.3806488e23",     "Boltmann's constant [J/K]"),
    ADD_CONSTANT("R"    , 8.3144621.,       "8.3144621",        "Gas constant [J/mol K]"),
    ADD_CONSTANT("g"    , 9.80665.,         "9.80665",          "Standard gravity [m/s²]"),
    
    // Mathematical constants
    ADD_CONSTANT("pi"   , 3.14159265358979323,
        "3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706"
        "7982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930381"
        "9644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412",
        "pi"),
    ADD_CONSTANT("e"   , 2.718281828459045235,
        "2.71828182845904523536028747135266249775724709369995957496696762772407663035354759457138217852516642"
        "7427466391932003059921817413596629043572900334295260595630738132328627943490763233829880753195251019"
        "0115738341879307021540891499348841675092447614606680822648001684774118537423454424371075390777449921",
        "Euler's number"),
    ADD_CONSTANT("phi" , 1.618033988749894848,
        "1.61803398874989484820458683436563811772030917980576286213544862270526046281890244970720720418939113"
        "7484754088075386891752126633862223536931793180060766726354433389086595939582905638322661319928290267"
        "8806752087668925017116962070322210432162695486262963136144381497587012203408058879544547492461856954",
        "Golden ratio")
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

