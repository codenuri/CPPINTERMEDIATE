/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
	auto f1 = [](int a, int b) { return a + b; };
		// class ClosureType{}; ClosureType();

	auto f2 = [](int a, int b) { return a + b; };

	//f2 = [](int a, int b) { return a + b; };

	cout << typeid(f1).name() << endl;
	cout << typeid(f2).name() << endl;

}