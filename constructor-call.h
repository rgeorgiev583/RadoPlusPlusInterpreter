/*
 * constructor-call.h
 *
 *  Created on: Jan 17, 2015
 *      Author: radoslav
 */

#ifndef CONSTRUCTOR_CALL_H_
#define CONSTRUCTOR_CALL_H_

#include "call.h"

class ConstructorCall: public Call
{
public:
	ConstructorCall(): Call(CALL_FUNCTION) {}
	ConstructorCall(const Identifier& _name, const std::vector<ExpressionTree>& _arguments):
			Call(CALL_FUNCTION, _name, _arguments) {}
	ConstructorCall(const char*&);

	ConstructorCall* clone() const { return new ConstructorCall(*this); }

	Value* execute(Environment&) const;
};


#endif /* CONSTRUCTOR_CALL_H_ */
