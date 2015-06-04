
/*==================================================
 *
 * File:    main.cc
 * 
 * Author:  Yann Kurzo
 *
 * Date:    May 11, 2015, 9:23 PM
 *
 * license: GPL2
 *
 ==================================================*/

#include <iostream>
#include <string>

#include "analyse.h"

using namespace std;

int main(void)
{
    string str("pow(2,pi()*pi())+pi()");
    
    cout << "Calculator" << endl;
    
    Analyse an(str);
    
    cout << endl << "Lexer: " << endl;
    an.lexer();
    an.displayToken();
    
    cout << endl << "Parser and exec: " << endl;
    an.parserAndExec();
    
    cout << endl << "Result:" << endl;
    cout << "        " << str << " = " << an.getResult() << endl << endl;
    
    return 0;
}