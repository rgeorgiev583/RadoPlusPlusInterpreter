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
	string program;

	while (!cin.eof())
	{
		string line;
		getline(cin, line);
		program += line + '\n';
	}

	const char* program_cstr = program.c_str();
	CompoundStatement cs(program_cstr);
	Environment e;
	cs.execute(e);
	return 0;
}

