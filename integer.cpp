/*
 * integer.cpp
 *
 *  Created on: Jan 15, 2015
 *      Author: radoslav
 */

#include "integer.h"
#include "strtok.h"
#include <cstdlib>
#include <cstring>


Integer::Integer(const char *& code): Value(VALUE_INTEGER)
{
	gotoToken(code, " \t\n\r");
	integer = atoi(code);
	code++;
	code += strspn(code, "0123456789");
}

