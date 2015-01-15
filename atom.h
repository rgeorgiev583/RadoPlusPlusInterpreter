/*
 * atom.h
 *
 *  Created on: Jan 14, 2015
 *      Author: radoslav
 */

#ifndef ATOM_H_
#define ATOM_H_

#include "atomtype.h"
#include "token.h"
#include <string>


class AtomicExpression: public Token
{
protected:
	ATOM_TYPE type;

public:
    AtomicExpression(ATOM_TYPE _type = ATOM_INVALID): Token(TOKEN_VALUE), type(_type) {}

    ATOM_TYPE getType() const { return type; }
};


#endif /* ATOM_H_ */
