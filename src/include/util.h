
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

#include <string>
#include <sstream>

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

#endif	/* UTIL_H */

