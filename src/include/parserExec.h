
//  ==================================================
/// @file   binTree.h
/// @author Yann Kurzo
/// @date   May 17, 2015, 2:06 AM
/// @license GPL2
/// @brief  
//  ==================================================

#ifndef BINTREE_H
#define	BINTREE_H

#include "token.h"
#include "function.h"

#include <vector>

#define DISPLAY_OPERATIONS

typedef std::vector<Token> TokenVector;
typedef TokenVector::iterator ListIt;

/// @brief  This class simulates a binary tree.
///         
class ParserExec
{
    private:
        /// List of tokens for the calculation
        TokenVector tokenVector_m;
        
    public:
		/// @brief  Constructor
		/// @param	TokenVector Vector of tokens to analyse
        ParserExec(TokenVector &tokenList);
        
		/// @brief	Start analysing the vector of tokens
        void start(void);
        
		/// @brief	Get the result
		/// @return Result
		/// @note	Must be called after start()
        double getResult(void) const;
        
    private:
		/// @brief	Analyse recursively the vector of tokens between 2 indexes
		/// @param	lowerIndex Lower index
		/// @param  upperIndex Upper index
		/// @return New upper index
        unsigned int algo(unsigned int lowerIndex, unsigned int upperIndex);
		
		/// @brief	Find operator with highest priority between 2 indexes
		/// @param	lowerIndex Lower index
		/// @param  upperIndex Upper index
		/// @return Return the index of the highest operator priority
        unsigned int findHighestOp(unsigned int lowerIndex, unsigned int upperIndex);
		
		/// @brief	Execute the function at the determined index and update the vector of tokens
		/// @param	functionIndex Index of the function
		/// @return Number of parameters used by the function
        unsigned int exec(unsigned int functionIndex);
		
		/// @brief	Execute the function at the determined index and update the vector of tokens
        void exec(Token &root, Token &left, Token &right);
        
        double execOperator(char op, double left, double right);
        
};


#endif	/* BINTREE_H */

