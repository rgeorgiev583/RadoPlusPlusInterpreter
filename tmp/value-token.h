/*
 * token.h
 *
 *  Created on: Jan 13, 2015
 *      Author: radoslav
 */

#ifndef VALUE_TOKEN_H_
#define VALUE_TOKEN_H_

#include "token.h"
#include "atom.h"


class AtomicExpressionToken: public Token, public AtomicExpression
{
public:
    AtomicExpressionToken(): Token(TOKEN_INVALID), AtomicExpression(ATOM_INVALID) {}
    AtomicExpressionToken(int _integer): AtomicExpression(_integer), type(TOKEN_VALUE) {}
    AtomicExpressionToken(const std::string& _str): AtomicExpression(_str), type(TOKEN_VALUE) {}
    AtomicExpressionToken(const Lambda& _lambda): AtomicExpression(_lambda), type(TOKEN_VALUE) {}
    AtomicExpressionToken(char _op): type(TOKEN_OPERATOR), op(_op) {}
    AtomicExpressionToken(const char* expr, ATOM_TYPE value_type): AtomicExpression(expr, value_type) {}

    TOKEN_TYPE getTokenType() const { return type; }
    char getOperator() const { return op; }
};


#endif /* VALUE_TOKEN_H_ */
