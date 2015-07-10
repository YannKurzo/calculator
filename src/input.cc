
//  ==========================================================================
/// @file   input.cc
/// @author Yann Kurzo
/// @date   July 10, 2015, 2:06 AM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  This file defines the Input class.
//  ==========================================================================

#include "input.h"
#include "iostream"

using namespace std;

Input::Input(void)
{
    
}

void Input::getInput(std::string &str)
{
    str = "";
    
    cin >> str;
    
    // while(str.find("\n") == string::npos)
    // {
        // str += getchar();
        // // Check for arrow
        // string checkArrow = "";
        // if(getArrow(checkArrow) == ARROW_UP)
        // {
            // checkArrow = history_m.at(history_m.size()-1);
            // cout << checkArrow;
        // }
        
        // // Get new line
        // cin >> str;
        // str = checkArrow + str;
        
    // }
    // Update history
    history_m.push_back(str);
    
    // Check history size
}