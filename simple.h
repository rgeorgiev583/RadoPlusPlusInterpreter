/*
 * simple.h
 *
 *  Created on: Jan 15, 2015
 *      Author: radoslav
 */

#ifndef SIMPLE_H_
#define SIMPLE_H_

#include "statement.h"
#include "exprtree.h"
#include <string>


enum SIMPLE_STATEMENT_TYPE
{
	STATEMENT_ASSIGNMENT,
	STATEMENT_RETURN,
	STATEMENT_OUTPUT,
	STATEMENT_INPUT
};

class SimpleStatement: public Statement
{
	SIMPLE_STATEMENT_TYPE type;
	std::string lhs;
	ExpressionTree rhs;

public:
	SimpleStatement(): Statement(STATEMENT_SIMPLE) {}
	SimpleStatement(const std::string& _lhs, const ExpressionTree& _rhs): Statement(STATEMENT_SIMPLE), lhs(_lhs), rhs(_rhs) {}
	SimpleStatement(const char*&);

	SimpleStatement* clone() const { return new SimpleStatement(*this); }

	const std::string& getLhs() const { return lhs; }
	ExpressionTreeIterator getRhsIterator() const { return rhs.iterator(); }
};


#endif /* SIMPLE_H_ */
