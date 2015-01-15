/*
 * token.h
 *
 *  Created on: Jan 13, 2015
 *      Author: radoslav
 */

#ifndef TOKEN_H_
#define TOKEN_H_

#include "atom.h"


enum TOKEN_TYPE
{
    TOKEN_INVALID,
    TOKEN_OPERATOR,
    TOKEN_VALUE
};

class AtomicExpressionToken: public AtomicExpression
{
    TOKEN_TYPE type;
    char op;

public:
    AtomicExpressionToken(): AtomicExpression(), type(TOKEN_INVALID) {}
    AtomicExpressionToken(int _integer): AtomicExpression(_integer), type(TOKEN_VALUE) {}
    AtomicExpressionToken(const std::string& _str): AtomicExpression(_str), type(TOKEN_VALUE) {}
    AtomicExpressionToken(const Lambda& _lambda): AtomicExpression(_lambda), type(TOKEN_VALUE) {}
    AtomicExpressionToken(char _op): type(TOKEN_OPERATOR), op(_op) {}
    AtomicExpressionToken(const char* expr, ATOM_TYPE value_type): AtomicExpression(expr, value_type) {}

    TOKEN_TYPE getType() const { return type; }
    ATOM_TYPE getValueType() const { return AtomicExpression::getType(); }
    char getOperator() const { return op; }
};


#endif /* TOKEN_H_ */
