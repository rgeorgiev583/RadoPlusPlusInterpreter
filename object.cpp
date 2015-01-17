/*
 * object.cpp
 *
 *  Created on: Jan 16, 2015
 *      Author: radoslav
 */

#include "object.h"
#include "strtok.h"


Object::Object(const char*& code): Value(VALUE_OBJECT)
{
	if (!gotoToken(code, " \t\n\r") || *code != '{')
	{
		type = VALUE_INVALID;
		return;
	}

	code++;

	while (gotoToken(code, ", \t\n\r") && *code != '}')
	{
		Identifier key = Identifier(code);

		if (!gotoToken(code, " \t\n\r") || *code != ':')
		{
			type = VALUE_INVALID;
			return;
		}

		code++;

		operator[](key) = ExpressionTree::createExpressionTree(code);
	}

	if (*code != '}')
		type = VALUE_INVALID;
	else
		code++;
}

