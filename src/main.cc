
//  ==========================================================================
/// @file   main.cc
/// @author Yann Kurzo
/// @date   May 11, 2015, 9:32 PM
/// @copyright Copyright 2015 Yann Kurzo. All rights reserved.
///         This project is released under the GNU Public License.
/// @brief  Start a new application
//  ==========================================================================

#include "application.h"
#include "analyze.h"

#include <iostream>
#include <string>
#include <exception>

#include "mpfrInterface.h"

using namespace std;

int main(int argc,char *argv[])
{
    // Create new application and start
    Application app(argc, argv);
    
    app.start();
    
    return 0;
}
