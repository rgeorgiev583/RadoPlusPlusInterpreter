/*
 * reference.h
 *
 *  Created on: Jan 17, 2015
 *      Author: radoslav
 */

#ifndef REFERENCE_H_
#define REFERENCE_H_

#include "value.h"
#include "identifier.h"


class Reference: public Value
{
	Identifier objectName, memberName;

public:
	Reference(): Value(VALUE_REFERENCE) {}
	Reference(const Identifier& _object, const Identifier& _member):
			Value(VALUE_REFERENCE), objectName(_object), memberName(_member) {}
	Reference(const char*& code);

	Reference* clone() const { return new Reference(*this); }

	const Identifier& getObjectName() const { return objectName; }
	const Identifier& getMemberName() const { return memberName; }
};


#endif /* REFERENCE_H_ */
