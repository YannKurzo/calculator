
//  ==========================================================================
/// @file   function.cc
/// @author Yann Kurzo
/// @date   May 26, 2015, 9:30 PM
/// @license GPL2
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
    return functions_m[str].func;
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
