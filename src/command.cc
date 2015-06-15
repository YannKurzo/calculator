
//  ==========================================================================
/// @file   command.cc
/// @author Yann Kurzo
/// @date   June 14, 2015, 9:32 PM
/// @license GPL2
/// @brief  This file defines the Command class.
//  ==========================================================================

#include "command.h"

using namespace std;

command_e Command::getArgument(std::string argument)
{
    for(int i=0; i<eNB_COMMANDS; ++i)
    {
        if(argument == ("--" + commands[i].command) || argument == commands[i].shortcut)
        {
            return static_cast<command_e>(i);
        }
    }
    return eNB_COMMANDS;
}

command_e Command::getCommand(std::string command)
{
    for(int i=0; i<eNB_COMMANDS; ++i)
    {
        if(command == commands[i].command || command == commands[i].shortcut)
        {
            return static_cast<command_e>(i);
        }
    }
    return eNB_COMMANDS;
}

std::string Command::getHelp(void)
{
    string str("");
    
    for(int i=0; i<eNB_COMMANDS; ++i)
    {
        str = str + "  " + commands[i].command + " (" + commands[i].shortcut + ") : " + commands[i].help + "\n";
    }
    
    return str;
}