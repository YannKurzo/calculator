
//  ==========================================================================
/// @file   command.cc
/// @author Yann Kurzo
/// @date   June 14, 2015, 9:32 PM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  This file defines the Command class.
//  ==========================================================================

#include "command.h"

#include <cstdlib>

using namespace std;

command_e Command::getArgument(std::string argument)
{
    string arg = argument.substr(0, argument.find("="));
    
    for(int i=0; i<eNB_COMMANDS; ++i)
    {
        if(arg == ("--" + commands[i].command) || arg == commands[i].shortcut)
        {
            return static_cast<command_e>(i);
        }
    }
    return eNB_COMMANDS;
}

command_e Command::getCommand(std::string command)
{
    string com = command.substr(0, command.find("="));
    
    for(int i=0; i<eNB_COMMANDS; ++i)
    {
        if(com == commands[i].command || com == commands[i].shortcut)
        {
            return static_cast<command_e>(i);
        }
    }
    return eNB_COMMANDS;
}

int Command::getValue(std::string command)
{
    return ::atoi(command.substr(command.find("=")+1, command.size()).c_str());
}

std::string Command::getHelp(void)
{
    string str("");

    str = str + "usage: calculator [OPTION]... CALCULATIONS\n\n";
    str = str + "Mandatory arguments\n";

    for(int i=0; i<eNB_COMMANDS; ++i)
    {
        str = str + "  " + commands[i].command + " (" + commands[i].shortcut + ") : " + commands[i].help + "\n";
    }
    
    return str;
}
