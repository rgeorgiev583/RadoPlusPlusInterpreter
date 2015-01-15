/*
 * string.h
 *
 *  Created on: Jan 15, 2015
 *      Author: radoslav
 */

#ifndef STRING_H_
#define STRING_H_

#include "value.h"


class String: public Value
{
	std::string str;

public:
	String(const std::string& _str): Value(VALUE_STRING), str(_str) {}
	String(const char*&);

	String* clone() const { return new String(*this); }

	const std::string& getString() const { return str; }
};


#endif /* STRING_H_ */
