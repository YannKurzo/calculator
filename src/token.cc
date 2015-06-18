
//  ==========================================================================
/// @file   token.cc
/// @author Yann Kurzo
/// @date   May 17, 2015, 12:23 AM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  This file defines the Token class. The operator priority is also
///         defined here.
//  ==========================================================================

#include "token.h"

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

Token::Token(tokenType_e type, const std::string &str)
{
    setStr(type, str);
}

Token::tokenType_e Token::getType(void) const
{
    return type_m;
}

std::string Token::getStr(void) const
{
    return str_m;
}

void Token::setStr(tokenType_e type, const std::string &str)
{
    type_m = type;
    str_m = str;
    
    // If it is a number, convert immediately
    if(type_m == eTOKENTYPE_NUMBER)
#if(USE_DOUBLE_TYPE == 1)
        n_m = ::atof(str_m.c_str());
#elif(USE_MPFR_LIBRARY == 1)
        n_m = calculType_t(str_m.c_str());
#endif
    else
        n_m = nan("");
}

calculType_t Token::getN(void) const
{
    return n_m;
}

void Token::setN(calculType_t n)
{
    type_m = eTOKENTYPE_NUMBER;
    n_m = n;
}

priority_e Token::getPriority(void) const
{
    priority_e priority = ePRIORITY_LOWEST;
    
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

