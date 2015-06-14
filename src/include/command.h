
//  ==========================================================================
/// @file   command.h
/// @author Yann Kurzo
/// @date   June 14, 2015, 9:32 PM
/// @license GPL2
/// @brief  
//  ==========================================================================

#ifndef COMMAND_H
#define	COMMAND_H

#include <string>



static const std::string argumentsShortcut[] =
{
    "-l"
};

static const std::string commands[] =
{
    "list-available-functions"
};


/// @brief  
class Command
{ 
    public:
        /// @brief
        typedef enum
        {
            eARGUMENT_LIST_AVAILABLE_FUNCTIONS,
            eNB_COMMANDS
        }command_t;
        
    protected:
        // Command to analyze
        std::string str_m;

    public:
        /// @brief  
        static command_t getArgument(std::string str);
        
        /// @brief  
        static command_t getCommand(std::string str);
        
    private:
        
        /// @brief  
};

#endif	/* COMMAND_H */

