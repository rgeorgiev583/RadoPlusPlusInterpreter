/*
 * lambda.h
 *
 *  Created on: Jan 13, 2015
 *      Author: radoslav
 */

#ifndef LAMBDA_H_
#define LAMBDA_H_

#include "value.h"
#include "compound.h"
#include "identifier.h"
#include <vector>
#include <map>
#include <string>


class Lambda: public Value
{
	std::vector<Identifier> signature;
	Statement* body;

	void copy(const Lambda&);
	void destroy();

public:
	Lambda(): Value(VALUE_LAMBDA) {}
	Lambda(const char*&);
	Lambda(const Lambda&);
	Lambda& operator=(const Lambda&);
	~Lambda();

	Lambda* clone() const { return new Lambda(*this); }

	std::vector<Identifier>::const_iterator getSignatureIterator() const { return signature.begin(); }
	std::vector<Identifier>::const_iterator getSignatureEndIterator() const { return signature.end(); }
	const Statement* getBody() const { return body; }
};


#endif /* LAMBDA_H_ */
