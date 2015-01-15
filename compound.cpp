/*
 * compound.cpp
 *
 *  Created on: Jan 15, 2015
 *      Author: radoslav
 */

#include "compound.h"
#include "strtok.h"
#include <cstring>
#include <string>


void CompoundStatement::copy(const CompoundStatement& other)
{
	for (std::vector<Statement*>::const_iterator i = other.body.begin(); i != other.body.end(); i++)
		body.push_back((*i)->clone());
}

void CompoundStatement::destroy()
{
	while (!body.empty())
	{
		delete body.back();
		body.pop_back();
	}
}

CompoundStatement::CompoundStatement(const char*& code): Statement(STATEMENT_COMPOUND)
{
	code = strchr(code, '{');
	code++;
	std::string token;

	while (token = getToken(code, ";"), !token.empty() && token.find('}') == std::string::npos)
		body.push_back(Statement::createStatement(code));
}

CompoundStatement::CompoundStatement(const CompoundStatement& other)
{
	copy(other);
}

CompoundStatement& CompoundStatement::operator=(const CompoundStatement& other)
{
	if (&other != this)
	{
		destroy();
		copy(other);
	}

	return *this;
}

CompoundStatement::~CompoundStatement()
{
	destroy();
}

