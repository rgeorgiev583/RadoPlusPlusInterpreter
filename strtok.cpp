/*
 * strtok.cpp
 *
 *  Created on: Jan 14, 2015
 *      Author: radoslav
 */

#include <string>
#include <cstring>
#include "strtok.h"


std::string getToken(const char*& str, const char* delim)
{
	if (!str)
		return NULL;

	str += strspn(str, delim);
	size_t len = strcspn(str, delim);
	const char* beg = str;
	str += len;
	return std::string(beg, len);
}

std::string peekToken(const char*& str, const char* delim)
{
	if (!str)
		return NULL;

	str += strspn(str, delim);
	size_t len = strcspn(str, delim);
	const char* beg = str;
	return std::string(beg, len);
}

bool gotoToken(const char*& str, const char* delim)
{
	if (!str)
		return false;

	str += strspn(str, delim);
	return *str;
}

bool ignoreToken(const char*& str, const char* delim)
{
	if (!str)
		return false;

	str += strspn(str, delim);

	if (!*str)
		return false;

	str += strcspn(str, delim);
	return true;
}

std::string peekToken(const std::string& str, const char* delim)
{
	size_t beg = str.find_first_not_of(delim);
	if (beg == std::string::npos)
		return std::string();

	size_t end = str.find_first_of(delim, beg);
	return end == std::string::npos ? str.substr(beg) : str.substr(beg, end - beg);
}


