/*
 * identifier.cpp
 *
 *  Created on: Jan 15, 2015
 *      Author: radoslav
 */


#include "identifier.h"
#include "strtok.h"
#include <cstring>
#include <string>


Identifier::Identifier(const char*& code): Value(VALUE_IDENTIFIER)
{
	gotoToken(code, " \t\n\r");
	size_t len = strspn(code, "_0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	name = std::string(code, len);
	code += len;
}

/// this is a hack!!!
bool Identifier::operator<(const Identifier b) const
{
	return getName() < b.getName();
}
