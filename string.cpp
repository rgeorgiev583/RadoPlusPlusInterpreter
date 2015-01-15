/*
 * string.cpp
 *
 *  Created on: Jan 15, 2015
 *      Author: radoslav
 */

#include <cstring>
#include "string.h"


String::String(const char*& code): Value(VALUE_STRING)
{
	code++;
	size_t len = strcspn(code, "\"");
	str = std::string(code, len);
	code += len;
}

