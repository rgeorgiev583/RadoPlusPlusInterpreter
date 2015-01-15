/*
 * arithmetic.cpp
 *
 *  Created on: Jan 14, 2015
 *      Author: radoslav
 */

#include "arithmetic.h"


int priority(char op)
{
	switch (op)
    {
        case '+': case '-':           return 1;
        case '*': case '/': case '%': return 2;
        case '^':                     return 3;
        default:                      return -1;
	}
}

int ipow(int a, int n)
{
    if (a == 0)
        return 0;
    else if (a == 1 || n <= 0)
        return 1;
    else if (n % 2)
        return a * ipow(a, n - 1);
    else
    {
        int b = ipow(a, n / 2);
        return b * b;
    }
}

