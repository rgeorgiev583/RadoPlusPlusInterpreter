/*
 * frame.h
 *
 *  Created on: Jan 14, 2015
 *      Author: radoslav
 */

#ifndef FRAME_H_
#define FRAME_H_

#include "exprtree.h"
#include "statement.h"
#include "identifier.h"
#include "value.h"
#include <queue>
#include <vector>
#include <map>


class CallStackFrame
{
	std::queue<Statement*, std::vector<Statement*> > procedure;
	Environment environment;

	void copy(const CallStackFrame&);
	void destroy();

public:
	CallStackFrame() {}
	CallStackFrame(const std::vector<Statement>& procedure_body, const Environment& arguments):
			procedure(procedure_body), environment(arguments) {}
	//CallStackFrame()


	Statement getNextStatement() const { return procedure.front(); }
	std::map<std::string, Value*>::const_iterator getStateIterator() const { return environment.begin(); }
};



#endif /* FRAME_H_ */
