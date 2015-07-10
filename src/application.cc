
//  ==========================================================================
/// @file   application.cc
/// @author Yann Kurzo
/// @date   June 14, 2015, 9:32 PM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  This file defines the Application class.
//  ==========================================================================

#include "application.h"
#include "config.h"
#include "analyze.h"
#include "util.h"
#include "constant.h"

#include <iostream>

using namespace std;

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
#include <deque>
void Application::startCommand(void)
{
    deque<string> history;
    // Get new line
    cin >> str_m;
    history.push_back(str_m);
    
    // While we do not exit
    while(str_m != "--exit" && str_m != "-q")
    {
        // Start analysis if it is not a command
        if(checkCommand() == eNB_COMMANDS)
        {
            startAnalyse();
        }
        
        // Check for arrow
        string checkArrow = "";
        if(getArrow(checkArrow) == ARROW_UP)
        {
            checkArrow = history.at(history.size()-1);
            cout << checkArrow;
        }
        
        // Get new line
        cin >> str_m;
        str_m = checkArrow + str_m;
    }
}

void Application::precisionCommand(void)
{
    // Set the precision
    if(Command::hasParam(str_m))
    {
#if(USE_DOUBLE_TYPE == 1)
        cout << "Command not valid when not using Mpfr library!" << endl;
#elif(USE_MPFR_LIBRARY == 1)
        if(Command::getValueParameter(str_m) > 1)
        {
            // Set precision
            MPFR::setPrecision(static_cast<unsigned int>(Command::getValueParameter(str_m)));
            
            // Do not display in argument mode
            if(!argumentPresent_m)
            {
                cout << "Precision set to " << Command::getValueParameter(str_m) << " bits" << endl;
            }
        }
        else
        {
            cout << "Parameter not valid!" << endl;
        }
#endif  /* USE_MPFR_LIBRARY */
    }
    // Get the precision
    else
    {
        cout << "Actual precision set to " << MPFR::getPrecision() << " bits" << endl;
    }
}

void Application::scientificCommand(void)
{
    // Set the display mode
    if(Command::hasParam(str_m))
    {
        int sci = Command::getValueParameter(str_m);
        
        if(sci >= 0 && sci <= 1)
        {
            if(sci == 0)
            {
                cout << "Display mode set to normal" << endl;
#if(USE_DOUBLE_TYPE == 1)
                cout.unsetf(ios_base::floatfield);
#elif(USE_MPFR_LIBRARY == 1)
                MPFR::setDisplayMode(false);
#endif  /* USE_MPFR_LIBRARY */
            }
            else
            {
                cout << "Display mode set to scientific" << endl;
#if(USE_DOUBLE_TYPE == 1)
                cout << std::scientific;
#elif(USE_MPFR_LIBRARY == 1)
                MPFR::setDisplayMode(true);
#endif  /* USE_MPFR_LIBRARY */
            }
        }
        else
        {
            cout << "Parameter not valid!" << endl;
        }
    }
    // Problem
    else
    {
        cout << "Parameter is missing" << endl;
    }
}

void Application::clearCommand(void)
{
    // Clear specific variable
    if(Command::hasParam(str_m))
    {
        string variableName = Command::getStringParameter(str_m);
        
        if(Constant::clearVariable(variableName))
        {
            cout << "Variable " << variableName << " is cleared" << endl;
        }
        else
        {
            cout << "Variable not cleared!" << endl;
        }
        
    }
    // Clear all the variables
    else
    {
        if(Constant::clearAll())
        {
            cout << "All user defined variables are cleared" << endl;
        }
        else
        {
            cout << "There is no user defined variables!" << endl;
        }
    }
}

command_e Application::checkCommand(void)
{
    command_e command = Command::getCommand(str_m);
        
    // Execute the command if it is a command
    switch(command)
    {
        case eCOMMAND_LIST_AVAILABLE_FUNCTIONS:
            cout << Function::getFunctionList() << endl;
            break;
        case eCOMMAND_LIST_AVAILABLE_CONSTANTS:
            cout << Constant::getConstantList() << endl;
            break;
        case eCOMMAND_LIST_AVAILABLE_VARIABLES:
            cout << Constant::getVariableList() << endl;
            break;
        case eCOMMAND_PRECISION:
            precisionCommand();
            break;
        case eCOMMAND_SCIENTIFIC:
            scientificCommand();
            break;
        case eCOMMAND_CLEAR:
            clearCommand();
            break;
        case eCOMMAND_HELP:
            cout << Command::getHelp(true, !argumentPresent_m) << endl;
            break;
        case eCOMMAND_VERSION:
            cout << applicationName_m << " " << applicationVersion_m << endl << endl;
            cout << "Copyright 2015 Yann Kurzo. All rights reserved." << endl;
            cout << "This project is released under the GNU Public License" << endl;
            break;
        case eCOMMAND_NOT_IMPLEMENTED:
            cout << "This command does not exist!" << endl;
            break;
        default:
            break;
    }
    
    return command;
}

void Application::checkSetVariable(void)
{
    std::size_t signPosition = str_m.find(string("="));
    if(signPosition != string::npos)
    {
        variable_m = str_m.substr(0, signPosition);
        
        // Check variable name validity
        if(!Constant::isValidVariableName(variable_m))
        {
            THROW("Variable name is not valid!");
        }
        str_m = str_m.substr(signPosition+1, str_m.size());
    }
    else
    {
        variable_m = "";
    }
}

void Application::startAnalyse(void)
{
    try
    {
        // Check equality sign
        checkSetVariable();

        // Analyze
        Analyze an(str_m);
        
        // Get tokens
        an.lexer();
        
        // Calculates
        an.parserExec();
        
        // Check if setting new variable
        if(variable_m != "")
        {
            // Check if the variable can be modified
            if(!Constant::addVariable(variable_m, an.getResult()))
            {
                THROW("Variable not set (existing constant)!");
            }
            str_m = variable_m;
        }
        
        // Display result
        if(argumentPresent_m)
        {
            cout << an.getResult() << " ";
        }
        else
        {
            cout << "Result:" << endl;
            cout << "        " << str_m << " = " << an.getResult() << endl << endl;
        }
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
