
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
#include <sstream>
#include <iomanip>

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

std::string Command::getHelp(bool detailed, bool command)
{
    stringstream flow;
    flow << setiosflags(ios::left);
    
    flow << "Usage: calculator [OPTION]... CALCULATION..." << endl;
    flow << "Execute the CALCULATION(s)." << endl << endl;

    for(int i=0; i<eNB_COMMANDS; ++i)
    {
        // Show help
        flow << "  " << commands[i].shortcut << ", ";
        flow << (command ? "  " : "--") << setw(18) << commands[i].command << setw(0);
        flow << commands[i].help << endl;
        
        // Show details
        if(detailed)
        {
            flow << getDetailedHelp(static_cast<command_e>(i));
        }
    }
    
    // Remark for multiple calculations
    flow << endl;
    flow << "The CALCULATIONS must be written without spaces. Multiple CALCULATIONS can be" << endl;
    flow << "done one after another by separating them with spaces." << endl;
    
    // Remark for ""
    if(!command)
    {
        flow << endl;
        flow << "Each CALCULATION should be written between quotations marks \" \" to ensure" << endl;
        flow << "a good execution of the calculation." << endl;
    }
    
    return flow.str();
}

std::string Command::getDetailedHelp(command_e command)
{
    stringstream flow;
    flow << setiosflags(ios::left);
    
    if(commands[command].details[0] != "")
    {
        for(unsigned int i=0;i<commands[command].details.size();++i)
        {
            flow << setw(26) << " " << setw(0) << commands[command].details[i] << endl;
        }
    }
    
    return flow.str();
}
