
//  ==========================================================================
/// @file   function.h
/// @author Yann Kurzo
/// @date   May 26, 2015, 9:30 PM
/// @license GPL2
/// @brief  This file defines the Function class.
//  ==========================================================================

#ifndef FUNCTION_H
#define	FUNCTION_H

#include "externalFunctions.h"

#include <string>
#include <cmath>
#include <map>

/// @brief  Function pointer for every function
typedef void (*func_ptr)();

/// @brief  Macro to easily add a new function
/// @param  str Name of the function used by the user
/// @param  str Number of parameters of the function
/// @param  functionName Name of the function in the library or declared in externalFunctions.h
/// @param  help Help notice for this function
#define ADD(str, nbParameters, functionName, help) {str, {nbParameters, reinterpret_cast<func_ptr>(&functionName), help}}

/// @brief  Function structure
///         Each function defines its number of parameters and a help notice
typedef struct
{
    unsigned int nbParameters;
    func_ptr func;
    std::string help;
}function_t;

/// @brief  Map to store the functions
typedef std::map<std::string,function_t> functionMap_t;

/// @brief  Iterator on functionMap_t
typedef functionMap_t::iterator functionMapIterator_t;

/// @brief  Map to store every function
/// @note   The function is stored in a map to be able to find which function
///         should be called depending on its name.
static functionMap_t functions_m = 
{
    // Trigonometric functions
    ADD("cos"   , 1, cos,   "Compute cosine"),
    ADD("sin"   , 1, sin,   "Compute sine"),
    ADD("tan"   , 1, tan,   "Compute tangent"),
    ADD("acos"  , 1, acos,  "Compute arc cosine"),
    ADD("asin"  , 1, asin,  "Compute arc sine"),
    ADD("atan"  , 1, atan,  "Compute arc tangent"),
    
    // Hyperbolic functions
    ADD("cosh"  , 1, cosh,  "Compute hyperbolic cosine"),
    ADD("sinh"  , 1, sinh,  "Compute hyperbolic sine"),
    ADD("tanh"  , 1, tanh,  "Compute hyperbolic tangent"),
    ADD("acosh" , 1, acosh, "Compute arc hyperbolic cosine"),
    ADD("asinh" , 1, asinh, "Compute arc hyperbolic sine"),
    ADD("atanh" , 1, atanh, "Compute arc hyperbolic tangent"),
    
    // Exponential and logarithmic functions
    ADD("exp"   , 1, exp,   "Compute exponential function"),
    ADD("log"   , 1, log,   "Compute natural logarithm"),
    ADD("log10" , 1, log10, "Compute common logarithm"),
    ADD("log2"  , 1, log2,  "Compute binary logarithm"),
    
    // Power functions
    ADD("pow"   , 2, pow,   "Raise to power"),
    ADD("sqrt"  , 1, sqrt,  "Compute square root"),
    ADD("cbrt"  , 1, cbrt,  "Compute cubic root"),
    ADD("hypot" , 2, hypot, "Compute hypotenuse"),
    
    // Rounding and remainder functions
    ADD("ceil"  , 1, ceil,  "Round up value"),
    ADD("floor" , 1, floor, "Round down value"),
    ADD("fmod"  , 2, fmod,  "Compute remainder of division"),
    ADD("trunc" , 1, trunc, "Truncate value"),
    ADD("round" , 1, round, "Round to nearest"),
    
    // Maximum, minimum, difference functions
    ADD("fdim"  , 2, fdim,  "Positive difference"),
    ADD("fmax"  , 2, fmax,  "Maximum value"),
    ADD("fmin"  , 2, fmin,  "Minimum value"),
    
    // Other functions
    ADD("abs"   , 1, abs,   "Compute absolute value"),
    
    // Defined in externalFunctions.h
    ADD("pi"    , 0, pi,    "Return pi"),
    ADD("NaN"   , 0, NaN,   "Return NAN"),
    ADD("inf"   , 0, inf,   "Return INFINITY")
};

/// @brief  This class is used to handle library or user defined functions.
/// @note   New functions can be easily added with the ADD macro.
class Function
{
    public:
        /// @brief  Get the number of parameters of the function
        /// @param  str Name of the function
        /// @return Number of parameters of the function
        static unsigned int getNbParameters(const std::string &str);
        
        /// @brief  Get a pointer on the function to call
        /// @param  str Name of the function
        /// @return Pointer to the function, NULL if it does not exist
        static func_ptr getFunction(const std::string &str);
        
        /// @brief  Get a string containing the list of implemented functions
        /// @return Function list
        static std::string getFunctionList(void);
};

/// @brief  Specific call of an implemented function (return double)
/// @param  str Name of the function
/// @param  args Variable number of different types of arguments (generally double)
/// @return Result of the function
template<class... Ts>
double call(std::string str, const Ts&... args)
{
    return reinterpret_cast<double(*)(Ts...)>(Function::getFunction(str))(args...);
}

/// @cond   Template based code / not on doxygen
// Generic call
template<class ReturnType, class... Ts>
ReturnType callFunction(void *function, const Ts&... args)
{	
   return reinterpret_cast<ReturnType(*)(Ts...)>(function)(args...);
}
/// @endcond


#endif	/* FUNCTION_H */

