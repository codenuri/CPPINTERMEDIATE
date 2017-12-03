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
	int  n = 10;
	int& r = n;

	auto a = r; // a ? int ? int&
	a = 30;

	cout << n << endl; // 30 ? 10
}