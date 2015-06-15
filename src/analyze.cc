
//  ==========================================================================
/// @file   analyze.cc
/// @author Yann Kurzo
/// @date   May 11, 2015, 9:32 PM
/// @license GPL2
/// @brief  This class manages the complete calculation process.
//  ==========================================================================

#include "analyze.h"
#include "lexer.h"

#include <iostream>

using namespace std;

Analyze::Analyze(const std::string &str)
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
	
#if(ANALYSE_DEBUG == 1)
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

#if(ANALYSE_DEBUG == 1)
void Analyze::displayToken(void) const
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