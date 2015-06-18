
//  ==========================================================================
/// @file   function.cc
/// @author Yann Kurzo
/// @date   May 26, 2015, 9:30 PM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  This file defines the Function class.
//  ==========================================================================

#include "function.h"

#include <iostream>
#include <cstdlib>
#include <exception>

using namespace std;

unsigned int Function::getNbParameters(const std::string &str)
{
    return functions_m[str].nbParameters;
}

func_ptr Function::getFunction(const std::string &str)
{
    return functions_m[str].func_p;
}

std::string Function::getFunctionList(void)
{
    string str("");
    
    for(functionMapIterator_t it = functions_m.begin(); it != functions_m.end(); ++it)
    {
        // Begin
        str = str + "  " + it->first + "(";
        
        // Parameters
        if(it->second.nbParameters > 0)
        {
            // 1st
            str = str + "a";
            // Others
            for(unsigned int i=1; i<it->second.nbParameters; ++i)
            {
                str = str + "," + string(1, 'a' + i);
            }
        }
        
        // End
        str = str + ") : " + it->second.help + "\n";
    }
    
    return str;
}

#if(USE_MPFR_LIBRARY == 1)
int call0(std::string str, mpfr_t res)
{
    return reinterpret_cast<int(*)(mpfr_t, mpfr_rnd_t)>
            (Function::getFunction(str))(res, getRoundingMethod());
}

int call1(std::string str, mpfr_t res, mpfr_t op0)
{
    return reinterpret_cast<int(*)(mpfr_t, mpfr_t, mpfr_rnd_t)>
            (Function::getFunction(str))(res, op0, getRoundingMethod());
}

int call2(std::string str, mpfr_t res, mpfr_t op0, mpfr_t op1)
{
    return reinterpret_cast<int(*)(mpfr_t, mpfr_t, mpfr_t, mpfr_rnd_t)>
            (Function::getFunction(str))(res, op0, op1, getRoundingMethod());
}

int call3(std::string str, mpfr_t res, mpfr_t op0, mpfr_t op1, mpfr_t op2)
{
    return reinterpret_cast<int(*)(mpfr_t, mpfr_t, mpfr_t, mpfr_t, mpfr_rnd_t)>
            (Function::getFunction(str))(res, op0, op1, op2, getRoundingMethod());
}
#endif