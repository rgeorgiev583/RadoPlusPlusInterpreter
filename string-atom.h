/*
 * string-atom.h
 *
 *  Created on: Jan 15, 2015
 *      Author: radoslav
 */

#ifndef STRING_ATOM_H_
#define STRING_ATOM_H_

#include "atom.h"


class String: public AtomicExpression
{
	std::string str;

public:
	String(const std::string& _str): AtomicExpression(ATOM_STRING), str(_str) {}
	String(const char*&);

	std::string getString() const { return str; }
};


#endif /* STRING_ATOM_H_ */
