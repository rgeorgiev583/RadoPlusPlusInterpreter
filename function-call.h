/*
 * function-call.h
 *
 *  Created on: Jan 17, 2015
 *      Author: radoslav
 */

#ifndef FUNCTION_CALL_H_
#define FUNCTION_CALL_H_

#include "call.h"
#include "environment.h"
#include <vector>
#include <map>


class FunctionCall: public Call
{
public:
	FunctionCall(): Call(CALL_FUNCTION) {}
	FunctionCall(const Identifier& _name, const std::vector<ExpressionTree>& _arguments):
			Call(CALL_FUNCTION, _name, _arguments) {}
	FunctionCall(const char*&);

	FunctionCall* clone() const { return new FunctionCall(*this); }

	Value* execute(Environment&) const;
};


#endif /* FUNCTION_CALL_H_ */
