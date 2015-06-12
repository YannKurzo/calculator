
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
	actualProcess_m = Analyze::eNOTHING_DONE;
}

void Analyze::lexer(void)
{    
	Lexer lexer_m(str_m);
	lexer_m.start();
	tokenVector_m = lexer_m.getTokenVector();
	
	// Update process
	actualProcess_m = eLEXER_DONE;
	
#ifdef ANALYSE_DEBUG
	// Display tokens for debug
	displayToken();
#endif
}

void Analyze::parserExec(void)
{
	// Check if the previous process has been done
	if(actualProcess_m < eLEXER_DONE)
	{
		lexer();
	}
	
    ParserExec parserExec_m(tokenVector_m);
    parserExec_m.start();
    result_m = parserExec_m.getResult();
	
	// Update process
	actualProcess_m = ePARSEREXEC_DONE;
}

double Analyze::getResult() 
{
	// Check if the previous process has been done
	if(actualProcess_m < ePARSEREXEC_DONE)
	{
		parserExec();
	}
	
    return result_m;
}

#ifdef ANALYSE_DEBUG
void Analyze::displayToken(void)
{
	if(actualProcess_m >= eLEXER_DONE)
	{
		for(unsigned int i=0; i<tokenVector_m.size(); ++i)
		{
			cout << "\"" << tokenVector_m[i] << "\" ";
		}
		cout << endl;
	}
	else
	{
		cout << "The lexer method must be called first!" << endl;	
	}
}
#endif