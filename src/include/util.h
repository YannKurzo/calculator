
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
#include <stdexcept>

/// @brief  Used to throw standard exception
#define THROW(str) throw runtime_error(str);

namespace std
{
    /// @brief  Implement std::to_string for compatibility with some compilers
    template <typename T>
    std::string to_string(T value)
    {
        std::ostringstream os;
        os << value;
        return os.str();
    }
}

/// @brief  Define HAVE_GETCH to 1 if the getch function exists
#if(HAVE_IOCTL == 0 && HAVE_CONIO == 0)
    #define HAVE_GETCH  0
#else
    #define HAVE_GETCH  1
#endif

#if(HAVE_GETCH == 1)
    
    #if(HAVE_IOCTL == 1)
    /// @brief  Get a character from the console without waiting on enter
    /// @return The character value
    /// @note   The returned character depends on the OS
    int getch( void );
    #endif

    /// @brief  Enumeration for special characters
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

    /// @brief  Get a character from the console without waiting on enter
    /// @param  str Entered characters if it is not a special character
    /// @return INPUT_NORMAL_CHAR if it is a normal character, see char_e enumeration otherwise
    /// @note   The returned values do not depend on the OS
    char_e getCharacter(std::string &str);

#endif /* HAVE_GETCH */

#endif	/* UTIL_H */

