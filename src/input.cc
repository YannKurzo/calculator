
//  ==========================================================================
/// @file   input.cc
/// @author Yann Kurzo
/// @date   July 10, 2015, 2:06 AM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  This file defines the Input class.
//  ==========================================================================

#include "input.h"
#include "util.h"

#include <iostream>

using namespace std;

Input::Input(void)
{
    historyNumber_m = 0;
}

void Input::getInput(std::string &str)
{   
    str = "";
    
#if(HAVE_CONIO == 0 && HAVE_IOCTL == 0)
    cin >> str;
#else
    /// TEST
    cout << "Test: ";
    
//    getArrow(str);
    while(str.find("\n") == string::npos)
    {
        // Check for arrow
        string checkArrow = "";
        int arrow = getArrow(checkArrow);
        switch(arrow)
        {
            case INPUT_ARROW_UP:
                if(historyNumber_m < history_m.size()-1)
                {
                    ++historyNumber_m;
                    checkArrow = history_m.at(history_m.size()-historyNumber_m-1);
                    for(int i=str.size()-1; i>=0; --i)
                    {
                        cout << "\b \b";
                    }
                    str = checkArrow;
                    cout << checkArrow;
                }
                break;
            case INPUT_ARROW_DOWN:
//                if(historyNumber_m > 0)
//                {
//                    --historyNumber_m;
//                    checkArrow = history_m.at(history_m.size()-historyNumber_m-1);
//                    for(int i=str.size()-1; i>=0; --i)
//                    {
//                        cout << "\b \b";
//                    }
//                    str = checkArrow;
//                    cout << checkArrow;
//                }
                break;
            case INPUT_ARROW_RIGHT:
                break;
            case INPUT_ARROW_LEFT:
                break;
            case INPUT_BACK:
                if(str.size() > 0)
                {
                    str.pop_back();
                    cout << "\b \b";
                }
                break;
            default:
                // Add current char
                str += checkArrow;
                cout << checkArrow;
                break;
        }
    }
    
    // Erase "\r\n"
    while(str.back() == '\r' || str.back() == '\n')
    {
        str.pop_back();
    }
    
    // Update history
    history_m.push_back(str);
    
    // Check history size
    
#endif
}