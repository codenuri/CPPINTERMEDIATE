/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

template<typename T> struct Plus
{
	T operator()(T a, T b) const 
	{
		return a + b;
	}
};

void foo(const Plus<int>& p) 
{
	int n = p(1, 2);
} 

int main()
{
	Plus<int> p;

}







