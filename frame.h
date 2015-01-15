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
#include "atom.h"
#include <queue>
#include <vector>
#include <map>


class CallStackFrame
{
	std::queue<Statement, std::vector<Statement> > procedure;
	std::map<std::string, ExpressionTree> state;

protected:


public:
	CallStackFrame() {}
	CallStackFrame(const std::vector<Statement>& procedure_body, const std::map<std::string, ExpressionTree>& arguments):
			procedure(procedure_body), state(arguments) {}


	Statement getNextStatement() const { return procedure.front(); }
	std::map<std::string, ExpressionTree>::const_iterator getStateIterator() const { return state.begin(); }

};



#endif /* FRAME_H_ */
