
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
        /// List of tokens for the calculation
        std::vector<Token> tokenVector_m;
		
	public:
		/// @brief  Constructor
		/// @param	str String to transform
        Lexer(std::string str);
        
		/// @brief	Start analysing the string
        void start(void);
        
		/// @brief	Get the result
		/// @return Calculated result
		/// @note	Must be called after start()
        std::vector<Token> getTokenVector(void) const;
};


#endif	/* LEXER_H */

