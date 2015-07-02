
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

command_e Command::getCommand(std::string command)
{
    std::size_t endCommand = command.find(parameterSign);
    string com = command.substr(0, endCommand);

    // Check commands
    for(int i=0; i<eNB_COMMANDS; ++i)
    {
        if(com == ("--" + commands[i].command) || com == commands[i].shortcut)
        {
            return static_cast<command_e>(i);
        }
    }
    // If there was the -> and it is not a command
    if(endCommand != string::npos)
    {
        return eCOMMAND_NOT_IMPLEMENTED;
    }
    // Otherwise, it was not a command
    else
    {
        return eNB_COMMANDS;
    }
}

bool Command::hasParam(std::string command)
{
    return (command.find(parameterSign) != string::npos);
}

int Command::getValueParameter(std::string command)
{
    return ::atoi(getStringParameter(command).c_str());
}

std::string Command::getStringParameter(std::string command)
{
    return command.substr(command.find(parameterSign)+parameterSign.size(), command.size());
}

std::string Command::getHelp(bool detailed, bool command)
{
    stringstream flow;
    flow << setiosflags(ios::left);
    
    flow << "Usage: calculator [OPTION[" << parameterSign << "VALUE]]... CALCULATION..." << endl;
    flow << "Execute the CALCULATION(s)." << endl << endl;

    for(int i=0; i<eNB_COMMANDS; ++i)
    {
        // Show help
        flow << "  " << commands[i].shortcut << ", ";
        flow << "--" << setw(16) << commands[i].command << setw(0);
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
    flow << endl;
    flow << "When a command needs a parameter, the parameter must be written after the" << endl;
    flow << "command separated by \"" << parameterSign << "\" without spaces." << endl;
    flow << "Example: -p" << parameterSign << "25 (set precision to 25 bits)." << endl;
    
    // Remark for ""
    if(!command)
    {
        flow << endl;
        flow << "Each CALCULATION should be written between quotations marks \" \" to ensure" << endl;
        flow << "a good execution of the calculation." << endl;
    }
    // Remark for setting user variables
    else
    {
        flow << endl;
        flow << "It is possible to set user variables by using \"variableName=value\". The value" << endl;
        flow << "can be a CALCULATION. The variable names must start with a letter and must" << endl;
        flow << "contain letters, numbers, or underscores only." << endl;
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
            flow << setw(24) << " " << setw(0) << commands[command].details[i] << endl;
        }
    }
    
    return flow.str();
}
