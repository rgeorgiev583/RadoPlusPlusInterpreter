/*
 * statement.h
 *
 *  Created on: Jan 14, 2015
 *      Author: radoslav
 */

#ifndef STATEMENT_H_
#define STATEMENT_H_

#include "exprtree.h"
#include <vector>


enum STATEMENT_TYPE
{
	STATEMENT_INVALID,
	STATEMENT_ASSIGNMENT,
	STATEMENT_RETURN,
	STATEMENT_OUTPUT,
	STATEMENT_INPUT,
	STATEMENT_CONDITIONAL,
	STATEMENT_COMPOUND
};

class Statement
{
	STATEMENT_TYPE type;
	std::string lhs;
	ExpressionTree rhs;
	std::vector<Statement> body;
	//Statement statement_condition_true, statement_condition_false;

public:
	Statement(): type(STATEMENT_INVALID) {}
	Statement(ExpressionTree _rhs, STATEMENT_TYPE _type): type(_type), rhs(_rhs) {}
	Statement(const char*&);

	STATEMENT_TYPE getType() const { return type; }
	const std::string& getLhs() const { return lhs; }
	ExpressionTreeIterator getRhsIterator() const { return rhs.iterator(); }
};


#endif /* STATEMENT_H_ */
