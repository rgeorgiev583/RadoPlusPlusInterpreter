/*
 * cloneable.h
 *
 *  Created on: Jan 15, 2015
 *      Author: radoslav
 */

#ifndef CLONEABLE_H_
#define CLONEABLE_H_


class Cloneable
{
public:
	virtual ~Cloneable() {}

	virtual Cloneable* clone() const = 0;
};


#endif /* CLONEABLE_H_ */
