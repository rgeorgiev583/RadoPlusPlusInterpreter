/*
 * atom.h
 *
 *  Created on: Jan 14, 2015
 *      Author: radoslav
 */

#ifndef ATOM_H_
#define ATOM_H_

#include "lambda.h"
#include "atomtype.h"
#include <string>


class AtomicExpression
{
	ATOM_TYPE type;
	int integer;
	std::string str;
	Lambda lambda;

public:
    AtomicExpression(): type(ATOM_INVALID) {}
    AtomicExpression(int _integer): type(ATOM_INTEGER), integer(_integer) {}
    AtomicExpression(const std::string& _str): type(ATOM_STRING), str(_str) {}
    AtomicExpression(const Lambda& _lambda): type(ATOM_LAMBDA), lambda(_lambda) {}
    AtomicExpression(const char*&, ATOM_TYPE);

    ATOM_TYPE getType() const { return type; }
    int getInteger() const { return integer; }
    const std::string& getString() const { return str; }
    const Lambda& getLambda() const { return lambda; }
};


#endif /* ATOM_H_ */
