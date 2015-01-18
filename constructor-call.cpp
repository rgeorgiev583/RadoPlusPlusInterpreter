/*
 * constructor-call.cpp
 *
 *  Created on: Jan 17, 2015
 *      Author: radoslav
 */

#include "constructor-call.h"
#include "strtok.h"
#include "object.h"


ConstructorCall::ConstructorCall(const char*& code)
{
	if (peekToken(code, " \t\n\r") != "new")
	{
		type = CALL_INVALID;
		return;
	}

	parse(code);
}

Value* ConstructorCall::execute(Environment& environment) const
{
	Environment::iterator eit = environment.find(name);
	Object* object = NULL;

	if (eit != environment.end())
	{
		Value* value = (*eit).second;

		if (value->getTokenType() == TOKEN_VALUE && ((Value*) value)->getValueType() == VALUE_OBJECT)
			object = (Object*) value;
	}

	if (!object)
		return NULL;

	object = object->clone();
	Object::iterator oit;
	std::vector<ExpressionTree>::const_iterator ait;

	for (oit = object->begin(), ait = arguments.begin();
		 oit != object->end() && ait != arguments.end();
		 oit++, ait++)

		(*oit).second = (*ait).evaluate(environment);

	return object;
}

