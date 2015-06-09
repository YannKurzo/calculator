
/*==================================================
 *
 * File:    binTree.cc
 * 
 * Author:  Yann Kurzo
 *
 * Date:    May 17, 2015, 2:06 AM
 *
 * license: GPL2
 *
 ==================================================*/

#include "binTree.h"

#include <iostream>
#include <string>
#include <cmath>

using namespace std;


BinTree::BinTree(void)
{
    
}

BinTree::BinTree(TokenVector &tokenList) :
    BinTree()
{
    tokenVector_m = tokenList;
    init();
}

BinTree::~BinTree(void)
{
    
}
        
void BinTree::init(void)
{
    ListIt it = tokenVector_m.begin();
    ListIt min = tokenVector_m.begin();
    ListIt max = tokenVector_m.end(); max--;
    
    // First node
    algo(0, tokenVector_m.size()-1);
}

unsigned int BinTree::algo(unsigned int min, unsigned int max)
{
    while(max - min >= 1)
    {
        unsigned int op = findHighestOp(min, max);
        
        if(tokenVector_m[op].getType() == Token::eTOKENTYPE_BRACKET_CLOSE)
        {
            unsigned int close = op;
            unsigned int open = op-1;
            
            // Get opening bracket
            while(tokenVector_m[open].getType() != Token::eTOKENTYPE_BRACKET_OPEN)
                --open;
            
            // Update max
            max = max - close + open;
            
            // Calculate
            close = algo(open+1, close-1) + 1;
            
            // Erase brackets
            tokenVector_m.erase(tokenVector_m.begin()+open+2);
            tokenVector_m.erase(tokenVector_m.begin()+open);
        }
        else if(tokenVector_m[op].getType() == Token::eTOKENTYPE_FUNCTION)
        {
            unsigned int parameters = exec(op);
            
            for(unsigned int i=op+parameters; i>op; --i)
                tokenVector_m.erase(tokenVector_m.begin()+i);
            
            max -= parameters;
        }
        else
        {
            unsigned int left = op-1;
            unsigned int right = op+1;

            // Calculate
            exec(tokenVector_m[op], tokenVector_m[left], tokenVector_m[right]);

            // Erase old token
            tokenVector_m.erase(tokenVector_m.begin()+right);
            tokenVector_m.erase(tokenVector_m.begin()+left);

            // Reinit max
            max -= 2;
        }
    }
    return max;
}

unsigned int BinTree::findHighestOp(unsigned int min, unsigned int max)
{
    unsigned int ret = min;
    int priority = tokenVector_m[min].getPriority();
    
    for(unsigned int i = min+1; i<=max; ++i)
    {
        if(tokenVector_m[i].getPriority() < priority)
        {
            priority = tokenVector_m[i].getPriority();
            ret = i;
        }
    }
    return ret;
}

unsigned int BinTree::exec(unsigned int func)
{
    // Get function name
    string str = tokenVector_m[func].getStr();
    
    // Number of parameters
    unsigned int nbPar = Function::getNbParameters(str);
    double par[MAX_NUMBER_PARAMETERS];
    
    // Set parameters
    for(unsigned int i=0; i<nbPar; ++i)
        par[i] = tokenVector_m[func+i+1].getN();
    
    // Result with MAX_NUMBER_PARAMETERS = 5
    double res = call(str, par[0], par[1], par[2], par[3], par[4]);
    
    // Update vector
    tokenVector_m[func].setN(res);
    
#ifdef DISPLAY_OPERATIONS
        cout << str << "(";
        if(nbPar > 0)
        {
            for(unsigned int i=0; i<nbPar-1; ++i)
                cout << tokenVector_m[func+i+1] << ", ";
            cout << tokenVector_m[func+nbPar];
        }
        cout << ") = " << tokenVector_m[func].getN() << endl;
#endif
    if(nbPar == 0)
        ++nbPar;
    
    return nbPar;
}

void BinTree::exec(Token &root, Token &left, Token &right)
{ 
    if(root.getType() == Token::eTOKENTYPE_OPERATOR)
    {
        double l = left.getN(), r = right.getN();
        
        root.setN(execOperator(root.getStr().at(0), l, r));
        
#ifdef DISPLAY_OPERATIONS
        cout << l << " " << root.getStr() << " " << r << " = " << root.getN() << endl;
#endif
    }
}

double BinTree::execOperator(char op, double left, double right)
{
    switch(op)
    {
        case '+':
            return left + right;
        case '-':
            return left - right;
        case '*':
            return left * right;
        case '/':
            return left / right;
        case '^':
            return pow(left, right);
        default:
            return 0;
    }
}


double BinTree::getResult(void) const
{
    return tokenVector_m.begin()->getN();
}
