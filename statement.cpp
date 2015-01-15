/*
 * statement.cpp
 *
 *  Created on: Jan 14, 2015
 *      Author: radoslav
 */

#include "statement.h"
#include "compound.h"
#include "simple.h"
#include "strtok.h"
#include "exprtree.h"
#include <string>
#include <cstring>


Statement* Statement::createStatement(const char*& code)
{
	Statement* statement;

	if (getToken(code, " \t\n\r")[0] == '{')
	{
		statement = new CompoundStatement(code);
		statement->type = STATEMENT_COMPOUND;
	}
	else
	{
		statement = new SimpleStatement(code);
		statement->type = STATEMENT_SIMPLE;
	}

	return statement;
}

