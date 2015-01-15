/*
 * int-atom.cpp
 *
 *  Created on: Jan 15, 2015
 *      Author: radoslav
 */

#include "int-atom.h"
#include <cstdlib>
#include <cstring>


Integer::Integer(const char *& code): AtomicExpression(ATOM_INTEGER)
{
	integer = atoi(code);
	code++;
	code += strspn(code, "0123456789");
	code--;
}

