
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

constantType_t Constant::getConstant(const std::string &str)
{
    return constants_m[str].value;
}

std::string Constant::getConstantList(void)
{
    string str("");
    
    for(constantMapIterator_t it = constants_m.begin(); it != constants_m.end(); ++it)
    {
        // Begin
        str = str + "  " + it->first + " : ";
        
        // End
        str = str + it->second.help + " (" + to_string(it->second.value) + ")\n";
    }
    
    return str;
}
