/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : name2.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <cstdio>

int square(int n)
{
	return n * n;
}
double square(double d)	
{
	return d * d;
}
int main()
{
	//printf("%p\n", &square); // error

	//printf("%p\n", static_cast<int(*)(int)>(&square)); // ok.

	//auto p = &square; // error

	int(*f)(int) = &square; // ok
}

