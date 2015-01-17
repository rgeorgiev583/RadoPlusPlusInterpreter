/*
 * environment.cpp
 *
 *  Created on: Jan 16, 2015
 *      Author: radoslav
 */

#include "environment.h"

void Environment::clone()
{
	for (EnvironmentIterator it = begin(); it != end(); it++)
		if ((*it).second)
			(*it).second = (*it).second->clone();
}

void Environment::destroy()
{
	for (EnvironmentIterator it = begin(); it != end(); it++)
		delete (*it).second;
}

Environment::Environment(): std::map<Identifier, Value*>() {}

Environment::Environment(const Environment& other): std::map<Identifier, Value*>(other)
{
	clone();
}

Environment& Environment::operator=(const Environment& other)
{
	if (&other != this)
	{
		destroy();
		std::map<Identifier, Value*>::operator=(other);
		clone();
	}

	return *this;
}

Environment::~Environment()
{
	destroy();
}

