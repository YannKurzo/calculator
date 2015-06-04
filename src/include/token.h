
/*==================================================
 *
 * File:    token.h
 * 
 * Author:  Yann Kurzo
 *
 * Date:    May 17, 2015, 12:23 AM
 *
 * license: GPL2
 * 
 * Description:
 *          
 *
 ==================================================*/


#ifndef TOKEN_H
#define	TOKEN_H

#include <string>

        
typedef enum
{
    P_BRACKET_CLOSE, P_BRACKET_OPEN, P_FUNCTION, P_OP_POWER, P_OP_MUL, P_OP_PLUS, P_LOWER
}priority_t;

static std::string bracketsOpen = "([{";
static std::string bracketsClose = ")]}";
static std::string operators = "^*/+-";
static priority_t opPriority[] = {P_OP_POWER, P_OP_MUL, P_OP_MUL, P_OP_PLUS, P_OP_PLUS};

class Token
{
    public:
        typedef enum
        {
            NUMBER, OPERATOR, BRACKET_OPEN, BRACKET_CLOSE, COMMA, FUNCTION
        }tokenType_t;
        
    protected:
        tokenType_t type_m;
        double n_m;
        std::string str_m;
        
    public:
        Token(void);
        Token(const Token &token);
        Token(tokenType_t type, std::string str);
        
        int getOpPriority(void) const;
        int getType(void) const;
        void setType(tokenType_t type);
        double getN(void) const;
        void setN(double n);
        std::string getStr(void) const;
        
        void display(std::ostream& flow) const;
};

std::ostream& operator<<(std::ostream& flow, Token const& token);


#endif	/* TOKEN_H */

