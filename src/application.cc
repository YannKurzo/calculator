
//  ==========================================================================
/// @file   application.cc
/// @author Yann Kurzo
/// @date   May 11, 2015, 9:32 PM
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
    }
}

void Application::startArgument(void)
{
    // Check every argument
    for(int i=1; i<argc_m; ++i)
    {
        str_m = argv_m[i];
        
        startAnalyse();
    }
}

void Application::startCommand(void)
{
    str_m = "pi()";
    
    startAnalyse();
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