/*
 * identifier.cpp
 *
 *  Created on: Jan 15, 2015
 *      Author: radoslav
 */


#include "identifier.h"
#include <cstring>
#include <string>


Identifier::Identifier(const char*& code): Value(VALUE_IDENTIFIER)
{
	size_t len = strspn(code, "_0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	name = std::string(code, len);
	code += len;
}

