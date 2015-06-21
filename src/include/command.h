
//  ==========================================================================
/// @file   command.h
/// @author Yann Kurzo
/// @date   June 14, 2015, 9:32 PM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  This file defines the Command class.
//  ==========================================================================

#ifndef COMMAND_H
#define	COMMAND_H

#include <string>

/// @brief  List of available commands and arguments
typedef enum
{
    eCOMMAND_LIST_AVAILABLE_FUNCTIONS,
    eCOMMAND_SET_PRECISION,
    eCOMMAND_HELP,
    eCOMMAND_EXIT,
    eNB_COMMANDS
}command_e;

/// @brief  Structure to hold a command
typedef struct
{
    command_e commandEnum;      ///< Command enumeration
    std::string command;        ///< Command name
    std::string shortcut;       ///< Command shortcut (-h)
    std::string help;           ///< Help notice
}command_t;

/// @brief  List of commands
static const command_t commands[] =
{
    {eCOMMAND_LIST_AVAILABLE_FUNCTIONS, "list-available-functions", "-l", "Show a list of available functions"},
    {eCOMMAND_SET_PRECISION, "set-precision", "-p", "Set the precision (only when using Mpfr library): set-precision=25 / -p=25 (without spaces)"},
    {eCOMMAND_HELP, "help", "-h", "Show this"},
    {eCOMMAND_EXIT, "exit", "-q", "Exit the program"}
};

/// @brief  This class handles the different commands and arguments
class Command
{
    protected:
        /// Command to analyze
        std::string str_m;

    public:
        /// @brief  Get the argument
        /// @param  argument Argument to analyze
        /// @return Argument, or eNB_COMMANDS otherwise
        static command_e getArgument(std::string argument);
        
        /// @brief  Get the command
        /// @param  command Command to analyze
        /// @return Command, or eNB_COMMANDS otherwise
        static command_e getCommand(std::string command);
        
        /// @brief  Get the value after the = in a command
        /// @param  command Command to analyze
        /// @return Value
        static int getValue(std::string command);
        
        /// @brief  Get help about the commands
        /// @return String containing the help
        static std::string getHelp(void);
};

#endif	/* COMMAND_H */

