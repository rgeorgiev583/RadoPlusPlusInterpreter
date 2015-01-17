/*
 * call.cpp
 *
 *  Created on: Jan 17, 2015
 *      Author: radoslav
 */

#include "call.h"
#include "constructor-call.h"
#include "function-call.h"
#include "strtok.h"


void Call::parse(const char*& code)
{
	name = Identifier(code);

	if (!gotoToken(code, " \t\n\r") || *code != '(')
	{
		type = CALL_INVALID;
		return;
	}

	code++;

	while (gotoToken(code, ", \t\n\r") && *code != ')')
		arguments.push_back(ExpressionTree::createExpressionTree(code));

	if (*code != ')')
		type = CALL_INVALID;
	else
		code++;
}

Call* Call::create(const char*& code)
{
	return peekToken(code, " \t\n\r") != "new" ? (Call*) new ConstructorCall(code) : (Call*) new FunctionCall(code);
}

Call::Call(const char*& code): Value(VALUE_CALL)
{
	parse(code);
}

