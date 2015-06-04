
/*==================================================
 *
 * File:    analyse.cc
 * 
 * Author:  Yann Kurzo
 *
 * Date:    May 11, 2015, 9:35 PM
 *
 * license: GPL2
 *
 ==================================================*/

#include "analyse.h"

#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;

Analyse::Analyse(std::string str)
{
    str_m = str;
    result_m = 0;
}

Analyse::~Analyse(void)
{
    delete binTree_m;
}

void Analyse::cleanString(void)
{
    str_m.erase(std::remove_if(str_m.begin(), str_m.end(), ::isspace), str_m.end());
}


void Analyse::lexer(void) {
    // Erase unnecessary char
    cleanString();
    
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
                // If it is closing immediately, erase them
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

void Analyse::parserAndExec(void)
{
    binTree_m = new BinTree(tokenVector_m);
    
    result_m = binTree_m->getResult();
}

double Analyse::getResult() const 
{
    return result_m;
}

void Analyse::displayToken(void)
{
    for(ListIt it = tokenVector_m.begin(); it!=tokenVector_m.end(); ++it)
    {
        cout << "\"" << *it<< "\" ";
    }
    cout << endl;
}