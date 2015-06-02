
/*==================================================
 *
 * File:    node.cc
 * 
 * Author:  Yann Kurzo
 *
 * Date:    May 17, 2015, 2:23 AM
 *
 * license: GPL2
 *
 ==================================================*/

#include "node.h"

using namespace std;

Node::Node(void)
{
    
}

Node(Token *root, Token *left, Token *right)
{   
    root_m = root;
    left_m = left;
    right_m = right;
}

void Node::exec(void)
{
//    if(leaf->left_m != NULL && leaf->left_m->type_m != NUMBER)
//        exec(leaf->left_m);
//
//    if(leaf->right_m != NULL && leaf->right_m->type_m != NUMBER)
//        exec(leaf->right_m);
//        
    if(root_m->type_m == OPERATOR)
    {
        double left = left_m->n_m, right = right_m->n_m;
        
#ifdef DISPLAY_OPERATIONS
        cout << left << root_m->str_m << right << endl;
#endif
        
        root_m->n_m = execOperator(root_m->str_m.at(0), left, right);
        root_m->type_m = P_NUMBER;
    }
}

double Node::execOperator(char op, double left, double right)
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

Node *Node::get(void)
{
    return root_m;
}

Node *Node::getLeft(void)
{
    return left_m;
}

void Node::setLeft(Node *left)
{
    left_m = left;
}

Node *Node::getRight(void)
{
    return right_m;
}

void Node::setRight(Node *right)
{
    right_m = right;
}