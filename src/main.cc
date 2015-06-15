
//  ==========================================================================
/// @file   main.cc
/// @author Yann Kurzo
/// @date   May 11, 2015, 9:32 PM
/// @license GPL2
/// @brief  Start a new application
//  ==========================================================================

#include "application.h"
#include "analyze.h"

#include <iostream>
#include <string>
#include <exception>

using namespace std;

int main(int argc,char *argv[])
{
    // Create new application and start
    Application app(argc, argv);
    
    app.start();
    
    return 0;
}
