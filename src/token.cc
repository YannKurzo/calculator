
//  ==================================================
/// @file   token.h
/// @author Yann Kurzo
/// @date   May 17, 2015, 12:23 AM
/// @license GPL2
/// @brief  A token represents a part of the input string.
///         The string can be separated in multiple tokens. The following types
///         are used: Closing brackets, Opening brackets, Functions, Operators,
///         ... The operator priority is also defined here.
//  ==================================================

#include "token.h"

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;


Token::Token(tokenType_t type, std::string str)
{
    setStr(type, str);
}

Token::tokenType_t Token::getType(void) const
{
    return type_m;
}

std::string Token::getStr(void) const
{
    return str_m;
}

void Token::setStr(tokenType_t type, std::string str)
{
    type_m = type;
    str_m = str;
    
    // If it is a number, convert immediately
    if(type_m == NUMBER)
        n_m = ::atof(str_m.c_str());
    else
        n_m = nan("");
}

double Token::getN(void) const
{
    return n_m;
}

void Token::setN(double n)
{
    type_m = NUMBER;
    n_m = n;
}

priority_t Token::getPriority(void) const
{
    priority_t priority = P_LOWER;
    
    switch(type_m)
    {
        case OPERATOR:
            priority = operatorPriority[operators.find(str_m)];
            break;
        case BRACKET_CLOSE:
            priority = P_BRACKET_CLOSE;
            break;
        case BRACKET_OPEN:
            priority = P_BRACKET_OPEN;
            break;
        case FUNCTION:
            priority = P_FUNCTION;
            break;
        default:
            priority = P_LOWER;
            break;
    }
    
    return priority;
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

