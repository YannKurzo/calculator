
/*==================================================
 *
 * File:    binTree.h
 * 
 * Author:  Yann Kurzo
 *
 * Date:    May 17, 2015, 2:06 AM
 *
 * license: GPL2
 * 
 * Description:
 *          
 *
 ==================================================*/


#ifndef BINTREE_H
#define	BINTREE_H

#include "token.h"
#include "function.h"

#include <vector>

#define DISPLAY_OPERATIONS

typedef std::vector<Token> TokenVector;
typedef TokenVector::iterator ListIt;

class BinTree
{
    private:
        TokenVector tokenVector_m;
        
    private:
        unsigned int algo(unsigned int min, unsigned int max);
        unsigned int findHighestOp(unsigned int min, unsigned int max);
        unsigned int exec(unsigned int func);
        
        double execOperator(char op, double left, double right);
        
    public:
        BinTree(void);
        BinTree(TokenVector &tokenList);
        ~BinTree(void);
        
        void init(void);
        
        void exec(Token &root, Token &left, Token &right);
        
        double getResult(void) const;
};


#endif	/* BINTREE_H */

