/*
 * compound.h
 *
 *  Created on: Jan 14, 2015
 *      Author: radoslav
 */

#ifndef COMPOUND_H_
#define COMPOUND_H_

#include "statement.h"
#include <vector>


class CallStackFrame {};

class CompoundStatement : public Statement
{
	friend class CallStackFrame;

	std::vector<Statement> body;

public:
	CompoundStatement() {}
	CompoundStatement(const char*);

	std::vector<Statement>::const_iterator getIterator() const { return body.begin(); }
};



#endif /* COMPOUND_H_ */
