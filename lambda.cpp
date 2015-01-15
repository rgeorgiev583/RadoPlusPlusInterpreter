/*
 * lambda.cpp
 *
 *  Created on: Jan 14, 2015
 *      Author: radoslav
 */

#include "lambda.h"
#include "string.h"


Lambda::Lambda(const char*& code): AtomicExpression(ATOM_LAMBDA)
{
	if (getToken(code, "( \t\n\r") != "\\")
	{
		type = ATOM_INVALID;
		return;
	}

	if (getToken(code, ", \t\n\r")[0] != '(')
	{
		type = ATOM_INVALID;
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

	body = Statement(code);
}

