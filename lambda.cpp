/*
 * lambda.cpp
 *
 *  Created on: Jan 14, 2015
 *      Author: radoslav
 */

#include "lambda.h"
#include "strtok.h"
#include "identifier.h"


void Lambda::copy(const Lambda& other)
{
	signature = other.signature;
	body = other.body->clone();
}

void Lambda::destroy()
{
	delete body;
}

Lambda::Lambda(const char*& code): Value(VALUE_LAMBDA)
{
	if (getToken(code, "( \t\n\r") != "\\")
	{
		type = VALUE_INVALID;
		return;
	}

	if (getToken(code, ", \t\n\r")[0] != '(')
	{
		type = VALUE_INVALID;
		return;
	}

	std::string token;
	code++;

	while (token = getToken(code, ", \t\n\r"), !token.empty() && token.find(')') == std::string::npos)
		signature.push_back(token);

	if (!token.empty())
	{
		std::string last_param = getToken(token, "), \t\n\r");

		if (!last_param.empty())
			signature.push_back(last_param);
	}

	body = Statement::createStatement(code);
}

Lambda::Lambda(const Lambda& other)
{
	copy(other);
}

Lambda& Lambda::operator=(const Lambda& other)
{
	if (&other != this)
	{
		destroy();
		copy(other);
	}

	return *this;
}

Lambda::~Lambda()
{
	destroy();
}

