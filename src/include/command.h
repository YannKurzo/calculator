
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
#include <vector>

/// @brief  Sign to send a value as a parameter
const static std::string parameterSign("->");

/// @brief  List of available commands and arguments
typedef enum
{
    eCOMMAND_LIST_AVAILABLE_FUNCTIONS,
    eCOMMAND_LIST_AVAILABLE_CONSTANTS,
    eCOMMAND_LIST_AVAILABLE_VARIABLES,
    eCOMMAND_PRECISION,
    eCOMMAND_CLEAR,
    eCOMMAND_HELP,
    eCOMMAND_VERSION,
    eCOMMAND_EXIT,
    eNB_COMMANDS,
    eCOMMAND_NOT_IMPLEMENTED
}command_e;

/// @brief  Structure to hold a command
typedef struct
{
    command_e commandEnum;      ///< Command enumeration
    std::string command;        ///< Command name
    std::string shortcut;       ///< Command shortcut (-h)
    std::string help;           ///< Help notice
    std::vector<std::string> details;///< Detailed help notice
}command_t;

/// @brief  List of commands
static const command_t commands[] =
{
    {eCOMMAND_LIST_AVAILABLE_FUNCTIONS, "functions-list", "-f", "Show a list of available functions",{""}},
    {eCOMMAND_LIST_AVAILABLE_CONSTANTS, "constants-list", "-c", "Show a list of available constants",{""}},
    {eCOMMAND_LIST_AVAILABLE_VARIABLES, "variables-list", "-u", "Show the list of user defined variables",{""}},
    {eCOMMAND_PRECISION, "precision", "-p", "Set/Get the precision (number of bits of the mantissa)",
        {"Use: (default number of bits is 53)",
         "  Get: -p | --precision (without parameters)",
         "  Set: -p" + parameterSign + "nbBits | --precision" + parameterSign + "nbBits (only for Mpfr)"}},
    {eCOMMAND_CLEAR, "erase", "-e", "Clear user defined variables",
        {"Use:",
         "  Clear all: -e | --erase",
         "  Clear variable 'x': -e->x | --erase->x"}},
    {eCOMMAND_HELP, "help", "-h", "Display this help",{""}},
    {eCOMMAND_VERSION, "version", "-v", "Display the program version",{""}},
    {eCOMMAND_EXIT, "exit", "-q", "Exit the program",{""}}
};

/// @brief  This class handles the different commands and arguments
class Command
{
    protected:
        /// Command to analyze
        std::string str_m;

    public:        
        /// @brief  Get the command
        /// @param  command Command to analyze
        /// @return Command, or eNB_COMMANDS otherwise
        static command_e getCommand(std::string command);
        
        /// @brief  Check if a command has parameters
        /// @return true if it does, false otherwise
        static bool hasParam(std::string command);
        
        /// @brief  Get the value after the command
        /// @param  command Command to analyze
        /// @return Value
        static int getValueParameter(std::string command);
        
        /// @brief  Get the parameter string after the command
        /// @param  command Command to analyze
        /// @return String
        static std::string getStringParameter(std::string command);
        
        /// @brief  Get help about the commands
        /// @param  detailed Detailed help if true
        /// @return String containing the help
        static std::string getHelp(bool detailed, bool command);
        
        /// @brief  Get detailed help about a commands
        /// @param  command Which command
        /// @return String containing the help
        static std::string getDetailedHelp(command_e command);
};

#endif	/* COMMAND_H */

