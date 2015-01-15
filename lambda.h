/*
 * lambda.h
 *
 *  Created on: Jan 13, 2015
 *      Author: radoslav
 */

#ifndef LAMBDA_H_
#define LAMBDA_H_

#include "atom.h"
#include "statement.h"
#include <vector>
#include <map>
#include <string>


class Lambda: public AtomicExpression
{
	std::vector<std::string> signature;
	Statement body;

public:
	Lambda(): AtomicExpression(ATOM_LAMBDA) {}
	Lambda(const char*&);

	std::vector<std::string>::const_iterator getSignatureIterator() const { return signature.begin(); }
	const Statement& getBody() const { return body; }
};


#endif /* LAMBDA_H_ */
