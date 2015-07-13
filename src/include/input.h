
//  ==========================================================================
/// @file   input.h
/// @author Yann Kurzo
/// @date   July 10, 2015, 2:06 AM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  This file defines the Input class.
//  ==========================================================================

#ifndef INPUT_H
#define	INPUT_H

#include "util.h"

#include <string>

/// @brief  This class is used get the user input. If the getch() function is
///         defined, it uses the arrows to get an historic of the commands.
///         Otherwise, the input is simply get by using the standard library.
class Input
{
    protected:
#if(HAVE_GETCH == 1)
    
        /// Actual command
        int historyNumber_m;
        
        /// Current position in string
        int pos_m;
        
#endif /* HAVE_GETCH */
        
    public:
        /// @brief  Constructor
        Input(void);
        
        /// @brief  Get the next command
        /// @param  str Contains the next command after the return
        void getInput(std::string &str);
        
#if(HAVE_GETCH == 1)
    
        /// @brief  Erase a complete line on output
        /// @param  str String to modify
        void coutEraseAll(std::string &str);
        
        /// @brief  Erase the character at the current position
        /// @param  str String to modify
        void coutErase(std::string &str);
        
        /// @brief  Go to the position (relative to current position)
        /// @param  pos Relative position to move to
        /// @param  str String to modify
        /// @return true if the position was updated, false otherwise
        bool coutGo(int pos, std::string &str);

        /// @brief  Add a string at the current position
        /// @param  c String to add at the current position
        /// @param  str String to modify
        void coutAdd(std::string &c, std::string &str);
        
#endif /* HAVE_GETCH */
};


#endif	/* INPUT_H */

