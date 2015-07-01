
//  ==========================================================================
/// @file   constant.cc
/// @author Yann Kurzo
/// @date   May 26, 2015, 9:30 PM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  This file defines the Constant class.
//  ==========================================================================

#include "constant.h"
#include "util.h"

#include <iostream>
#include <cstdlib>
#include <exception>

using namespace std;

#if(USE_DOUBLE_TYPE == 1)
double Constant::getConstant(const std::string &str)
#elif(USE_MPFR_LIBRARY == 1)
std::string Constant::getConstant(const std::string &str)
#endif
{
    return constants_m[str].value;
}

bool Constant::exist(const std::string &str)
{
    bool exist = (constants_m[str].help != "");
    
    if(!exist)
    {
        constants_m.erase(str);
    }
    
    return exist;
}

std::string Constant::getConstantList(void)
{
    string str("");
    
    for(constantMapIterator_t it = constants_m.begin(); it != constants_m.end(); ++it)
    {
        // Begin
        str = str + "  " + it->first + " : ";
        
        // End
        str = str + it->second.help + " (" + to_string(it->second.value).substr(0, 15) + ")\n";
    }
    
    return str;
}

bool Constant::addConstant(std::string constantName, calculType_t value)
{
    bool ret = true;
    
#if(USE_DOUBLE_TYPE == 1)
    constants_m.insert(ADD_CONSTANT(constantName, value, to_string(value), "User constant"));
#elif(USE_MPFR_LIBRARY == 1)
    constants_m.insert(ADD_CONSTANT(constantName, 0., to_string(value), "User constant"));
#endif
    
    // Re-set if it was already defined (only for user constants))
    if(constants_m[constantName].help == "User constant")
    {
        constants_m.erase(constantName);
#if(USE_DOUBLE_TYPE == 1)
        constants_m.insert(ADD_CONSTANT(constantName, value, to_string(value), "User constant"));
#elif(USE_MPFR_LIBRARY == 1)
        constants_m.insert(ADD_CONSTANT(constantName, 0., to_string(value), "User constant"));
#endif
    }
    else
    {
        // Constant was not set
        ret = false;
    }
    
    return ret;
}