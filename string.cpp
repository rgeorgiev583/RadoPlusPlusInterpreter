/*
 * string.cpp
 *
 *  Created on: Jan 14, 2015
 *      Author: radoslav
 */

#include "string.h"
#include <string>
#include <cstring>


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

std::string getToken(const std::string& str, const char* delim)
{
	size_t beg = str.find_first_not_of(delim);
	if (beg == std::string::npos)
		return std::string();

	size_t end = str.find_first_of(delim, beg);
	return end == std::string::npos ? str.substr(beg) : str.substr(beg, end - beg);
}

