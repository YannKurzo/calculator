
//  ==================================================
/// @file   function.h
/// @author Yann Kurzo
/// @date   May 26, 2015, 9:30 PM
/// @license GPL2
/// @brief  Handle existing functions of libraries
/// @note   New functions can be easily added with the ADD macro.
//  ==================================================

#ifndef FUNCTION_H
#define	FUNCTION_H

#include "externalFunctions.h"

#include <string>
#include <cmath>
#include <map>

#define MAX_NUMBER_PARAMETERS 5

typedef void (*func_ptr)();

#define ADD(str, nbParameters, functionName) {str, {nbParameters, reinterpret_cast<func_ptr>(&functionName)}}


typedef struct
{
    unsigned int nbParameters;
    func_ptr func;
    
}function_t;

static std::map<std::string,function_t> functions_m = 
{
    ADD("pow"   , 2, pow),
    ADD("ln"    , 1, log),
    ADD("pi"    , 0, pi)
};

class Function
{
    private:
        
    public:
        static unsigned int getNbParameters(std::string str);
        static func_ptr getFunction(std::string str);
};

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


#endif	/* FUNCTION_H */

