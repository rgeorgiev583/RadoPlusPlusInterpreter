/*
 * token.h
 *
 *  Created on: Jan 15, 2015
 *      Author: radoslav
 */

#ifndef TOKEN_H_
#define TOKEN_H_


enum TOKEN_TYPE
{
    TOKEN_INVALID,
    TOKEN_OPERATOR,
    TOKEN_VALUE
};

class Token
{
	TOKEN_TYPE type;

public:
	Token(TOKEN_TYPE _type = TOKEN_INVALID): type(_type) {}

	TOKEN_TYPE getType() const { return type; }
};


#endif /* TOKEN_H_ */
