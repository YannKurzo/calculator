
//  ==========================================================================
/// @file   application.cc
/// @author Yann Kurzo
/// @date   June 14, 2015, 9:32 PM
/// @license GPL2
/// @brief  
//  ==========================================================================

#include "application.h"

#include <iostream>

using namespace std;

Application::Application(int argc, char* argv[])
{
    argc_m = argc;
    argv_m = argv;
    
    // Check for arguments
    argumentPresent_m = (argc_m > 1);
        
    // Show title
    showTitle();
}

void Application::start(void)
{
    if(argumentPresent_m)
    {
        startArgument();
    }
    else
    {
        startCommand();
        showExit();
    }
}

void Application::startArgument(void)
{
    // Check every argument
    for(int i=1; i<argc_m; ++i)
    {
        str_m = argv_m[i];
        
        // Start analysis if it is not a command
        if(checkCommand() == eNB_COMMANDS)
        {
            startAnalyse();
        }
        // Else cancel
        else
        {
            break;
        }
    }
}

void Application::startCommand(void)
{
    cin >> str_m;
    
    // While we do not exit
    while(str_m != "exit")
    {
        // Start analysis if it is not a command
        if(checkCommand() == eNB_COMMANDS)
        {
            startAnalyse();
        }
        
        // Get new line
        cin >> str_m;
    }
}

command_e Application::checkCommand(void)
{
    command_e command;
    
    // Get the right command
    if(argumentPresent_m)
    {
        command = Command::getArgument(str_m);
    }
    else
    {
        command = Command::getCommand(str_m);
    }
        
    // Execute the command if it is a command
    if(command != eNB_COMMANDS)
    {
        // Show functions and quit
        switch(command)
        {
            case eCOMMAND_LIST_AVAILABLE_FUNCTIONS:
                cout << Function::getFunctionList() << endl;
                break;
            case eCOMMAND_HELP:
                cout << Command::getHelp() << endl;
                break;
            default:
                break;
        }
    }
    
    return command;
}

void Application::startAnalyse(void)
{
    // Analyze
    Analyze an(str_m);
    
    try
    {
        // Get tokens
        an.lexer();
        
        // Calculates
        an.parserExec();

        // Display result
        cout << "Result:" << endl;
        cout << "        " << str_m << " = " << an.getResult() << endl << endl;
    }
    catch(exception const &e)
    {
        cerr << "Problem when analyzing entered string:\n\t" << e.what() << endl;
    }
}

void Application::showTitle(void)
{
    // Title
    cout << "--------------------" << endl;
    cout << "---- Calculator ----" << endl;
    cout << "--------------------" << endl << endl;
}

void Application::showExit(void)
{
    // Title
    cout << "Exit Calculator ..." << endl << endl;
}