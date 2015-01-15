/*
 * integer.h
 *
 *  Created on: Jan 15, 2015
 *      Author: radoslav
 */

#ifndef INTEGER_H_
#define INTEGER_H_

#include "value.h"


class Integer: public Value
{
	int integer;

public:
	Integer(int _integer): Value(VALUE_INTEGER), integer(_integer) {}
	Integer(const char*&);

	Integer* clone() const { return new Integer(*this); }

	int getInteger() const { return integer; }
};


#endif /* INTEGER_H_ */
