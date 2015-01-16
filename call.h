/*
 * call.h
 *
 *  Created on: Jan 15, 2015
 *      Author: radoslav
 */

#ifndef CALL_H_
#define CALL_H_

#include "identifier.h"
#include "exprtree.h"
#include "lambda.h"
#include "environment.h"
#include <vector>
#include <map>

class Call: public Value
{
	Identifier name;
	std::vector<ExpressionTree> arguments;
	Lambda* lambda;

	void create(const char*&);
	void assignLambda(Environment&);

public:
	Call(): Value(VALUE_CALL), lambda(NULL) {}
	Call(const Identifier& _name, const std::vector<ExpressionTree>& _arguments): name(_name), arguments(_arguments), lambda(NULL) {}
	Call(const Identifier&, const std::vector<ExpressionTree>&, Environment&);
	Call(const char*&);
	Call(const char*&, Environment&);

	Call* clone() const { return new Call(*this); }

	const Identifier& getIdentifier() const { return name; }
	std::vector<ExpressionTree>::const_iterator getArgumentIterator() const { return arguments.begin(); }
	std::vector<ExpressionTree>::const_iterator getArgumentEndIterator() const { return arguments.end(); }
	const Lambda* getLambda() const { return lambda; }
};


#endif /* CALL_H_ */
