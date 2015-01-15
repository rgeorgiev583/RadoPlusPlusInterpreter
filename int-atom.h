/*
 * int-atom.h
 *
 *  Created on: Jan 15, 2015
 *      Author: radoslav
 */

#ifndef INT_ATOM_H_
#define INT_ATOM_H_

#include "atom.h"


class Integer: public AtomicExpression
{
	int integer;

public:
	Integer(int _integer): AtomicExpression(ATOM_INTEGER), integer(_integer) {}
	Integer(const char*&);

	int getInteger() const { return integer; }
};


#endif /* INT_ATOM_H_ */
