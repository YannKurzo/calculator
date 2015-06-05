
/*==================================================
 *
 * File:    token.cc
 * 
 * Author:  Yann Kurzo
 *
 * Date:    May 17, 2015, 12:23 AM
 *
 * license: GPL2
 *
 ==================================================*/

#include "token.h"

#include <iostream>
#include <cstdlib>

using namespace std;


Token::Token(const Token &token)
{
    type_m = token.type_m;
    str_m = token.str_m;
    n_m = token.n_m;
}

Token::Token(tokenType_t type, std::string str)
{
    type_m = type;
    str_m = str;
    
    if(type_m == NUMBER)
        n_m = ::atof(str_m.c_str());
}

int Token::getOpPriority(void) const
{
    switch(type_m)
    {
        case OPERATOR:
            return opPriority[operators.find(str_m)];
        case BRACKET_CLOSE:
            return P_BRACKET_CLOSE;
        case BRACKET_OPEN:
            return P_BRACKET_OPEN;
        case FUNCTION:
            return P_FUNCTION;
        default:
            return P_LOWER;
    }
}

int Token::getType(void) const
{
    return type_m;
}

void Token::setType(tokenType_t type)
{
    type_m = type;
}

double Token::getN(void) const
{
    return n_m;
}

void Token::setN(double n)
{
    n_m = n;
}

std::string Token::getStr(void) const
{
    return str_m;
}

void Token::display(std::ostream& flow) const
{
    if(type_m == NUMBER)
        flow << n_m;
    else
        flow << str_m;
}

std::ostream& operator<<(std::ostream& flow, Token const& token)
{
    token.display(flow);
    return flow;
}

