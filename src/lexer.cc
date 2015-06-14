
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

#include <iostream>
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
	
    // Check brackets
    checkBrackets();
	
	// Push every token from the string
	pushTokens();
	
	// Check implicit multiplication
	checkImplicitMultiplication();
	
    // Check tokens
	checkTokens();
}

TokenVector Lexer::getTokenVector(void) const
{
	return tokenVector_m;
}

void Lexer::pushTokens(void)
{
	// Opening bracket at beginning
	tokenVector_m.push_back(Token(Token::eTOKENTYPE_BRACKET_OPEN, "("));
	
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
            i = pushOpeningBracket(i);
            
		}
		else if(bracketsClose.find(c) != string::npos)
		{
			tokenVector_m.push_back(Token(Token::eTOKENTYPE_BRACKET_CLOSE, str_m.substr(i, 1)));
		}
		// Check operators
		else if(operators.find(c) != string::npos)
		{
			tokenVector_m.push_back(Token(Token::eTOKENTYPE_OPERATOR, str_m.substr(i, 1)));
            
            // Check unary minus '-'
            if(c == '-')
            {
                Token::tokenType_t type = tokenVector_m.at(tokenVector_m.size()-2).getType();
                
                // If it is the first of the string OR if last one was an operator or an opening bracket
                if(i == 0 || type == Token::eTOKENTYPE_OPERATOR ||
                             type == Token::eTOKENTYPE_BRACKET_OPEN)
                {
                    tokenVector_m.at(tokenVector_m.size()-1).setStr(Token::eTOKENTYPE_UNARY_MINUS, "--");
                }
            }
		}
		// Check separator, replace by brackets to optimize calculation
		else if(c == ',')
		{
			tokenVector_m.push_back(Token(Token::eTOKENTYPE_BRACKET_CLOSE, ")"));
			tokenVector_m.push_back(Token(Token::eTOKENTYPE_COMMA, ","));
			tokenVector_m.push_back(Token(Token::eTOKENTYPE_BRACKET_OPEN, "("));
		}
		// Functions
		else
		{
			i = pushFunction(i);
		}
    }
	
	// Closing bracket at ending
	tokenVector_m.push_back(Token(Token::eTOKENTYPE_BRACKET_CLOSE, ")"));
}

unsigned int Lexer::pushOpeningBracket(unsigned int startIndex)
{
    // If it is not "()", ok, else skip
    if(str_m.at(startIndex+1) != ')')
    {
        tokenVector_m.push_back(Token(Token::eTOKENTYPE_BRACKET_OPEN, str_m.substr(startIndex, 1)));
    }
    else
    {
        ++startIndex;
    }
    
    return startIndex;
}

unsigned int Lexer::pushNumber(unsigned int startIndex)
{
	unsigned int stopIndex = startIndex + 1;
	
	// While it is not the end of the string and it is part of a number (digit or .)
	while(stopIndex<str_m.length() && (isdigit(str_m.at(stopIndex)) || str_m.at(stopIndex) == '.'))
		++stopIndex;
            
    tokenVector_m.push_back(Token(Token::eTOKENTYPE_NUMBER, str_m.substr(startIndex, stopIndex-startIndex)));
            
	return stopIndex - 1;
}

unsigned int Lexer::pushFunction(unsigned int startIndex)
{
	unsigned int stopIndex = startIndex + 1;
	
	// While it is not the end of the string and it is not an opening bracket
	// Every character but the opening bracket can be considered as part of the function!
	while(stopIndex<str_m.length() && !(bracketsOpen.find(str_m.at(stopIndex)) != string::npos))
		++stopIndex;

	tokenVector_m.push_back(Token(Token::eTOKENTYPE_FUNCTION, str_m.substr(startIndex, stopIndex-startIndex)));
	
	// Check if function exists
	if(Function::getFunction(tokenVector_m.back().getStr()) == NULL)
	{
		THROW("Function " + tokenVector_m.back().getStr() + "() is not implemented!");
	}
	// Check for brackets when at the end of the string
	else if(stopIndex == str_m.length())
	{
		THROW("Missing brackets at function " + tokenVector_m.back().getStr() + "()!");
	}
	
	// If there is no parameter to this function, skip the brackets
	if(Function::getNbParameters(tokenVector_m.back().getStr()) == 0)
	{
        if(str_m.substr(stopIndex, 2) != "()")
        {
            THROW("Too much parameters!");
        }
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
		{
            ++bracketsCount;
			
			if(operators.find(str_m.at(i+1)) != string::npos && str_m.at(i+1) != '-')
			{
				THROW("Operators cannot follow an opening bracket!");
			}
			else if(str_m.at(i+1) == ',')
			{
				THROW("Comma ',' cannot follow an opening bracket!");
			}
		}
        
        else if(bracketsClose.find(str_m.at(i)) != string::npos)
		{
            --bracketsCount;
		}
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

void Lexer::checkImplicitMultiplication(void)
{
	for(unsigned int i=0; i<tokenVector_m.size()-1; ++i)
    {
        // If it is a number
        if(tokenVector_m.at(i).getType() == Token::eTOKENTYPE_NUMBER)
        {
            // If next one is a function or an opening bracket
            if(tokenVector_m.at(i+1).getType() == Token::eTOKENTYPE_FUNCTION ||
               tokenVector_m.at(i+1).getType() == Token::eTOKENTYPE_BRACKET_OPEN)
            {
                // Add multiplication operator
                tokenVector_m.insert(tokenVector_m.begin()+i+1,
                    Token(Token::eTOKENTYPE_OPERATOR, "*"));
                
                ++i;
            }
        }
    }
}

void Lexer::checkTokens(void)
{
	for(unsigned int i=1; i<tokenVector_m.size()-1; ++i)
    {
        Token::tokenType_t type = tokenVector_m.at(i).getType();
        Token::tokenType_t typeNext = tokenVector_m.at(i+1).getType();
        
        // Check operators
        if(type == Token::eTOKENTYPE_OPERATOR ||
           type == Token::eTOKENTYPE_UNARY_MINUS)
        {
            if(typeNext == Token::eTOKENTYPE_OPERATOR)
            {
                THROW("Multiple operator in a row!");
            }
            if(typeNext == Token::eTOKENTYPE_BRACKET_CLOSE ||
               typeNext == Token::eTOKENTYPE_COMMA)
            {
                THROW("There must be a number or a function right to an operator!");
            }
        }
    }
}