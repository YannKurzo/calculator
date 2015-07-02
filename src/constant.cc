
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
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <exception>

using namespace std;

const string userVariable("User variable");

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
    stringstream flow;
    flow << setiosflags(ios::left);
    
    for(constantMapIterator_t it = constants_m.begin(); it != constants_m.end(); ++it)
    {
        if(it->second.help != userVariable)
        {
            flow << "  " << setw(8) << it->first << " " << it->second.help + " (" + to_string(it->second.value).substr(0, 15) + ")\n";
        }
    }
    
    return flow.str();
}

std::string Constant::getVariableList(void)
{
    stringstream flow;
    flow << setiosflags(ios::left);
    
    for(constantMapIterator_t it = constants_m.begin(); it != constants_m.end(); ++it)
    {
        if(it->second.help == userVariable)
        {
            flow << "  " << setw(8) << it->first << " " << it->second.help + " (" + to_string(it->second.value).substr(0, 15) + ")\n";
        }
    }
    
    return flow.str();
}

bool Constant::addVariable(std::string variableName, calculType_t value)
{
    bool ret = true;
    
#if(USE_DOUBLE_TYPE == 1)
    constants_m.insert(ADD_CONSTANT(variableName, value, to_string(value), userVariable));
#elif(USE_MPFR_LIBRARY == 1)
    constants_m.insert(ADD_CONSTANT(variableName, 0., to_string(value), userVariable));
#endif
    
    // Re-set if it was already defined (only for user variables))
    if(constants_m[variableName].help == userVariable)
    {
        constants_m.erase(variableName);
#if(USE_DOUBLE_TYPE == 1)
        constants_m.insert(ADD_CONSTANT(variableName, value, to_string(value), userVariable));
#elif(USE_MPFR_LIBRARY == 1)
        constants_m.insert(ADD_CONSTANT(variableName, 0., to_string(value), userVariable));
#endif
    }
    else
    {
        // Constant was not set
        ret = false;
    }
    
    return ret;
}

bool Constant::isValidVariableName(std::string variableName)
{
    // Check size
    if(variableName.size() == 0)
        return false;
    
    // Check first character
    if(!(isalpha(variableName.at(0)) || variableName.at(0) == '_'))
        return false;
    
    // Check other characters
    for(unsigned int i=1;i<variableName.size();++i)
    {
        if(!(isalnum(variableName.at(i)) || variableName.at(i) == '_'))
            return false;
    }
    
    return true;
}