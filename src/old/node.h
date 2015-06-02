
/*==================================================
 *
 * File:    node.h
 * 
 * Author:  Yann Kurzo
 *
 * Date:    May 17, 2015, 2:23 AM
 *
 * license: GPL2
 * 
 * Description:
 *          
 *
 ==================================================*/


#ifndef NODE_H
#define	NODE_H

#include <iostream>
#include <cmath>

#include "token.h"

#define DISPLAY_OPERATIONS

class Node
{
    protected:
        Node *root_m;
        Node *left_m;
        Node *right_m;
        
    private:
        double execOperator(char op, double left, double right);
        
    public:
        Node(void);
        Node(Token *root, Token *left, Token *right);
        
        void exec(void);
        
        Node *get(void);
        Node *getLeft(void);
        void setLeft(Node *left);
        Node *getRight(void);
        void setRight(Node *right);
};


#endif	/* NODE_H */

