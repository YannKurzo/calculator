
//  ==========================================================================
/// @file   lexer.h
/// @author Yann Kurzo
/// @date   June 11, 2015, 2:06 PM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  This file defines the Lexer class.
//  ==========================================================================

#ifndef LEXER_H
#define	LEXER_H

#include "token.h"

#include <string>
#include <vector>

/// @brief  This class is used to separate the string in different tokens. It also
///			throws an exception in case the string format is not correct.   
class Lexer
{
    protected:
        /// String to compute
        std::string str_m;

        /// List of tokens for the calculation
        TokenVector tokenVector_m;

    public:
        /// @brief  Constructor
        /// @param	str String to transform
        Lexer(const std::string &str);

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
        
        /// @brief	Push an opening bracket
        /// @param  startIndex Starting index of the number
        /// @return New index after pushing the number
        unsigned int pushOpeningBracket(unsigned int startIndex);
        
        /// @brief	Push a closing bracket
        /// @param  startIndex Starting index of the number
        /// @return New index after pushing the number
        unsigned int pushClosingBracket(unsigned int startIndex);
        
        /// @brief	Push an operator
        /// @param  startIndex Starting index of the number
        /// @return New index after pushing the number
        unsigned int pushOperator(unsigned int startIndex);
        
        /// @brief	Push a comma
        /// @param  startIndex Starting index of the number
        /// @return New index after pushing the number
        unsigned int pushComma(unsigned int startIndex);

        /// @brief	Push the function or constant starting at the defined index of the string
        /// @param  startIndex Starting index of the function / constant
        /// @return New index after pushing the number
        unsigned int pushFunctionOrConstant(unsigned int startIndex);

        /// @brief  Erase all unnecessary characters of the string
        void cleanString(void);

        /// @brief  Throw an exception there is a problem with the brackets
        void checkBrackets(void);

        /// @brief  Add the multiplication operator when it is omitted
        /// @note   Add only before a function or an opening bracket
        void checkImplicitMultiplication(void);

        /// @brief  Check if the tokens are correct
        void checkTokens(void);
};


#endif	/* LEXER_H */

