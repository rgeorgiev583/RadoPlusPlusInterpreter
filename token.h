/*
 * token.h
 *
 *  Created on: Jan 15, 2015
 *      Author: radoslav
 */

#ifndef TOKEN_H_
#define TOKEN_H_

#include "cloneable.h"


enum TOKEN_TYPE
{
    TOKEN_INVALID,
    TOKEN_OPERATOR,
    TOKEN_VALUE
};

class Token: public Cloneable
{
	TOKEN_TYPE type;

public:
	Token(TOKEN_TYPE _type = TOKEN_INVALID): type(_type) {}

	virtual Token* clone() const = 0;

	TOKEN_TYPE getTokenType() const { return type; }
};


#endif /* TOKEN_H_ */
