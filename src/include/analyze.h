
//  ==========================================================================
/// @file   analyze.h
/// @author Yann Kurzo
/// @date   May 11, 2015, 9:32 PM
/// @license GPL2
/// @brief  Manages the complete calculation process
///         The Analyze class provides a way to complete the calculation
///         of a string entered by the user.
//  ==========================================================================

#ifndef ANALYZE_H
#define	ANALYZE_H

#include "token.h"
#include "parserExec.h"

#include <string>

/// @brief	Define to show the vector of tokens after the lexer process
#define ANALYSE_DEBUG

/// @brief  This class manages the complete calculation
/// @note   After creating the class with the constructor, the member functions
///         lexer() and parserAndExec() should be called in order before
///         getting the result with the getResult() function.
class Analyze
{ 
    protected:
        /// String to compute
        std::string str_m;
		
        /// Result of the calculation
        double result_m;
        
        /// List of tokens for the calculation
        TokenVector tokenVector_m;
		
		/// Enumeration to check the actual process
		typedef enum
		{
			eNOTHING_DONE,
			eLEXER_DONE,
			ePARSEREXEC_DONE
		}actualProcess_e;
		
		/// Actual process
		actualProcess_e actualProcess_m;

    public:
        /// @brief  Construct a calculation process
        /// @param  str String to compute
        Analyze(std::string str);
        
        /// @brief  Analyses and separates in tokens the string to compute
        void lexer(void);
        
        /// @brief  Analyses the list of tokens and calculates the result
        void parserExec(void);

        /// @brief  Get the result
        double getResult();

#ifdef ANALYSE_DEBUG
	private:
        /// @brief  Display the list of tokens
		/// @note	Debug utility
        void displayToken(void);
#endif
};

#endif	/* ANALYZE_H */

