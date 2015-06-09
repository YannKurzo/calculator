
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

#ifndef TOKEN_H
#define	TOKEN_H

#include <string>

    
/// @brief  Enumeration that determines the token priority from high to low
typedef enum
{
    P_BRACKET_CLOSE,
    P_BRACKET_OPEN,
    P_FUNCTION,
    P_OP_POWER,
    P_OP_MUL_DIV,
    P_OP_PLUS_MINUS,
    P_OP_MODULO,
    P_LOWER
}priority_t;

/// @brief  Defines the brackets
static std::string bracketsOpen = "(";
static std::string bracketsClose = ")";

/// @brief  Defines the different operators and their own priority
static std::string operators = "^*/+-%";
static priority_t operatorPriority[] =
{
    P_OP_POWER,
    P_OP_MUL_DIV,
    P_OP_MUL_DIV,
    P_OP_PLUS_MINUS,
    P_OP_PLUS_MINUS,
    P_OP_MODULO
};

/// @brief  This class is used to store each token of the string
class Token
{
    public:
        /// @brief  Enumeration to determine the type of the token
        typedef enum
        {
            BRACKET_CLOSE, BRACKET_OPEN, FUNCTION, OPERATOR, NUMBER, COMMA 
        }tokenType_t;
        
    protected:
        /// To store the type of the token
        tokenType_t type_m;
        
        /// To store the string of the token
        std::string str_m;
        
        /// To convert to number if the token is a number
        double n_m;
        
    public:
        /// @brief  Constructor
        /// @param  type Type of the token
        /// @param  str String of the token
        Token(tokenType_t type, std::string str);
        
        /// @brief  Get type of the token
        tokenType_t getType(void) const;
        
        /// @brief  Get string of the token
        std::string getStr(void) const;
        /// @todo   Set string with type
        void setStr(tokenType_t type, std::string str);
        
        /// @brief  Get value of the token
        double getN(void) const;
        /// @brief  Set value of the token
        void setN(double n);
        
        /// @brief  Get the priority of the token
        priority_t getPriority(void) const;
        
        /// @brief  Used to display the token with standard output
        void display(std::ostream& flow) const;
};

/// @brief  Standard output
std::ostream& operator<<(std::ostream& flow, Token const& token);


#endif	/* TOKEN_H */

