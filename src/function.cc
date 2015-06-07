
//  ==================================================
/// @file   function.h
/// @author Yann Kurzo
/// @date   May 26, 2015, 9:30 PM
/// @license GPL2
/// @brief  Handle existing functions of libraries
/// @note   New functions can be easily added with the ADD macro.
//  ==================================================

#include "function.h"

#include <iostream>
#include <cstdlib>

using namespace std;

unsigned int Function::getNbParameters(std::string str)
{
    func_ptr ret = functions_m[str].func;
    
    if(ret == NULL)
    {
        cout << "Function \"" << str << "\" is not implemented!" << endl;
        exit(EXIT_FAILURE);
    }
    
    return functions_m[str].nbParameters;
}

func_ptr Function::getFunction(std::string str)
{
    func_ptr ret = functions_m[str].func;
    
    if(ret == NULL)
    {
        cout << "Function \"" << str << "\" is not implemented!" << endl;
        exit(EXIT_FAILURE);
    }
    
    return ret;
}
