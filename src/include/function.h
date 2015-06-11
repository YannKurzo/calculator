
//  ==========================================================================
/// @file   function.h
/// @author Yann Kurzo
/// @date   May 26, 2015, 9:30 PM
/// @license GPL2
/// @brief  Handle existing functions of libraries
/// @note   New functions can be easily added with the ADD macro.
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
#define ADD(str, nbParameters, functionName) {str, {nbParameters, reinterpret_cast<func_ptr>(&functionName)}}


/// @brief  Function structure
///         Each function must tell its number of parameters
typedef struct
{
    unsigned int nbParameters;
    func_ptr func;
}function_t;

/// @brief  Map to store every function
/// @note   The function is stored in a map to be able to find which function
///         should be called depending on its name.
static std::map<std::string,function_t> functions_m = 
{
    ADD("pow"   , 2, pow),
    ADD("ln"    , 1, log),
    ADD("pi"    , 0, pi)
};

/// @brief  Class to get the actual function if it exists
class Function
{
    private:
        
    public:
        /// @brief  Get the number of parameters of the function
        /// @param  str Name of the function
        /// @return Number of parameters of the function
        static unsigned int getNbParameters(std::string str);
        
        /// @brief  Get a pointer on the function to call
        /// @param  str Name of the function
        /// @return Pointer to the function, NULL if it does not exist
        static func_ptr getFunction(std::string str);
};

/// @cond   Template based code / not on doxygen
// Specific call (return double)
template<class... Ts>
double call(std::string str, const Ts&... args)
{
    return reinterpret_cast<double(*)(Ts...)>(Function::getFunction(str))(args...);
}

// Generic call
//template<class ReturnType, class... Ts>
//ReturnType callFunction(void *function, const Ts&... args)
//{	
//    return reinterpret_cast<ReturnType(*)(Ts...)>(function)(args...);
//}
/// @cond


#endif	/* FUNCTION_H */

