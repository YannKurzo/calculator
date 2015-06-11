
//  ==========================================================================
/// @file   lexer.cc
/// @author Yann Kurzo
/// @date   June 11, 2015, 2:06 PM
/// @license GPL2
/// @brief  
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
	
    // // Check tokens
	
    // // Check brackets
    // checkBrackets();
    
    unsigned int j;
    // Check whole input string
    for(unsigned int i=0; i<str_m.length(); ++i)
    {
        char c = str_m.at(i);
        // Check digit and numbers
        if(isdigit(c))
        {
            j = i + 1;
            while(j<str_m.length() && (isdigit(str_m.at(j)) || str_m.at(j) == '.'))
                ++j;
            
            tokenVector_m.push_back(Token(Token::eTOKENTYPE_NUMBER, str_m.substr(i, j-i)));
            
            i = j-1;
        }
        else
        {
            // Check brackets
            if(bracketsOpen.find(c) != string::npos)
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
            // Check separator
            else if(c == ',')
            {
                tokenVector_m.push_back(Token(Token::eTOKENTYPE_BRACKET_CLOSE, ")"));
                tokenVector_m.push_back(Token(Token::eTOKENTYPE_BRACKET_OPEN, "("));
            }
            // Functions
            else
            {
                j = i + 1;
                while(j<str_m.length() && !(bracketsOpen.find(str_m.at(j)) != string::npos ||
                        bracketsClose.find(str_m.at(j)) != string::npos ||
                        operators.find(str_m.at(j)) != string::npos || isdigit(str_m.at(j))))
                    ++j;

                tokenVector_m.push_back(Token(Token::eTOKENTYPE_FUNCTION, str_m.substr(i, j-i)));
                
                // // Check if function exists
                // if(Function::getFunction(tokenVector_m.back().getStr()) == NULL)
                // {
                    // THROW("Function " + tokenVector_m.back().getStr() + "() is not implemented!");
                // }

                i = j-1;
                
				// If there is no parameter
                if(Function::getNbParameters(tokenVector_m.back().getStr()) == 0)
                {
					// Skip the brackets
                    i+=2;
                }
            }
        }
    }
}

TokenVector Lexer::getTokenVector(void) const
{
	return tokenVector_m;
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