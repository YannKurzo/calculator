
//  ==================================================
/// @file   analyze.h
/// @author Yann Kurzo
/// @date   May 11, 2015, 9:32 PM
/// @license GPL2
/// @brief  Manages the complete calculation process
///         The Analyze class provides a way to complete the calculation
///         of a string entered by the user.
//  ==================================================

#include "analyze.h"

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <exception>

using namespace std;

#define THROW(str) throw runtime_error(str);

Analyze::Analyze(std::string str)
{
    str_m = str;
    result_m = 0;
}

Analyze::~Analyze(void)
{
    delete binTree_m;
}

void Analyze::cleanString(void)
{
    str_m.erase(std::remove_if(str_m.begin(), str_m.end(), ::isspace), str_m.end());
}

void Analyze::checkBrackets(void)
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


void Analyze::lexer(void)
{
    // Erase unnecessary char
    cleanString();
    
    // Check brackets
    checkBrackets();
    
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
            
            tokenVector_m.push_back(Token(Token::NUMBER, str_m.substr(i, j-i)));
            
            i = j-1;
        }
        else
        {
            // Check brackets
            if(bracketsOpen.find(c) != string::npos)
            {
                tokenVector_m.push_back(Token(Token::BRACKET_OPEN, str_m.substr(i, 1)));
            }
            else if(bracketsClose.find(c) != string::npos)
            {
                tokenVector_m.push_back(Token(Token::BRACKET_CLOSE, str_m.substr(i, 1)));
            }
            // Check operators
            else if(operators.find(c) != string::npos)
            {
                tokenVector_m.push_back(Token(Token::OPERATOR, str_m.substr(i, 1)));
            }
            // Check separator
            else if(c == ',')
            {
                tokenVector_m.push_back(Token(Token::BRACKET_CLOSE, ")"));
                tokenVector_m.push_back(Token(Token::BRACKET_OPEN, "("));
            }
            // Functions
            else
            {
                j = i + 1;
                while(j<str_m.length() && !(bracketsOpen.find(str_m.at(j)) != string::npos ||
                        bracketsClose.find(str_m.at(j)) != string::npos ||
                        operators.find(str_m.at(j)) != string::npos || isdigit(str_m.at(j))))
                    ++j;

                tokenVector_m.push_back(Token(Token::FUNCTION, str_m.substr(i, j-i)));
                
                // Check if function exists
                if(Function::getFunction(tokenVector_m.back().getStr()) == NULL)
                {
                    THROW("Function " + tokenVector_m.back().getStr() + "() is not implemented!");
                }

                i = j-1;
                
                if(Function::getNbParameters(tokenVector_m.back().getStr()) == 0)
                {
                    tokenVector_m.push_back(Token(Token::BRACKET_OPEN, str_m.substr(i+1, 1)));
                    tokenVector_m.push_back(Token(Token::NUMBER, "0"));
                    tokenVector_m.push_back(Token(Token::BRACKET_CLOSE, str_m.substr(i+2, 1)));
                    i+=2;
                }
            }
        }
    }
}

void Analyze::parserAndExec(void)
{
    binTree_m = new BinTree(tokenVector_m);
    
    result_m = binTree_m->getResult();
}

double Analyze::getResult() const 
{
    return result_m;
}

void Analyze::displayToken(void)
{
    for(ListIt it = tokenVector_m.begin(); it!=tokenVector_m.end(); ++it)
    {
        cout << "\"" << *it<< "\" ";
    }
    cout << endl;
}