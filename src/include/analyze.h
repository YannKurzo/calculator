
//  ==========================================================================
/// @file   analyze.h
/// @author Yann Kurzo
/// @date   May 11, 2015, 9:32 PM
/// @license GPL2
/// @brief  This class manages the complete calculation process.
//  ==========================================================================

#ifndef ANALYZE_H
#define	ANALYZE_H

#include "token.h"
#include "parserExec.h"

#include <string>

/// @brief	Define to 1 to show the vector of tokens after the lexer process
#define ANALYSE_DEBUG 0

/// @brief  This class manages the complete calculation process.
/// @note   Calling getResult() before lexer() and parserExec() functions
///         will automatically execute lexer() and parserExec() before
///         returning the result.
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
        Analyze(const std::string &str);
        
        /// @brief  Analyses and separates in tokens the string to compute
        void lexer(void);
        
        /// @brief  Analyses the list of tokens and calculates the result
        void parserExec(void);

        /// @brief  Get the result
        double getResult();

#if(ANALYSE_DEBUG == 1)
	private:
        /// @brief  Display the list of tokens
		/// @note	Debug utility
        void displayToken(void) const;
#endif
};

#endif	/* ANALYZE_H */

