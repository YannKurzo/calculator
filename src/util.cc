
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
    CHAR_BACK = 127
};
#endif /* HAVE_CONIO */

#if(HAVE_IOCTL == 1)
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
    CHAR_BACK = 127
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

arrow_e getArrow(std::string &str)
{
    arrow_e ret = INPUT_NONE;
    
    int escapeChar1 = getch();
    
    if(escapeChar1 == CHAR_ESCAPE1)
    {
#if(HAVE_IOCTL == 1)
    int escapeChar2 = getch();
        
    if(escapeChar2 == CHAR_ESCAPE2)
    {
#endif
        int arrowChar = getch();
        
        switch(arrowChar)
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
            default:
                str = static_cast<char>(arrowChar) + str;
                break;
        }
#if(HAVE_IOCTL == 1)
    }
    else
    {
        str = static_cast<char>(escapeChar2) + str;
    }
#endif
    }
    else if(escapeChar1 == CHAR_BACK)
    {
        ret = INPUT_BACK;
    }
    else
    {
        str = static_cast<char>(escapeChar1) + str;
    }
    
    return ret;
}
