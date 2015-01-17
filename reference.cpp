/*
 * reference.cpp
 *
 *  Created on: Jan 18, 2015
 *      Author: radoslav
 */

#include "reference.h"
#include "identifier.h"
#include "strtok.h"


Reference::Reference(const char*& code): Value(VALUE_REFERENCE)
{
	objectName = Identifier(code);

	if (!gotoToken(code, " \t\n\r"))
	{
		type = VALUE_INVALID;
		return;
	}

	if (*code == '.')
		memberName = Identifier(code);
	else
	{
		memberName = objectName;
		objectName = Identifier();
	}
}

