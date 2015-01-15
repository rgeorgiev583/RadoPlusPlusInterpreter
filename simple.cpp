/*
 * simple.cpp
 *
 *  Created on: Jan 15, 2015
 *      Author: radoslav
 */

#include "simple.h"
#include "strtok.h"
#include <string>
#include <cstring>


SimpleStatement::SimpleStatement(const char*& code): Statement(STATEMENT_SIMPLE)
{
	std::string lhs_expr = getToken(code, "= \t\n\r");

	if (lhs_expr == "return")
		type = STATEMENT_RETURN;
	else if (lhs_expr == "print")
		type = STATEMENT_OUTPUT;
	else if (lhs_expr == "input")
		type = STATEMENT_INPUT;
	else
	{
		type = STATEMENT_ASSIGNMENT;
		code = strchr(code, '=');
		code++;
	}

	rhs = ExpressionTree::createExpressionTree(code);
}

