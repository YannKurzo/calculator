
//  ==========================================================================
/// @file   command.cc
/// @author Yann Kurzo
/// @date   June 14, 2015, 9:32 PM
/// @license GPL2
/// @brief  
//  ==========================================================================

#include "command.h"

using namespace std;


Command::command_t Command::getArgument(std::string str)
{
    for(int i=0; i<eNB_COMMANDS; ++i)
    {
        if(str == ("--" + commands[i]) || str == argumentsShortcut[i])
        {
            return static_cast<command_t>(i);
        }
    }
    return eNB_COMMANDS;
}

Command::command_t Command::getCommand(std::string str)
{
    for(int i=0; i<eNB_COMMANDS; ++i)
    {
        if(str == commands[i] || str == argumentsShortcut[i])
        {
            return static_cast<command_t>(i);
        }
    }
    return eNB_COMMANDS;
}