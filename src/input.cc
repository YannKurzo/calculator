
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
    pos_m = 0;
    historyNumber_m = 0;
}

void Input::coutEraseAll(std::string &str)
{
    // Erase screen
    for(int i=str.size()-1; i>=0; --i)
    {
        cout << "\b \b";
    }
    // Erase string
    str = "";
}

void Input::coutErase(std::string &str)
{
    if(pos_m > 0)
    {
        // Erase string
        --pos_m;
        str.erase(pos_m, 1);
        cout << "\b";
        
        // Erase screen
        for(int i=pos_m; i<static_cast<int>(str.size()); ++i)
        {
            cout << str.at(i);
        }
        cout << " ";
        
        // Move cursor back
        for(int i=pos_m; i<=static_cast<int>(str.size()); ++i)
        {
            cout << "\b";
        }
    }
}

bool Input::coutGo(int pos, std::string &str)
{
    if(pos_m + pos >= 0 && pos_m + pos <= static_cast<int>(str.size()))
    {
        if(pos < 0)
        {
            for(int i=pos; i<0; ++i)
            {
                cout << "\b";
                --pos_m;
            }
        }
        else
        {
            for(int i=pos; i>0; --i)
            {
                cout << str.at(pos_m);
                ++pos_m;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

void Input::coutAdd(std::string &c, std::string &str)
{
    // Insert character
    str.insert(pos_m, c);
    ++pos_m;
        
    // Print the rest of characters
    for(int i=pos_m-1; i<static_cast<int>(str.size()); ++i)
    {
        cout << str.at(i);
    }
    
    // Move cursor back
    for(int i=pos_m; i<static_cast<int>(str.size()); ++i)
    {
        cout << "\b";
    }
}

void Input::getInput(std::string &str)
{   
#if(HAVE_CONIO == 0 && HAVE_IOCTL == 0)
    cin >> str;
#else
    /// TEST
    
    str = "";

    // While there is only white spaces
    while(str.size() == 0 || str.find_first_not_of(" \t\n\v\f\r") == std::string::npos)
    {
cout << "Test: ";
        // Init
        pos_m = 0;
        str = "";
        
        // While enter was not pressed
        while(str.find("\n") == string::npos)
        {
            // Check for characters
            string tmpStr = "";
            int specialChar = getCharacter(tmpStr);
            
            switch(specialChar)
            {
                case INPUT_ARROW_UP:
                    coutEraseAll(str);
                    // if(historyNumber_m < history_m.size()-1)
                    // {
                        // ++historyNumber_m;
                        // checkArrow = history_m.at(history_m.size()-historyNumber_m-1);
                        // for(int i=str.size()-1; i>=0; --i)
                        // {
                            // cout << "\b \b";
                        // }
                        // str = checkArrow;
                        // cout << checkArrow;
                    // }
                    break;
                case INPUT_ARROW_DOWN:
    // //                if(historyNumber_m > 0)
    // //                {
    // //                    --historyNumber_m;
    // //                    checkArrow = history_m.at(history_m.size()-historyNumber_m-1);
    // //                    for(int i=str.size()-1; i>=0; --i)
    // //                    {
    // //                        cout << "\b \b";
    // //                    }
    // //                    str = checkArrow;
    // //                    cout << checkArrow;
    // //                }
                    break;
                case INPUT_ARROW_RIGHT:
                    coutGo(1, str);
                    break;
                case INPUT_ARROW_LEFT:
                    coutGo(-1, str);
                    break;
                case INPUT_BACK:
                    coutErase(str);
                    break;
                case INPUT_DELETE:
                    if(coutGo(1, str))
                    {
                        coutErase(str);
                    }
                    break;
                default:
                    coutAdd(tmpStr, str);
                    break;
            }
        }
        
        // Erase "\r\n"
        while(str.back() == '\r' || str.back() == '\n')
        {
            str.pop_back();
        }
        // Update history
        // history_m.push_back(str);
        
        // Check history size
    }
#endif
}