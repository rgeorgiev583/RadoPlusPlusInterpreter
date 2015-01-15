/*
 * statement.h
 *
 *  Created on: Jan 14, 2015
 *      Author: radoslav
 */

#ifndef STATEMENT_H_
#define STATEMENT_H_

#include "value.h"


enum STATEMENT_TYPE
{
	STATEMENT_INVALID,
	STATEMENT_SIMPLE,
	STATEMENT_CONDITIONAL,
	STATEMENT_COMPOUND
};

class Statement: public Value
{
	STATEMENT_TYPE type;

public:
	static Statement* createStatement(const char*&);

	Statement(STATEMENT_TYPE _type = STATEMENT_INVALID): type(_type) {}

	virtual Statement* clone() const = 0;

	STATEMENT_TYPE getType() const { return type; }
};


#endif /* STATEMENT_H_ */
