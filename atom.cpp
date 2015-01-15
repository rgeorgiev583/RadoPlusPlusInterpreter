/*
 * atom.cpp
 *
 *  Created on: Jan 14, 2015
 *      Author: radoslav
 */

#include "atom.h"
//#include "lambda.h"
#include "string.h"
#include <string>
#include <cstring>
#include <cstdlib>


AtomicExpression::AtomicExpression(const char*& code, ATOM_TYPE _type): type(_type)
{
	switch (_type)
	{
	case ATOM_INTEGER:
		integer = atoi(code);
		code++;
		code += strspn(code, "0123456789");
		code--;
		break;

	case ATOM_STRING:
		{
			code++;
			size_t len = strcspn(code, "\"");
			str = std::string(code, len);
			code += len;
		}
		break;

	case ATOM_LAMBDA:
		lambda = Lambda(code);
		break;

	default:;
	}
}

