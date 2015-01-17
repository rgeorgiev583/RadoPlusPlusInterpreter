/*
 * function-call.cpp
 *
 *  Created on: Jan 17, 2015
 *      Author: radoslav
 */

#include "function-call.h"
#include "strtok.h"
#include "exprtree.h"
#include "identifier.h"
#include "value.h"
#include "lambda.h"
#include "environment.h"
#include <map>
#include <cstring>


FunctionCall::FunctionCall(const char*& code)
{
	parse(code);
}

Value* FunctionCall::execute(Environment& environment) const
{
	EnvironmentIterator eit = environment.find(name);
	Lambda* lambda = NULL;

	if (eit != environment.end())
	{
		Value* value = (*eit).second;

		if (value->getTokenType() == TOKEN_VALUE && ((Value*) value)->getValueType() == VALUE_LAMBDA)
			lambda = (Lambda*) value;
	}

	if (!lambda)
		return NULL;

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
			(*it).second = value->clone();
	}

	return retval;
}

