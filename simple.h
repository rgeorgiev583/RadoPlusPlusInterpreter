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
#include "identifier.h"
#include "reference.h"
#include <string>


enum SIMPLE_STATEMENT_TYPE
{
	SIMPLE_STATEMENT_INVALID,
	STATEMENT_ASSIGNMENT,
	STATEMENT_RETURN,
	STATEMENT_OUTPUT,
	STATEMENT_INPUT
};

class SimpleStatement: public Statement
{
	Reference lhs;
	ExpressionTree rhs;

protected:
	SIMPLE_STATEMENT_TYPE type;

public:
	SimpleStatement(): Statement(STATEMENT_SIMPLE) {}
	SimpleStatement(const Reference& _lhs, const ExpressionTree& _rhs): Statement(STATEMENT_SIMPLE), lhs(_lhs), rhs(_rhs) {}
	SimpleStatement(const char*&);

	SimpleStatement* clone() const { return new SimpleStatement(*this); }

	const Reference& getLhs() const { return lhs; }
	ExpressionTreeConstIterator getRhsIterator() const { return rhs.getConstIterator(); }

	Value* execute(Environment&) const;
};


#endif /* SIMPLE_H_ */
