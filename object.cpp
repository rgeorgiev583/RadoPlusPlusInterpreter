/*
 * object.cpp
 *
 *  Created on: Jan 16, 2015
 *      Author: radoslav
 */

#include "object.h"


void Object::copy(const Object& other)
{
	for (ConstObjectIterator it = other.begin(); it != other.end(); it++)
		if ((*it).second)
			this->at((*it).first) = (*it).second->clone();
}

void Object::destroy()
{
	for (ObjectIterator it = begin(); it != end(); it++)
		delete (*it).second;
}

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

		Value* value = ExpressionTree::createExpressionTree(code).evaluate
		push_back(Statement::createStatement(code));
	}

	if (*code != '}')
		type = VALUE_INVALID;
	else
		code++;

	if (!gotoToken(code, " \t\n\r") || *code != '\\')
	{
		type = VALUE_INVALID;
		return;
	}

	code++;

	if (!gotoToken(code, " \t\n\r") || *code != '(')
	{
		type = VALUE_INVALID;
		return;
	}

	code++;

	while (gotoToken(code, ", \t\n\r") && *code != ')')
		signature.push_back(Identifier(code));

	if (*code != ')')
		type = VALUE_INVALID;
	else
	{
		code++;
		body = Statement::createStatement(code);
	}
}

Object::Object(const Object& other)
{
	copy(other);
}

Object& Object::operator=(const Object& other)
{
	if (&other != this)
	{
		destroy();
		copy(other);
	}

	return *this;
}

Object::~Object()
{
	destroy();
}



