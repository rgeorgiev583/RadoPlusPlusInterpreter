/*
 * tokenizer.h
 *
 *  Created on: 03.06.2014
 *      Author: radoslav
 */

#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#include "coredefs.h"

class Tokenizer
{
protected:
	string sourcestring, delimiters, token;
	size_t offset, token_position;
	bool no_delimiters_found;

public:
	static const string WHITESPACE;
	Tokenizer();
	Tokenizer(const string&);
	Tokenizer(const string&, const string&);
	bool nextToken();
	bool nextToken(const string&);
	const string getToken() const;
	const size_t getTokenPosition() const;
	const size_t getOffset() const;
	bool wereDelimitersFound() const;
	void rewind(size_t = 0);
	void rewind(const string&, size_t = 0);
};

#endif /* TOKENIZER_H_ */
