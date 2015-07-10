
//  ==========================================================================
/// @file   util.cc
/// @author Yann Kurzo
/// @date   June 14, 2015, 9:32 PM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  Define a few utilitary functions
//  ==========================================================================

#include "util.h"

#include <iostream>
#include <conio.h>

using namespace std;

arrow_e getArrow(std::string &str)
{
    arrow_e ret = ARROW_NONE;
    
    int c1 = getch();
    
    if(c1 == 224)
    {
        int c2 = getch();
        
        switch(c2)
        {
            case 72:
                ret = ARROW_UP;
                break;
            case 77:
                ret = ARROW_RIGHT;
                break;
            case 80:
                ret = ARROW_DOWN;
                break;
            case 75:
                ret = ARROW_LEFT;
                break;
            default:
                str = static_cast<char>(c2) + str;
                break;
        }
    }
    else
    {
        str = static_cast<char>(c1) + str;
    }
    
    cout << str;
    
    return ret;
}


/// TEST

// #include <sys/ioctl.h>
// int getch( void );
// int getch( void )
// {
// char ch;
// int fd = fileno(stdin);
// struct termio old_tty, new_tty;

// ioctl(fd, TCGETA, &old_tty);
// new_tty = old_tty;
// new_tty.c_lflag &= ~(ICANON | ECHO | ISIG);
// ioctl(fd, TCSETA, &new_tty);
// fread(&ch, 1, sizeof(ch), stdin);
// ioctl(fd, TCSETA, &old_tty);

// return ch;
// }

/// TEST