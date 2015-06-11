
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
		/// @note	If the priority is the same, take the first one from the left
        unsigned int findHighestOp(unsigned int lowerIndex, unsigned int upperIndex);
		
		/// @brief	Execute the operator or function at the determined index and update the vector of tokens
		///			It calculates and updates the result token, and it erases the old unnecessary tokens.
		/// @param	index Index of the operator or function
		/// @return The number of token that were erased
        unsigned int exec(unsigned int index);
        
		/// @brief	Calculate with normal operators (+ - * / ^ %)
		/// @param  op Operator string
		/// @param  left Left operand
		/// @param  right Right operand
		/// @return The result of the operation
        double execOperator(std::string op, double left, double right);
		
		/// @brief	Calculate the result of the function
		double execFunction(std::string functionName, unsigned int firstParameterIndex);
		
        
};


#endif	/* BINTREE_H */

