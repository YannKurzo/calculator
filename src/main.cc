
//  ==================================================
/// @file   main.cc
/// @author Yann Kurzo
/// @date   May 11, 2015, 9:32 PM
/// @license GPL2
//  ==================================================

#include "analyze.h"

#include <iostream>
#include <string>
#include <exception>

using namespace std;

int main(void)
{
    string str("pow(2+5,pi())+pi()");
    
    cout << "Calculator" << endl << endl;
    
    Analyze an(str);
    
    try
    {
        // Get tokens
        an.lexer();
        an.displayToken();
        
        // Calculates
        an.parserAndExec();

        // Display result
        cout << endl << "Result:" << endl;
        cout << "        " << str << " = " << an.getResult() << endl << endl;
    }
    catch(exception const &e)
    {
        cerr << "Problem when analyzing entered string:\n\t" << e.what() << endl;
    }
	
	cin.get();
    
    return 0;
}