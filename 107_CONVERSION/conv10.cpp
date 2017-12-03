/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <cstdlib>
using namespace std;


template<typename T> T* memAlloc(int sz )
{
	return (T*)malloc(sz);
}

int main()
{
	//double* p = memAlloc<double>(40);

	double* p1 = memAlloc(40);
	int*    p2 = memAlloc(40);

}

