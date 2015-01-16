/*
 * simple.cpp
 *
 *  Created on: Jan 15, 2015
 *      Author: radoslav
 */

#include "simple.h"
#include "strtok.h"
#include "identifier.h"
#include "environment.h"
#include "integer.h"
#include "string.h"
#include <iostream>
#include <string>
#include <cstring>


SimpleStatement::SimpleStatement(const char*& code): Statement(STATEMENT_SIMPLE)
{
	std::string lhs_expr = getToken(code, "= \t\n\r");

	if (lhs_expr == "input")
	{
		type = STATEMENT_INPUT;
		lhs = Identifier(code);
	}
	else
	{
		if (lhs_expr == "return")
			type = STATEMENT_RETURN;
		else if (lhs_expr == "print")
			type = STATEMENT_OUTPUT;
		else
		{
			type = STATEMENT_ASSIGNMENT;
			lhs = lhs_expr;
			code = strchr(code, '=');
			code++;
		}

		rhs = ExpressionTree::createExpressionTree(code);
	}
}

Value* SimpleStatement::execute(Environment& environment) const
{
	switch (type)
	{
	case STATEMENT_ASSIGNMENT:
		{
			Environment::iterator it = environment.find(lhs);

			if (it != environment.end())
			{
				delete (*it).second;
				(*it).second = rhs.evaluate(environment);
			}
			else
				environment[lhs] = rhs.evaluate(environment);
		}

		break;

	case STATEMENT_RETURN:
		return rhs.evaluate(environment);

	case STATEMENT_OUTPUT:
		{
			Value* value = rhs.evaluate(environment);

			switch (value->getValueType())
			{
			case VALUE_INTEGER:
				std::cout << ((Integer*) value)->getInteger();
				break;

			case VALUE_STRING:
				std::cout << ((String*) value)->getString();
			}

			delete value;
			break;
		}

	case STATEMENT_INPUT:;
	}

	return NULL;
}

