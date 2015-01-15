/*
 * lambda.h
 *
 *  Created on: Jan 13, 2015
 *      Author: radoslav
 */

#ifndef LAMBDA_H_
#define LAMBDA_H_

#include "statement.h"
#include <vector>
#include <map>
#include <string>


class Lambda
{
	bool valid;
	std::vector<std::string> signature;
	Statement body;

public:
	Lambda() {}
	Lambda(const char*&);

	std::vector<std::string>::const_iterator getSignatureIterator() const { return signature.begin(); }
	const Statement& getBody() const { return body; }
};


#endif /* LAMBDA_H_ */
