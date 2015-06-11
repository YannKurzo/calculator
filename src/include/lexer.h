
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
		/// @brief  Erase all unnecessary characters of the string
		void cleanString(void);
		
        /// @brief  Throw an exception there is a problem with the brackets
        void checkBrackets(void);
};


#endif	/* LEXER_H */
