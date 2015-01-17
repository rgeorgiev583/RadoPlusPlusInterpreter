/*
 * object.h
 *
 *  Created on: Jan 16, 2015
 *      Author: radoslav
 */

#ifndef OBJECT_H_
#define OBJECT_H_

#include "identifier.h"
#include "value.h"
#include "exprtree.h"
#include <map>


typedef std::map<Identifier, ExpressionTree>::iterator ObjectIterator;
typedef std::map<Identifier, ExpressionTree>::const_iterator ConstObjectIterator;

class Object: public Value, public std::map<Identifier, ExpressionTree>
{
public:
	Object(): Value(VALUE_OBJECT) {}
	Object(const char*&);

	Object* clone() const { return new Object(*this); }
};


#endif /* OBJECT_H_ */
