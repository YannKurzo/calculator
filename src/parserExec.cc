
//  ==========================================================================
/// @file   parserExec.cc
/// @author Yann Kurzo
/// @date   May 17, 2015, 2:06 AM
/// @license GPL2
/// @brief  Parse the vector of tokens and calculates the mathematical result
//  ==========================================================================

#include "parserExec.h"

#include <iostream>
#include <string>
#include <cmath>

using namespace std;


ParserExec::ParserExec(TokenVector &tokenList)
{
    tokenVector_m = tokenList;
}
        
void ParserExec::start(void)
{
    // First call with the whole vector of tokens
    algo(0, tokenVector_m.size()-1);
}

double ParserExec::getResult(void) const
{
    return tokenVector_m.begin()->getN();
}

unsigned int ParserExec::algo(unsigned int lowerIndex, unsigned int upperIndex)
{
	// While there is more than 1 token or while the last token is not a number
    while(upperIndex - lowerIndex >= 1 || 
		 (upperIndex - lowerIndex == 0 && tokenVector_m[lowerIndex].getType() != Token::eTOKENTYPE_NUMBER))
    {
		// Find highest operator or function
        unsigned int op = findHighestOp(lowerIndex, upperIndex);
        
		// If there is a closing bracket
        if(tokenVector_m[op].getType() == Token::eTOKENTYPE_BRACKET_CLOSE)
        {
            unsigned int closingBracketIndex = op;
            unsigned int openingBracketIndex = op-1;
            
            // Get opening bracket index
            while(tokenVector_m[openingBracketIndex].getType() != Token::eTOKENTYPE_BRACKET_OPEN)
                --openingBracketIndex;
            
            // Update upperIndex
            upperIndex = upperIndex - closingBracketIndex + openingBracketIndex;
            
            // Calculate what is between the bracket recursively
            closingBracketIndex = algo(openingBracketIndex + 1, closingBracketIndex - 1) + 1;
            
            // Erase brackets
            tokenVector_m.erase(tokenVector_m.begin() + openingBracketIndex + 2);
            tokenVector_m.erase(tokenVector_m.begin() + openingBracketIndex);
        }
        else
        {
            // Execute the operator or function and reinitialize upperIndex
            upperIndex -= exec(op);
        }
    }
    return upperIndex;
}

unsigned int ParserExec::findHighestOp(unsigned int lowerIndex, unsigned int upperIndex)
{
    unsigned int ret = lowerIndex;
    int priority = tokenVector_m[lowerIndex].getPriority();
    
    for(unsigned int i = lowerIndex+1; i<=upperIndex; ++i)
    {
        if(tokenVector_m[i].getPriority() < priority)
        {
            priority = tokenVector_m[i].getPriority();
            ret = i;
        }
    }
    return ret;
}

unsigned int ParserExec::exec(unsigned int index)
{
	unsigned int vectorLenghtChange = 0;
	
	// Operator
    if(tokenVector_m[index].getType() == Token::eTOKENTYPE_OPERATOR)
    {
		// Calculate
        tokenVector_m[index].setN(
			execOperator(
				tokenVector_m[index].getStr(),
				tokenVector_m[index-1].getN(),
				tokenVector_m[index+1].getN()
			)
		);
		
		// Erase old token
		tokenVector_m.erase(tokenVector_m.begin()+index+1);
		tokenVector_m.erase(tokenVector_m.begin()+index-1);
		
		// Update vector length
		vectorLenghtChange = 2;
    }
	
	// Functions
	else if(tokenVector_m[index].getType() == Token::eTOKENTYPE_FUNCTION)
	{
		// Calculate
        tokenVector_m[index].setN(
			execFunction(
				tokenVector_m[index].getStr(),
				index + 1
			)
		);
		
		// Erase old token
		unsigned int nbParameters = Function::getNbParameters(tokenVector_m[index].getStr());
		
		for(unsigned int i=index+nbParameters; i>index; --i)
			tokenVector_m.erase(tokenVector_m.begin() + i);
            
		// Update vector length
        vectorLenghtChange = nbParameters;
	}
	
	return vectorLenghtChange;
}

double ParserExec::execOperator(std::string op, double left, double right)
{
	double res = 0;
	
    switch(op.at(0))
    {
        case '+':
            res = left + right;
			break;
        case '-':
            res = left - right;
			break;
        case '*':
            res = left * right;
			break;
        case '/':
            res = left / right;
			break;
        case '^':
            res = pow(left, right);
			break;
        default:
            res = 0;
			break;
    }
	
#ifdef DISPLAY_OPERATIONS
    cout << left << " " << op << " " << right << " = " << res << endl;
#endif

	return res;
}

double ParserExec::execFunction(std::string functionName, unsigned int firstParameterIndex)
{
    // Number of parameters
    unsigned int nbPar = Function::getNbParameters(functionName);
    double par[MAX_NUMBER_PARAMETERS];
    
    // Set parameters
    for(unsigned int i=0; i<nbPar; ++i)
        par[i] = tokenVector_m[firstParameterIndex+i].getN();
    
    // Result with MAX_NUMBER_PARAMETERS = 5
#if(MAX_NUMBER_PARAMETERS != 5)
	#error "Adapt the code here!"
#endif
    double res = call(functionName, par[0], par[1], par[2], par[3], par[4]);
    
#ifdef DISPLAY_OPERATIONS
        cout << functionName << "(";
        if(nbPar > 0)
        {
            for(unsigned int i=0; i<nbPar-1; ++i)
                cout << tokenVector_m[firstParameterIndex+i] << ", ";
            cout << tokenVector_m[firstParameterIndex+nbPar-1];
        }
        cout << ") = " << res << endl;
#endif

	return res;
}
