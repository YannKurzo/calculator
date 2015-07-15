
//  ==========================================================================
/// @file   constant.cc
/// @author Yann Kurzo
/// @date   May 26, 2015, 9:30 PM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  This file defines the Constant class.
//  ==========================================================================

#include "constant.h"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <exception>
#include <vector>

using namespace std;

const string cUserVariable("User variable");

calculType_t Constant::getConstant(const std::string &str)
{
#if(USE_DOUBLE_TYPE == 1)
    return constants_m[str].value;
#elif(USE_MPFR_LIBRARY == 1)
    if(constants_m[str].strValue == "")
    {
        return constants_m[str].value;
    }
    else
    {
        return calculType_t(constants_m[str].strValue);
    }
#endif
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

std::string Constant::getList(bool variableList)
{
    stringstream flow;
    flow.precision(15);
    flow << setiosflags(ios::left);
    
#if(USE_MPFR_LIBRARY == 1)
    bool displayModeOld = MPFR::getDisplayMode();
    MPFR::setDisplayMode(true);
#endif /* USE_MPFR_LIBRARY */
    
    for(constantMapIterator_t it = constants_m.begin(); it != constants_m.end(); ++it)
    {
        if((it->second.help == cUserVariable && variableList) || (it->second.help != cUserVariable && !variableList))
        {
            flow << "  " << setw(8) << it->first << " " << it->second.help << " (" << it->second.value << ")\n";
        }
    }
    
#if(USE_MPFR_LIBRARY == 1)
    MPFR::setDisplayMode(displayModeOld);
#endif /* USE_MPFR_LIBRARY */
    
    return flow.str();
}

std::string Constant::getConstantList(void)
{
    return getList(false);
}

std::string Constant::getVariableList(void)
{
    string str = getList(true);
    if(str == "")
    {
        str = "No user defined variables!";
    }
    return str;
}

bool Constant::addVariable(const std::string &variableName, calculType_t value)
{
    bool ret = true;
    
    if(exist(variableName))
    {
        if(constants_m[variableName].help == cUserVariable)
        {
            constants_m.erase(variableName);
            constants_m.insert(ADD_USER(variableName, value, cUserVariable));
        }
        else
        {
            // Constant was not set
            ret = false;
        }
    }
    else
    {
        constants_m.insert(ADD_USER(variableName, value, cUserVariable));
    }
    
    return ret;
}

bool Constant::clearVariable(std::string variableName)
{
    if(exist(variableName) && constants_m[variableName].help == cUserVariable)
    {
        constants_m.erase(variableName);
        return true;
    }
    else
    {
        return false;
    }
}

bool Constant::clearAll(void)
{
    vector<string> variableNames;
    for(constantMapIterator_t it = constants_m.begin(); it != constants_m.end(); ++it)
    {
        if(it->second.help == cUserVariable)
        {
            variableNames.push_back(it->first);
        }
    }
    for(unsigned int i=0;i<variableNames.size();++i)
    {
        constants_m.erase(variableNames.at(i));
    }
    if(variableNames.size() > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
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