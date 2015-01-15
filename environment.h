/*
 * environment.h
 *
 *  Created on: Jan 13, 2015
 *      Author: radoslav
 */

#ifndef ENVIRONMENT_H_
#define ENVIRONMENT_H_

#include <map>
#include <stack>
#include "frame.h"
#include "statement.h"


class Environment
{
	std::stack<CallStackFrame> callStack;
	std::vector<Statement> program;
};


#endif /* ENVIRONMENT_H_ */
