
//  ==================================================
/// @file   analyze.h
/// @author Yann Kurzo
/// @date   May 11, 2015, 9:32 PM
/// @license GPL2
/// @brief  Manages the complete calculation process
///         The Analyze class provides a way to complete the calculation
///         of a string entered by the user.
//  ==================================================

#ifndef STRUCT_H
#define	STRUCT_H

#include "token.h"
#include "binTree.h"

#include <string>

/// @brief  This class manages the complete calculation
/// @note   After creating the class with the constructor, the member functions
///         lexer() and parserAndExec() should be called in order before
///         getting the result with the getResult() function.
class Analyse
{ 
    protected:
        /// String to compute
        std::string str_m;
        /// Result of the calculation
        double result_m;
        
        /// List of tokens for the calculation
        TokenVector tokenVector_m;
        
        /// Binary tree to compute the list of tokens
        BinTree *binTree_m;
        
    private:
        void cleanString(void);

    public:
        /// @brief  Construct a calculation process
        /// @param  str String to compute
        Analyse(std::string str);
        
        /// @brief  Destructor
        ~Analyse(void);
        
        /// @brief  Analyzes and separates in tokens the string to compute
        void lexer(void);
        /// @brief  Analyzes the list of tokens and calculates the result
        void parserAndExec(void);

        /// @brief  Get the result
        double getResult() const;

        /// @brief  Display the list of tokens
        void displayToken(void);
};

#endif	/* STRUCT_H */

