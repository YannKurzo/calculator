
//  ==========================================================================
/// @file   lexer.cc
/// @author Yann Kurzo
/// @date   June 11, 2015, 2:06 PM
/// @license GPL2
/// @brief  
//  ==========================================================================

#include "lexer.h"

using namespace std;


Lexer::Lexer(std::string str)
{
	str = "";
}

void Lexer::start(void)
{
	
}

std::vector<Token> Lexer::getTokenVector(void) const
{
	return tokenVector_m;
}
