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
	auto f1 = [](int a, int b) { return a + b; };

	auto f2 = [](int a, int b) -> int { return a + b; };

	auto f3 = [](int a, int b){ 
						if (a == 1)
							return a;
						else
							return b;
						};

	auto f4 = [](int a, double b) -> double {
						if (a == 1)
							return a;
						else
							return b;
					};

}