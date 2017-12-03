/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

int main()
{
	int n = 0;
	int* p = &n;

	decltype(n) n1; // int

	decltype(p) d1; // int*

	decltype(*p) d2; // int ? int&  // *p = 20
					 // int&.   error

	int x[3] = { 1,2,3 };

	decltype(x[0]) d3; // int&. error
	auto a1 = x[0];    // int

	decltype(++n) d4; // int&
	decltype(n++) d5; // int
}
