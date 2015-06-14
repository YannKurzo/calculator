
//  ==========================================================================
/// @file   application.h
/// @author Yann Kurzo
/// @date   May 11, 2015, 9:32 PM
/// @license GPL2
/// @brief  
//  ==========================================================================

#ifndef APPLICATION_H
#define	APPLICATION_H

#include "analyze.h"

#include <string>

/// @brief  
class Application
{ 
    protected:
        // String to compute
        std::string str_m;
        
        //
        int argc_m;
        
        //
        char **argv_m;
        
        //
        bool argumentPresent_m;

    public:
        /// @brief  
        Application(int argc,char *argv[]);
        
        /// @brief  
        void start(void);
        
    private:
        
        /// @brief  
        void startArgument(void);

        /// @brief  
        void startCommand(void);
        
        /// @brief  
        void startAnalyse(void);

        /// @brief  
        void showTitle(void);
};

#endif	/* APPLICATION_H */

