/*
 * compound.h
 *
 *  Created on: Jan 15, 2015
 *      Author: radoslav
 */

#ifndef COMPOUND_H_
#define COMPOUND_H_

#include "statement.h"
#include <vector>


class CompoundStatement: public Statement
{
	std::vector<Statement*> body;

	void copy(const CompoundStatement&);
	void destroy();

public:
	CompoundStatement(): Statement(STATEMENT_SIMPLE) {}
	CompoundStatement(const char*&);
	CompoundStatement(const CompoundStatement&);
	CompoundStatement& operator=(const CompoundStatement&);
	~CompoundStatement();

	CompoundStatement* clone() const { return new CompoundStatement(*this); }

	std::vector<Statement*>::const_iterator getBodyIterator() const { return body.begin(); }
};


#endif /* COMPOUND_H_ */
