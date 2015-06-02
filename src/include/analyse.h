
/*==================================================
 *
 * File:    analyse.h
 * 
 * Author:  Yann Kurzo
 *
 * Date:    May 11, 2015, 9:32 PM
 *
 * license: GPL2
 * 
 * Description:
 *          
 *
 ==================================================*/


#ifndef STRUCT_H
#define	STRUCT_H

#include <iostream>
#include <string>
#include <cctype>
#include <list>
#include <algorithm>

#include "token.h"
#include "binTree.h"

class Analyse
{ 
    protected:
        // Input / Output
        std::string str_m;
        double result_m;
        
        // List of token
        TokenVector tokenVector_m;
        
        // Binary tree
        BinTree *binTree_m;
        
    private:
        void cleanString(void);
        void addBrackets(void);

    public:
        Analyse(std::string str);
        ~Analyse(void);
        
        void lexer(void);
        void displayToken(void);
        void parserAndExec(void);

        double getResult() const;

};

#endif	/* STRUCT_H */

