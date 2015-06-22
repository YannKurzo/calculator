
//  ==========================================================================
/// @file   application.h
/// @author Yann Kurzo
/// @date   June 14, 2015, 9:32 PM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  This file defines the Application class.
//  ==========================================================================

#ifndef APPLICATION_H
#define	APPLICATION_H

#include "mpfrInterface.h"
#include "analyze.h"
#include "command.h"

#include <string>

/// @brief  This class manages the whole application with the main arguments when
///         they are specified
/// @note   The command mode is started when no arguments are given to the program.
///         The argument mode is started otherwise.
class Application
{ 
    protected:
        /// String to compute
        std::string str_m;
        
        /// Number of main arguments
        int argc_m;
        
        /// Pointer on a table of main arguments
        char **argv_m;
        
        /// Used to verify if main arguments are specified
        bool argumentPresent_m;
        
        /// Application name
        const std::string applicationName_m = "calculator";
        
        /// Application version
        const std::string applicationVersion_m = "v1.0";

    public:
        /// @brief  Constructor
        /// @param  argc Number of main arguments
        /// @param  *argv[] Pointer on a table of main arguments
        Application(int argc,char *argv[]);
        
        /// @brief  Start the program in the right mode depending on the main arguments
        void start(void);
        
    private:
        /// @brief  Start the program in argument mode
        void startArgument(void);

        /// @brief  Start the program in command mode
        void startCommand(void);
        
        /// @brief  Check the command depending on the mode and execute it
        /// @return Executed command, eNB_ARGUMENTS otherwise
        command_e checkCommand(void);
        
        /// @brief  Start the analysis with str_m as input string
        void startAnalyse(void);

        /// @brief  Show the title of the application
        void showTitle(void);

        /// @brief  Show a goodbye text
        void showExit(void);
};

#endif	/* APPLICATION_H */

