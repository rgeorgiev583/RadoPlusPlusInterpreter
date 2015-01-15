/*
 * integer.cpp
 *
 *  Created on: Jan 15, 2015
 *      Author: radoslav
 */

#include <cstdlib>
#include <cstring>
#include "integer.h"


Integer::Integer(const char *& code): Value(VALUE_INTEGER)
{
	integer = atoi(code);
	code++;
	code += strspn(code, "0123456789");
	code--;
}

