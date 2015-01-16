/*
 * call.cpp
 *
 *  Created on: Jan 15, 2015
 *      Author: radoslav
 */

#include "call.h"
#include "strtok.h"
#include "exprtree.h"
#include "identifier.h"
#include "value.h"
#include "environment.h"
#include <map>


void Call::create(const char*& code)
{
	name = Identifier(code);

	if (getToken(code, ", \t\n\r")[0] != '(')
	{
		type = VALUE_INVALID;
		return;
	}

	std::string token;
	code++;

	do
		arguments.push_back(ExpressionTree::createExpressionTree(code));
	while (token = getToken(code, " \t\n\r"), !token.empty() && token[0] == ',');

	if (token.empty() || token[0] != ')')
	{
		type = VALUE_INVALID;
	}
}

void Call::assignLambda(Environment& environment)
{

}

Call::Call(const Identifier& _name, const std::vector<ExpressionTree>& _arguments, Environment& environment): Call(_name, _arguments)
{
	assignLambda(environment);
}

Call::Call(const char*& code)
{
	create(code);
}

Call::Call(const char*& code, Environment& environment)
{
	create(code);
	assignLambda(environment);
}

