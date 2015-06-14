
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

/// @brief  List of available commands and arguments
typedef enum
{
    eCOMMAND_LIST_AVAILABLE_FUNCTIONS,
    eCOMMAND_HELP,
    eNB_COMMANDS
}command_e;

/// @brief  Structure to hold a command
typedef struct
{
    command_e commandEnum;
    std::string command;
    std::string shortcut;
    std::string help;
}command_t;

/// @brief  List of commands
static const command_t commands[] =
{
    {eCOMMAND_LIST_AVAILABLE_FUNCTIONS, "list-available-functions", "-l", "Show a list of available functions"},
    {eCOMMAND_HELP, "help", "-h", "Show this"}
};

/// @brief  List of commands
//static const std::string commands[] =
//{
//    "list-available-functions"
//};
//
///// @brief  List of commands shortcut
//static const std::string commandsShortcut[] =
//{
//    "-l"
//};

/// @brief  Class to handle the different commands and arguments
class Command
{
    protected:
        // Command to analyze
        std::string str_m;

    public:
        /// @brief  Get the actual argument
        /// @return Argument, or eNB_COMMANDS elsewhere
        static command_e getArgument(std::string str);
        
        /// @brief  Get the actual command
        /// @return Command, or eNB_COMMANDS elsewhere
        static command_e getCommand(std::string str);
        
        /// @brief  Get help about the commands
        /// @return String containing the help
        static std::string getHelp(void);
};

#endif	/* COMMAND_H */

