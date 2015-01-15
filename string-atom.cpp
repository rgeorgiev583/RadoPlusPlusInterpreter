/*
 * string-atom.cpp
 *
 *  Created on: Jan 15, 2015
 *      Author: radoslav
 */

#include "string-atom.h"
#include <cstring>


String::String(const char*& code): AtomicExpression(ATOM_STRING)
{
	code++;
	size_t len = strcspn(code, "\"");
	str = std::string(code, len);
	code += len;
}

