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


Call::Call(const char*& code)
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

Value* Call::execute(Environment& environment) const
{
	EnvironmentIterator eit = environment.find(name);
	Lambda* lambda = NULL;

	if (eit != environment.end())
	{
		Value* value = (*eit).second;

		if (value->getTokenType() == TOKEN_VALUE && ((Value*) value)->getValueType() == VALUE_LAMBDA)
			lambda = (Lambda*) value;
	}

	Environment child_environment(environment);
	std::vector<Identifier>::const_iterator pit;
	std::vector<ExpressionTree>::const_iterator ait;

	for (pit = lambda->getSignatureIterator(), ait = arguments.begin();
		 pit != lambda->getSignatureEndIterator() && ait != arguments.end();
		 pit++, ait++)

		child_environment[(*pit).getName()] = (*ait).evaluate(environment);

	Value* retval = lambda->getBody()->execute(child_environment);

	for (Environment::iterator it = environment.begin(); it != environment.end(); it++)
	{
		Value* value = child_environment[(*it).first];

		if ((*it).second != value)
			(*it).second = value;
	}

	return retval;
}

