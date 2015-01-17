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
#include <map>


typedef std::map<Identifier, Value*>::iterator ObjectIterator;
typedef std::map<Identifier, Value*>::const_iterator ConstObjectIterator;

class Object: public Value, public std::map<Identifier, Value*>
{
	void copy(const Object&);
	void destroy();

public:
	Object(): Value(VALUE_OBJECT) {}
	Object(const char*&);
	Object(const Object&);
	Object& operator=(const Object&);
	~Object();

	Object* clone() const { return new Object(*this); }
}


#endif /* OBJECT_H_ */
