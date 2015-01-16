/*
 * string.cpp
 *
 *  Created on: Jan 15, 2015
 *      Author: radoslav
 */

#include "string.h"
#include "strtok.h"
#include <cstring>


String::String(const char*& code): Value(VALUE_STRING)
{
	gotoToken(code, " \t\n\r");

	if (*code == '"')
		code++;

	size_t len = strcspn(code, "\"");
	str = std::string(code, len);
	code += len;
}

