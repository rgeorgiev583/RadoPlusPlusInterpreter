/*
 * value.h
 *
 *  Created on: Jan 14, 2015
 *      Author: radoslav
 */

#ifndef VALUE_H_
#define VALUE_H_

#include "token.h"
#include <string>


enum VALUE_TYPE
{
	VALUE_INVALID,
	VALUE_INTEGER,
	VALUE_STRING,
	VALUE_OBJECT,
	VALUE_IDENTIFIER,
	VALUE_CALL
};

class Value: public Token
{
protected:
	VALUE_TYPE type;

public:
    Value(VALUE_TYPE _type = VALUE_INVALID): Token(TOKEN_VALUE), type(_type) {}

    virtual Value* clone() const = 0;

    VALUE_TYPE getValueType() const { return type; }
};


#endif /* VALUE_H_ */
