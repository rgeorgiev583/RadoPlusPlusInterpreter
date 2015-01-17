/*
 * call.h
 *
 *  Created on: Jan 15, 2015
 *      Author: radoslav
 */

#ifndef CALL_H_
#define CALL_H_

#include "value.h"
#include "identifier.h"
#include "exprtree.h"
#include <vector>


enum CALL_TYPE
{
	CALL_INVALID,
	CALL_FUNCTION
};

class Call: public Value
{
protected:
	CALL_TYPE type;
	Identifier name;
	std::vector<ExpressionTree> arguments;

	void parse(const char*&);

public:
	static Call* create(const char*&);

	Call(CALL_TYPE _type = CALL_INVALID): Value(VALUE_CALL), type(_type) {}
	Call(CALL_TYPE _type, const Identifier& _name, const std::vector<ExpressionTree>& _arguments):
			type(_type), name(_name), arguments(_arguments) {}
	Call(const char*&);

	virtual Call* clone() const = 0;

	CALL_TYPE getCallType() const { return type; }
	const Identifier& getIdentifier() const { return name; }
	std::vector<ExpressionTree>::const_iterator getArgumentIterator() const { return arguments.begin(); }
	std::vector<ExpressionTree>::const_iterator getArgumentEndIterator() const { return arguments.end(); }

	virtual Value* execute(Environment&) const = 0;
};


#endif /* CALL_H_ */
