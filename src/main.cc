
//  ==========================================================================
/// @file   main.cc
/// @author Yann Kurzo
/// @date   May 11, 2015, 9:32 PM
/// @license GPL2
//  ==========================================================================

#include "application.h"
#include "analyze.h"

#include <iostream>
#include <string>
#include <exception>

using namespace std;

void startAnalyze(string str);

int main(int argc,char *argv[])
{
    // Title
    cout << "--------------------" << endl;
    cout << "---- Calculator ----" << endl;
    cout << "--------------------" << endl << endl;
    
    string str("0");
    
    // If no argument, use cin
    if(argc < 2)
    {
        str = "pi()";
    }
    // Else use line argumentvoid
    else
    {
        str = argv[1];
    }
    
    startAnalyze(str);
	
	cin.get();
    
    return 0;
}

void startAnalyze(string str)
{
    // Analyze
    Analyze an(str);
    
    try
    {
        // Get tokens
        an.lexer();
        
        // // Calculates
        an.parserExec();

        // Display result
        cout << endl << "Result:" << endl;
        cout << "        " << str << " = " << an.getResult() << endl << endl;
    }
    catch(exception const &e)
    {
        cerr << "Problem when analyzing entered string:\n\t" << e.what() << endl;
    }
}