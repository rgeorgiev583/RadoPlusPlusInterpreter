/*
 * main.cpp
 *
 *  Created on: Jan 16, 2015
 *      Author: radoslav
 */

#include "compound.h"
#include "environment.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string program, line;

	do
	{
		getline(cin, line);
		program += line + '\n';
	}
	while (!cin.eof() && line != "--");

	const char* program_cstr = program.c_str();
	CompoundStatement cs(program_cstr);
	Environment e;
	cs.execute(e);
	return 0;
}

