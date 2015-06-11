
//  ==========================================================================
/// @file   analyze.cc
/// @author Yann Kurzo
/// @date   May 11, 2015, 9:32 PM
/// @license GPL2
/// @brief  Manages the complete calculation process
///         The Analyze class provides a way to complete the calculation
///         of a string entered by the user.
//  ==========================================================================

#include "analyze.h"
#include "lexer.h"

#include <iostream>

using namespace std;

Analyze::Analyze(std::string str)
{
    str_m = str;
    result_m = 0;
}

void Analyze::lexer(void)
{    
	Lexer lexer_m(str_m);
	
	lexer_m.start();
	
	tokenVector_m = lexer_m.getTokenVector();
}

void Analyze::parserExec(void)
{
    ParserExec parserExec_m(tokenVector_m);
    
    parserExec_m.start();
    
    result_m = parserExec_m.getResult();
}

double Analyze::getResult() const 
{
    return result_m;
}

void Analyze::displayToken(void)
{
	for(unsigned int i=0; i<tokenVector_m.size(); ++i)
    {
        cout << "\"" << tokenVector_m[i] << "\" ";
    }
    cout << endl;
}