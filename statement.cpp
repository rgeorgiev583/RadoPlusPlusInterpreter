/*
 * statement.cpp
 *
 *  Created on: Jan 14, 2015
 *      Author: radoslav
 */

#include "statement.h"
#include "string.h"
#include <string>
#include <cstring>


Statement::Statement(const char*& code)
{
	std::string lhs_expr = getToken(code, "= \t\n\r");

	if (lhs_expr == "return")
		type = STATEMENT_RETURN;
	else if (lhs_expr == "print")
		type = STATEMENT_OUTPUT;
	else if (lhs_expr == "input")
		type = STATEMENT_INPUT;
	else if (lhs_expr[0] == '{')
	{
		type = STATEMENT_COMPOUND;
		code++;
		std::string token;

		while (token = getToken(code, ";"), !token.empty() && token.find('}') == std::string::npos)
			body.push_back(Statement(code));
	}
	else
	{
		type = STATEMENT_ASSIGNMENT;
		code = strchr(code, '=');
		code++;
	}

	rhs = createExpressionTree(code);
}

