
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

#include <string>
#include <deque>

/// @brief  This class is used to parse the vector of tokens and calculates
///         the mathematical result.
class Input
{
    protected:
        /// Command history
        std::deque<std::string> history_m;
        
        /// Actual command
        unsigned int historyNumber_m;
        
        int pos_m;
        
    public:
        /// @brief  Constructor
        Input(void);
        
        /// @brief  Get the next command
        void getInput(std::string &str);
        
        void coutEraseAll(std::string &str);
        
        void coutErase(std::string &str);
        
        bool coutGo(int pos, std::string &str);

        void coutAdd(std::string &c, std::string &str);
};


#endif	/* INPUT_H */

