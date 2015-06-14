
//  ==========================================================================
/// @file   command.h
/// @author Yann Kurzo
/// @date   June 14, 2015, 9:32 PM
/// @license GPL2
/// @brief  Class to handle the different commands and arguments
//  ==========================================================================

#ifndef COMMAND_H
#define	COMMAND_H

#include <string>


/// @brief  List of commands
static const std::string commands[] =
{
    "list-available-functions"
};

/// @brief  List of commands shortcut
static const std::string commandsShortcut[] =
{
    "-l"
};

/// @brief  Class to handle the different commands and arguments
class Command
{ 
    public:
        /// @brief  List of available commands and arguments
        typedef enum
        {
            eARGUMENT_LIST_AVAILABLE_FUNCTIONS,
            eNB_COMMANDS
        }command_t;
        
    protected:
        // Command to analyze
        std::string str_m;

    public:
        /// @brief  Get the actual argument
        /// @return Argument, or eNB_COMMANDS elsewhere
        static command_t getArgument(std::string str);
        
        /// @brief  Get the actual command
        /// @return Command, or eNB_COMMANDS elsewhere
        static command_t getCommand(std::string str);
};

#endif	/* COMMAND_H */

