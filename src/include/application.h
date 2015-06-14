
//  ==========================================================================
/// @file   application.h
/// @author Yann Kurzo
/// @date   June 14, 2015, 9:32 PM
/// @license GPL2
/// @brief  
//  ==========================================================================

#ifndef APPLICATION_H
#define	APPLICATION_H

#include "analyze.h"
#include "command.h"

#include <string>

/// @brief  
class Application
{ 
    protected:
        // String to compute
        std::string str_m;
        
        // Number of main arguments
        int argc_m;
        
        // Pointer on a table of main arguments
        char **argv_m;
        
        // Used to verify if there were main arguments
        bool argumentPresent_m;

    public:
        /// @brief  Constructor
        /// @param  argc Number of main arguments
        /// @param  *argv[] Pointer on a table of main arguments
        Application(int argc,char *argv[]);
        
        /// @brief  Start the program in the right mode
        void start(void);
        
    private:
        /// @brief  Start the program in argument mode
        void startArgument(void);

        /// @brief  Start the program in command mode
        void startCommand(void);
        
        /// @brief  Check the command depending on the mode and execute it
        /// @return Executed command, eNB_ARGUMENTS elsewhere
        Command::command_t checkCommand(void);
        
        /// @brief  Start the analysis with str_m as input string
        void startAnalyse(void);

        /// @brief  Show the title of the application
        void showTitle(void);

        /// @brief  Show a goodbye text
        void showExit(void);
};

#endif	/* APPLICATION_H */

