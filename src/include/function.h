
//  ==========================================================================
/// @file   function.h
/// @author Yann Kurzo
/// @date   May 26, 2015, 9:30 PM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  This file defines the Function class.
//  ==========================================================================

#ifndef FUNCTION_H
#define	FUNCTION_H

#include "mpfrInterface.h"

#if(USE_DOUBLE_TYPE == 1)
#include "externalFunctionsDouble.h"
#elif(USE_MPFR_LIBRARY == 1)
#include "externalFunctionsMpfr.h"
#endif

#include <string>
#include <cmath>
#include <map>

/// @brief  Function pointer for every function
typedef void (*func_ptr)();

/// @brief  Macro to easily add a new function
/// @param  str Name of the function used by the user
/// @param  nbParameters Number of parameters of the function
/// @param  functionName Name of the function in the library or declared in externalFunctions.h
/// @param  help Help notice for this function
#if(USE_DOUBLE_TYPE == 1)
#define ADD(str, nbParameters, functionName, help) {str, {nbParameters, reinterpret_cast<func_ptr>(&functionName), help}}
#elif(USE_MPFR_LIBRARY == 1)
#define ADD(str, nbParameters, functionName, help) {str, {nbParameters, reinterpret_cast<func_ptr>(&mpfr_##functionName), help}}
#endif

#define ADDSAMENAME(str, nbParameters, functionName, help) {str, {nbParameters, reinterpret_cast<func_ptr>(&functionName), help}}


/// @brief  Structure to hold a function
typedef struct
{
    unsigned int nbParameters;  ///< Number of parameters
    func_ptr func_p;            ///< Pointer to the function
    std::string help;           ///< Help notice
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
    
    // Other functions
    ADD("abs"   , 1, fabs,  "Compute absolute value"),
    
    // Defined in externalFunctions.h
    ADDSAMENAME("pi"    , 0, pi,    "Return pi"),
    ADDSAMENAME("inf"   , 0, inf,   "Return INFINITY")
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

#if(USE_DOUBLE_TYPE == 1)

/// @cond TEMPLATE_CODE
template<class... Ts>
double call(std::string str, const Ts&... args)
{
    return reinterpret_cast<double(*)(Ts...)>(Function::getFunction(str))(args...);
}
/// @endcond TEMPLATE_CODEEXTERNALFUNCTIONS_H

#elif(USE_MPFR_LIBRARY == 1)

    // Result with MAX_NUMBER_PARAMETERS = 3
#if(MAX_NUMBER_PARAMETERS != 3)
	#error "Adapt the code here!"
#endif

int call(std::string str, mpfr_t res);
int call(std::string str, mpfr_t res, mpfr_t op0);
int call(std::string str, mpfr_t res, mpfr_t op0, mpfr_t op1);
int call(std::string str, mpfr_t res, mpfr_t op0, mpfr_t op1, mpfr_t op2);

#endif


#endif	/* FUNCTION_H */

