
/*==================================================
 *
 * File:    test.cc
 * 
 * Author:  Yann Kurzo
 *
 * Date:    May 26, 2015, 9:30 PM
 *
 * license: GPL2
 *
 ==================================================*/

#include "function.h"

#include <iostream>
#include <cmath>

using namespace std;

unsigned int Function::getNbParameters(std::string str)
{
    void * ret = functions_m[str].func;
    
    if(ret == 0)
    {
        cout << "Function \"" << str << "\" is not implemented!" << endl;
        exit(EXIT_FAILURE);
    }
    
    return functions_m[str].nbParameters;
}

void *Function::getFunction(std::string str)
{
    void * ret = functions_m[str].func;
    
    if(ret == 0)
    {
        cout << "Function \"" << str << "\" is not implemented!" << endl;
        exit(EXIT_FAILURE);
    }
    
    return ret;
}