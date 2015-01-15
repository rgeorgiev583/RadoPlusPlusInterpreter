/*
 * tokenizer.cpp
 *
 *  Created on: 04.06.2014
 *      Author: radoslav
 */

#include "../headers/tokenizer.h"

const string Tokenizer::WHITESPACE(" \t\n\r");

Tokenizer::Tokenizer(): offset(0), token_position(string::npos),
		no_delimiters_found(false) {}

Tokenizer::Tokenizer(const string& _sourcestring):
		sourcestring(_sourcestring), delimiters(WHITESPACE), offset(0),
		token_position(string::npos), no_delimiters_found(false) {}

Tokenizer::Tokenizer(const string& _sourcestring,
		const string& _delimiters):
		sourcestring(_sourcestring), delimiters(_delimiters), offset(0),
		token_position(string::npos), no_delimiters_found(false) {}

bool Tokenizer::nextToken()
{
    return nextToken(delimiters);
}

bool Tokenizer::nextToken(const string& delimiters)
{
    size_t i = sourcestring.find_first_not_of(delimiters, offset);
    if (i == string::npos)
    {
        offset = sourcestring.length();
        return false;
    }

    size_t j = sourcestring.find_first_of(delimiters, i);
    if (j == string::npos)
    {
        token = sourcestring.substr(i);
        token_position = i;
        offset = sourcestring.length();
        no_delimiters_found = true;
        return true;
    }

    token = sourcestring.substr(i, j - i);
    token_position = i;
    offset = j;
    return true;
}

const string Tokenizer::getToken() const
{
	return token;
}

const size_t Tokenizer::getTokenPosition() const
{
	return token_position;
}

const size_t Tokenizer::getOffset() const
{
	return offset;
}

bool Tokenizer::wereDelimitersFound() const
{
	return !no_delimiters_found;
}

void Tokenizer::rewind(size_t _offset)
{
	offset = _offset;
	no_delimiters_found = false;
}

void Tokenizer::rewind(const string& _delimiters, size_t _offset)
{
	rewind(_offset);
	delimiters = _delimiters;
}
