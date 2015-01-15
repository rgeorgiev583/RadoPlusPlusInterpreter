/*
 * compound.cpp
 *
 *  Created on: Jan 14, 2015
 *      Author: radoslav
 */

#include "compound.h"
#include "string.h"
#include "statement.h"
#include <cstring>
#include <string>


CompoundStatement::CompoundStatement(const char* code)
{
	code = strchr(code, '{');
	code++;
	std::string token;

	while (token = getToken(code, "; \t\n\r"), !token.empty() && token.find('}') == std::string::npos)
	{
		body.push_back(Statement(code));
	}
}

