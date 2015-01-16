/*
 * environment.cpp
 *
 *  Created on: Jan 16, 2015
 *      Author: radoslav
 */

#include "environment.h"

void Environment::copy(const Environment& other)
{
	for (ConstEnvironmentIterator it = other.begin(); it != other.end(); it++)
		if ((*it).second)
			this->at((*it).first) = (*it).second->clone();
}

void Environment::destroy()
{
	for (EnvironmentIterator it = begin(); it != end(); it++)
		delete (*it).second;
}

Environment::Environment(): std::map<Identifier, Value*>() {}

Environment::Environment(const Environment& other)
{
	copy(other);
}

Environment& Environment::operator=(const Environment& other)
{
	if (&other != this)
	{
		destroy();
		copy(other);
	}

	return *this;
}

Environment::~Environment()
{
	destroy();
}

