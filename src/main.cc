
//  ==========================================================================
/// @file   main.cc
/// @author Yann Kurzo
/// @date   May 11, 2015, 9:32 PM
/// @license GPL2
//  ==========================================================================

#include "application.h"
#include "analyze.h"

#include <iostream>
#include <string>
#include <exception>

using namespace std;

int main(int argc,char *argv[])
{
    Application app(argc, argv);
    
    app.start();
    
//    string str("0");
//    
//    // If no argument, use cin
//    if(argc < 2)
//    {
//        str = "pi()";
//    }
//    // Else use line argumentvoid
//    else
//    {
//        str = argv[1];
//    }
//    
//    startAnalyze(str);
	
	cin.get();
    
    return 0;
}
