
//  ==================================================
/// @file   main.cc
/// @author Yann Kurzo
/// @date   May 11, 2015, 9:32 PM
/// @license GPL2
//  ==================================================

#include <iostream>
#include <string>

#include "analyze.h"

using namespace std;

int main(void)
{
    string str("pow(2,pi()*pi())+pi()");
    
    cout << "Calculator" << endl;
    
    Analyze an(str);
    
    cout << endl << "Lexer: " << endl;
    an.lexer();
    an.displayToken();
    
    cout << endl << "Parser and exec: " << endl;
    an.parserAndExec();
    
    cout << endl << "Result:" << endl;
    cout << "        " << str << " = " << an.getResult() << endl << endl;
	
	cin.get();
    
    return 0;
}