/*
 * operator.h
 *
 *  Created on: Jan 15, 2015
 *      Author: radoslav
 */

#ifndef OPERATOR_H_
#define OPERATOR_H_

#include "token.h"


class Operator: public Token
{
	char op;

public:
	Operator(): Token(TOKEN_INVALID) {}
	Operator(char _op): Token(TOKEN_OPERATOR), op(_op) {}

	Operator* clone() const { return new Operator(*this); }

	char getOperator() const { return op; }
};


#endif /* OPERATOR_H_ */
