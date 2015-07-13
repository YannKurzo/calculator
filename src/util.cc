
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
#include <cstdlib>

using namespace std;

#if(HAVE_CONIO == 1)
#include <conio.h>

enum
{
    CHAR_ESCAPE1 = 224,
    CHAR_UP = 72,
    CHAR_RIGHT = 77,
    CHAR_DOWN = 80,
    CHAR_LEFT = 75,
    CHAR_DELETE = 51,
    CHAR_BACKSPACE = 8
};
#endif /* HAVE_CONIO */

#if(HAVE_IOCTL == 1)
#include <cstdio>
#include <sys/ioctl.h>
#include <termios.h>

enum
{
    CHAR_ESCAPE1 = 27,
    CHAR_ESCAPE2 = 91,
    CHAR_UP = 65,
    CHAR_RIGHT = 67,
    CHAR_DOWN = 66,
    CHAR_LEFT = 68,
    CHAR_DELETE = 51,
    CHAR_BACKSPACE = 127
};

int getch( void )
{
    char ch;
    int fd = fileno(stdin);
    struct termio old_tty, new_tty;

    ioctl(fd, TCGETA, &old_tty);
    new_tty = old_tty;
    new_tty.c_lflag &= ~(ICANON | ECHO | ISIG);
    ioctl(fd, TCSETA, &new_tty);
    if(fread(&ch, 1, sizeof(ch), stdin) != 1)
    {
        cout << "Problem with fread!" << endl;
    }
    ioctl(fd, TCSETA, &old_tty);

    return ch;
}
#endif /* HAVE_IOCTL */

char_e getCharacter(std::string &str)
{
    char_e ret = INPUT_NORMAL_CHAR;
    
    int escapeChar1 = getch();
    
    if(escapeChar1 == CHAR_ESCAPE1)
    {
#if(HAVE_IOCTL == 1)
    int escapeChar2 = getch();
        
    if(escapeChar2 == CHAR_ESCAPE2)
    {
#endif /* HAVE_IOCTL */
        int actualChar = getch();
        
        switch(actualChar)
        {
            case CHAR_UP:
                ret = INPUT_ARROW_UP;
                break;
            case CHAR_RIGHT:
                ret = INPUT_ARROW_RIGHT;
                break;
            case CHAR_DOWN:
                ret = INPUT_ARROW_DOWN;
                break;
            case CHAR_LEFT:
                ret = INPUT_ARROW_LEFT;
                break;
            case CHAR_DELETE:
                // Get last char
                getch();
                ret = INPUT_DELETE;
                break;
            default:
                // Get back the character
                str = static_cast<char>(actualChar) + str;
                break;
        }
#if(HAVE_IOCTL == 1)
    }
    else
    {
        str = static_cast<char>(escapeChar2) + str;
    }
#endif /* HAVE_IOCTL */
    }
    // Get ctrl + C and ctrl + D
    else if(escapeChar1 == 0x03 || escapeChar1 == 0x04)
    {
        exit(0);
    }
    // Get backspace
    else if(escapeChar1 == CHAR_BACKSPACE)
    {
        ret = INPUT_BACK;
    }
    // Get normal characters
    else
    {
        // Check for cariage return
        if(escapeChar1 == '\r')
        {
            str = "\n" + str;
        }
        // Get back the character
        str = static_cast<char>(escapeChar1) + str;
    }
    
    return ret;
}
