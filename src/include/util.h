
//  ==========================================================================
/// @file   util.h
/// @author Yann Kurzo
/// @date   June 14, 2015, 9:32 PM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  Define a few utilitary functions
//  ==========================================================================

#ifndef UTIL_H
#define	UTIL_H

// Check for autoconfig header
#if HAVE_CONFIG_H
#include <autoConfig.h>
#endif /* HAVE_CONFIG_H */

#include <string>
#include <sstream>

// Used to throw standard exception
#define THROW(str) throw runtime_error(str);

namespace std
{
    // Implement std::to_string for compatibility with some compilers
    template <typename T>
    std::string to_string(T value)
    {
        std::ostringstream os;
        os << value;
        return os.str();
    }
}

#if(HAVE_IOCTL == 1)
int getch( void );
#endif

#if(HAVE_IOCTL == 0 && HAVE_CONIO == 0)
    #define HAVE_GETCH  0
#else
    #define HAVE_GETCH  1
#endif

// Use getch to check for special characters
typedef enum
{
    INPUT_ARROW_UP,
    INPUT_ARROW_RIGHT,
    INPUT_ARROW_DOWN,
    INPUT_ARROW_LEFT,
    INPUT_BACK,
    INPUT_DELETE,
    INPUT_NORMAL_CHAR
}char_e;

char_e getCharacter(std::string &str);

#endif	/* UTIL_H */

