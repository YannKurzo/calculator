
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
#include <exception>

using namespace std;

unsigned int Function::getNbParameters(std::string str)
{
    return functions_m[str].nbParameters;
}

func_ptr Function::getFunction(std::string str)
{
    return functions_m[str].func;
}
