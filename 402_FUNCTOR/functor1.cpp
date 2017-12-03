/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

// functor1.cpp
// Function Object(functor)
class Plus
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};

int main()
{
	Plus p; // Plus ≈∏¿‘¿« ∞¥√º

	int n = p(1, 2); // p.operator()(1,2)

	cout << n << endl; // 3

	// a + b;	// a.operator+(b)
	// a - b;	// a.operator-(b)
	// a();		// a.operator()()
	// a(1,2);	// a.operator()(1,2)
}