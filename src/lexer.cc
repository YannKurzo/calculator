
//  ==========================================================================
/// @file   lexer.cc
/// @author Yann Kurzo
/// @date   June 11, 2015, 2:06 PM
/// @license GPL2
/// @brief  This class separates the string in different tokens. It also
///			throws an exception in case the string has a problem in its
///			format.
//  ==========================================================================

#include "lexer.h"
#include "function.h"

#include <cctype>
#include <algorithm>
#include <exception>

using namespace std;

#define THROW(str) throw runtime_error(str);

Lexer::Lexer(std::string str)
{
	str_m = str;
}

void Lexer::start(void)
{
    // Erase unnecessary char
    cleanString();
	
	// Push every token from the string
	pushTokens();
	
    // // Check tokens
	
    // // Check brackets
    // checkBrackets();
    
}

TokenVector Lexer::getTokenVector(void) const
{
	return tokenVector_m;
}

void Lexer::pushTokens(void)
{
    // Check whole input string
    for(unsigned int i=0; i<str_m.length(); ++i)
    {
        char c = str_m.at(i);
        // Check digit and numbers
        if(isdigit(c))
        {
			i = pushNumber(i);
        }
        // Check brackets
        else if(bracketsOpen.find(c) != string::npos)
		{
			tokenVector_m.push_back(Token(Token::eTOKENTYPE_BRACKET_OPEN, str_m.substr(i, 1)));
		}
		else if(bracketsClose.find(c) != string::npos)
		{
			tokenVector_m.push_back(Token(Token::eTOKENTYPE_BRACKET_CLOSE, str_m.substr(i, 1)));
		}
		// Check operators
		else if(operators.find(c) != string::npos)
		{
			tokenVector_m.push_back(Token(Token::eTOKENTYPE_OPERATOR, str_m.substr(i, 1)));
		}
		// Check separator, replace by brackets to optimize calculation
		else if(c == ',')
		{
			tokenVector_m.push_back(Token(Token::eTOKENTYPE_BRACKET_CLOSE, ")"));
			tokenVector_m.push_back(Token(Token::eTOKENTYPE_BRACKET_OPEN, "("));
		}
		// Functions
		else
		{
			i = pushFunction(i);
		}
    }
}

unsigned int Lexer::pushNumber(unsigned int startIndex)
{
	unsigned int stopIndex = startIndex + 1;
	
	// While it is part of a number (digit or .)
	while(stopIndex<str_m.length() && (isdigit(str_m.at(stopIndex)) || str_m.at(stopIndex) == '.'))
		++stopIndex;
            
    tokenVector_m.push_back(Token(Token::eTOKENTYPE_NUMBER, str_m.substr(startIndex, stopIndex-startIndex)));
            
	return stopIndex - 1;
}

unsigned int Lexer::pushFunction(unsigned int startIndex)
{
	unsigned int stopIndex = startIndex + 1;
	
	// While it is not an opening bracket
	while(stopIndex<str_m.length() && !(bracketsOpen.find(str_m.at(stopIndex)) != string::npos ||
			bracketsClose.find(str_m.at(stopIndex)) != string::npos ||
			operators.find(str_m.at(stopIndex)) != string::npos || isdigit(str_m.at(stopIndex))))
		++stopIndex;

	tokenVector_m.push_back(Token(Token::eTOKENTYPE_FUNCTION, str_m.substr(startIndex, stopIndex-startIndex)));
	
	// // Check if function exists
	// if(Function::getFunction(tokenVector_m.back().getStr()) == NULL)
	// {
		// THROW("Function " + tokenVector_m.back().getStr() + "() is not implemented!");
	// }
	
	// If there is no parameter, skip the brackets
	if(Function::getNbParameters(tokenVector_m.back().getStr()) == 0)
	{
		stopIndex += 2;
	}
	
	return stopIndex - 1;
}

void Lexer::cleanString(void)
{
    str_m.erase(std::remove_if(str_m.begin(), str_m.end(), ::isspace), str_m.end());
}

void Lexer::checkBrackets(void)
{
    int bracketsCount = 0;
    
    // Check whole input string
    for(unsigned int i=0; i<str_m.length(); ++i)
    {
        // Check brackets
        if(bracketsOpen.find(str_m.at(i)) != string::npos)
            ++bracketsCount;
        
        else if(bracketsClose.find(str_m.at(i)) != string::npos)
            --bracketsCount;
    }
    
    if(bracketsCount != 0)
    {
        if(bracketsCount > 0)
        {
            THROW("Missing " + std::to_string(bracketsCount) + " closing brackets!");
        }
        else
        {
            THROW("Missing " + std::to_string(-bracketsCount) + " opening brackets!");
        }
    }
}