
//  ==========================================================================
/// @file   application.cc
/// @author Yann Kurzo
/// @date   June 14, 2015, 9:32 PM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  This file defines the Application class.
//  ==========================================================================

#include "application.h"
#include "analyze.h"
#include "constant.h"

#include <iostream>

using namespace std;

#define THROW(str) throw runtime_error(str);

Application::Application(int argc, char* argv[])
{
    argc_m = argc;
    argv_m = argv;
    
    // Check for arguments
    argumentPresent_m = (argc_m > 1);
        
    // Show title
    if(!argumentPresent_m)
    {
        showTitle();
    }
    
    // Set cout precision
    cout.precision(15);
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
    }
}

void Application::startCommand(void)
{
    cin >> str_m;
    
    // While we do not exit
    while(str_m != "exit" && str_m != "-q")
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
            case eCOMMAND_SET_PRECISION:
                
#if(USE_DOUBLE_TYPE == 1)
                cout << "Command not valid when not using Mpfr library!" << endl;
#elif(USE_MPFR_LIBRARY == 1)
                if(Command::getValue(str_m) > 1)
                {
                    MPFR::setPrecision(static_cast<unsigned int>(Command::getValue(str_m)));
                    cout << "Precision set to " << Command::getValue(str_m) << " bits" << endl;
                }
                else
                {
                    cout << "Parameter not valid!" << endl;
                }
#endif  /* USE_MPFR_LIBRARY */
                break;
            case eCOMMAND_LIST_AVAILABLE_FUNCTIONS:
                cout << Function::getFunctionList() << endl;
                break;
            case eCOMMAND_LIST_AVAILABLE_CONSTANTS:
                cout << Constant::getConstantList() << endl;
                break;
            case eCOMMAND_HELP:
                cout << Command::getHelp(true, !argumentPresent_m) << endl;
                break;
            case eCOMMAND_VERSION:
                cout << applicationName_m << " " << applicationVersion_m << endl << endl;
                cout << "Copyright 2015 Yann Kurzo. All rights reserved." << endl;
                cout << "This project is released under the GNU Public License" << endl;
                break;
            default:
                break;
        }
    }
    
    return command;
}

void Application::startAnalyse(void)
{
    // Check equality sign
    std::size_t signPosition = str_m.find(string("="));
    if(signPosition != string::npos)
    {
        variable_m = str_m.substr(0, signPosition);
        str_m = str_m.substr(signPosition+1, str_m.size());
    }
    else
    {
        variable_m = "";
    }
    
    // Analyze
    Analyze an(str_m);
    
    try
    {
        // Get tokens
        an.lexer();
        
        // Calculates
        an.parserExec();
        
        // Check if setting new variable
        if(variable_m != "")
        {
            // Check if the variable can be modified
            if(!Constant::addConstant(variable_m, an.getResult()))
            {
                THROW("Variable not set (existing constant)!");
            }
            str_m = variable_m;
        }
        
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
    // Set strings to show
    string title = "---- " + applicationName_m + " " + applicationVersion_m + " ----";
    string line = "";
    
    for(unsigned int i=0; i<title.size(); ++i)
    {
        line += "-";
    }
    
    // Show title
    cout << endl << line << endl;
    cout << title << endl;
    cout << line << endl << endl;
}

void Application::showExit(void)
{
    // Title
    cout << "Exit calculator ..." << endl << endl;
}
