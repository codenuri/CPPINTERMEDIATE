/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

int main()
{
//	int v1 = 10, v2 = 20;
//	auto f1 = [y = v1](int a) { return a + y; };


	int x = 4;
	auto y = [&r = x, x = x + 1]()->int
	{
		r += 2;
		return x * x;
	}();  
	
	cout << x << endl; // 6
	cout << y << endl; // 25
}