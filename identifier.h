/*
 * identifier.h
 *
 *  Created on: Jan 15, 2015
 *      Author: radoslav
 */

#ifndef IDENTIFIER_H_
#define IDENTIFIER_H_

#include "value.h"
#include <string>


class Identifier: public Value
{
	std::string name;

public:
	Identifier(): Value(VALUE_IDENTIFIER) {}
	Identifier(const std::string& _name): Value(VALUE_IDENTIFIER), name(_name) {}
	Identifier(const char*& code);

	Identifier* clone() const { return new Identifier(*this); }

	const std::string& getName() const { return name; }
};


#endif /* IDENTIFIER_H_ */
