/*
 * atom.h
 *
 *  Created on: Jan 14, 2015
 *      Author: radoslav
 */

#ifndef ATOM_H_
#define ATOM_H_

#include "token.h"
#include <string>


enum ATOM_TYPE
{
	ATOM_INVALID,
	ATOM_INTEGER,
	ATOM_STRING,
	ATOM_LAMBDA
};

class AtomicExpression: public Token
{
protected:
	ATOM_TYPE type;

public:
    AtomicExpression(ATOM_TYPE _type = ATOM_INVALID): Token(TOKEN_VALUE), type(_type) {}

    ATOM_TYPE getType() const { return type; }
};


#endif /* ATOM_H_ */
