
//  ==========================================================================
/// @file   lexer.h
/// @author Yann Kurzo
/// @date   June 11, 2015, 2:06 PM
/// @license GPL2
/// @brief  
//  ==========================================================================

#ifndef LEXER_H
#define	LEXER_H

#include "token.h"

#include <string>
#include <vector>

/// @brief  This class simulates a binary tree.
///         
class Lexer
{
    private:
        /// String to compute
        std::string str_m;

        /// List of tokens for the calculation
        TokenVector tokenVector_m;

    public:
        /// @brief  Constructor
        /// @param	str String to transform
        Lexer(std::string str);

        /// @brief	Start analysing the string
        void start(void);

        /// @brief	Get the result
        /// @return Calculated result
        /// @note	Must be called after start()
        TokenVector getTokenVector(void) const;
		
    private:
        /// @brief  Analyses the string and push the corresponding tokens to the vector
        void pushTokens(void);

        /// @brief	Push the number starting at the defined index of the string
        /// @param  startIndex Starting index of the number
        /// @return New index after pushing the number
        unsigned int pushNumber(unsigned int startIndex);
        
        unsigned int pushOpeningBracket(unsigned int startIndex);
        
        unsigned int pushClosingBracket(unsigned int startIndex);
        
        unsigned int pushOperator(unsigned int startIndex);
        
        unsigned int pushComma(unsigned int startIndex);

        /// @brief	Push the function starting at the defined index of the string
        /// @param  startIndex Starting index of the function
        /// @return New index after pushing the number
        unsigned int pushFunction(unsigned int startIndex);

        /// @brief  Erase all unnecessary characters of the string
        void cleanString(void);

        /// @brief  Throw an exception there is a problem with the brackets
        void checkBrackets(void);

        /// @brief  Add the multiplication operator when it is omitted
        /// @note   Before function or opening brackets
        void checkImplicitMultiplication(void);

        /// @brief  Check if the tokens are correct
        void checkTokens(void);
};


#endif	/* LEXER_H */

