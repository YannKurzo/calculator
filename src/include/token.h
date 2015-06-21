
//  ==========================================================================
/// @file   token.h
/// @author Yann Kurzo
/// @date   May 17, 2015, 12:23 AM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  This file defines the Token class. The operator priority is also
///         defined here.
//  ==========================================================================

#ifndef TOKEN_H
#define	TOKEN_H

#include "mpfrInterface.h"

#include <string>
#include <vector>
    
/// @brief  Enumeration that determines the token priority from high to low
typedef enum
{
    ePRIORITY_BRACKET_CLOSE,
    ePRIORITY_BRACKET_OPEN,
    ePRIORITY_FUNCTION,
    ePRIORITY_UNARY_MINUS,
    ePRIORITY_OP_POWER,
    ePRIORITY_OP_MUL_DIV,
    ePRIORITY_OP_PLUS_MINUS,
    ePRIORITY_OP_MODULO,
    ePRIORITY_LOWEST
}priority_e;

/// @brief  Defines the opening brackets
static const std::string bracketsOpen = "(";
/// @brief  Defines the closing brackets
static const std::string bracketsClose = ")";

/// @brief  Defines the different operators
static const std::string operators = "^*/+-%";
/// @brief  Defines the operator priority
static const priority_e operatorPriority[] =
{
    ePRIORITY_OP_POWER,
    ePRIORITY_OP_MUL_DIV,
    ePRIORITY_OP_MUL_DIV,
    ePRIORITY_OP_PLUS_MINUS,
    ePRIORITY_OP_PLUS_MINUS,
    ePRIORITY_OP_MODULO
};

/// @brief  Defines the different tokens and their own priority
static const priority_e tokenPriority[] =
{
    ePRIORITY_BRACKET_CLOSE,
    ePRIORITY_BRACKET_OPEN,
    ePRIORITY_FUNCTION,
    ePRIORITY_UNARY_MINUS,
    ePRIORITY_LOWEST,
    ePRIORITY_LOWEST,
    ePRIORITY_LOWEST
};

/// @brief  This class handles a token which represents a part of the input string.
///         The string can be separated in multiple tokens. The following types
///         are used: Closing brackets, Opening brackets, Functions, Operators, ...
class Token
{
    public:
        /// @brief  Enumeration to determine the type of the token
        typedef enum
        {
            eTOKENTYPE_BRACKET_CLOSE,
            eTOKENTYPE_BRACKET_OPEN,
            eTOKENTYPE_FUNCTION,
            eTOKENTYPE_UNARY_MINUS,
            eTOKENTYPE_OPERATOR,
            eTOKENTYPE_NUMBER,
            eTOKENTYPE_COMMA 
        }tokenType_e;
        
    protected:
        /// To store the type of the token
        tokenType_e type_m;
        
        /// To store the string of the token
        std::string str_m;
        
        /// To convert to number if the token is a number
        calculType_t n_m;
        
    public:
        /// @brief  Constructor
        /// @param  type Type of the token
        /// @param  str String of the token
        Token(tokenType_e type, const std::string &str);
        
        /// @brief  Get type of the token
        tokenType_e getType(void) const;
        
        /// @brief  Get string of the token
        std::string getStr(void) const;
        /// @brief  Set string with type
        void setStr(tokenType_e type, const std::string &str);
        
        /// @brief  Get value of the token
        calculType_t getN(void) const;
        /// @brief  Set value of the token
        void setN(calculType_t n);
        
        /// @brief  Get the priority of the token
        priority_e getPriority(void) const;
        
        /// @brief  Used to display the token with standard output
        void display(std::ostream& flow) const;
};

/// @cond STANDARD_OUTPUT
std::ostream& operator<<(std::ostream& flow, Token const& token);
/// @endcond STANDARD_OUTPUT

/// @brief  Vector of tokens
typedef std::vector<Token> TokenVector;


#endif	/* TOKEN_H */

