
//  ==========================================================================
/// @file   token.cc
/// @author Yann Kurzo
/// @date   May 17, 2015, 12:23 AM
/// @license GPL2
/// @brief  This file defines the Token class. The operator priority is also
///         defined here.
//  ==========================================================================

#include "token.h"

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

Token::Token(tokenType_t type, const std::string &str)
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

void Token::setStr(tokenType_t type, const std::string &str)
{
    type_m = type;
    str_m = str;
    
    // If it is a number, convert immediately
    if(type_m == eTOKENTYPE_NUMBER)
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
    type_m = eTOKENTYPE_NUMBER;
    n_m = n;
}

priority_t Token::getPriority(void) const
{
    priority_t priority = ePRIORITY_LOWEST;
    
    switch(type_m)
    {
        case eTOKENTYPE_OPERATOR:
            priority = operatorPriority[operators.find(str_m)];
            break;
        default:
            priority = tokenPriority[type_m];
            break;
    }
    
    return priority;
}

void Token::display(std::ostream& flow) const
{
    if(type_m == eTOKENTYPE_NUMBER)
        flow << n_m;
    else
        flow << str_m;
}

std::ostream& operator<<(std::ostream& flow, Token const& token)
{
    token.display(flow);
    return flow;
}

