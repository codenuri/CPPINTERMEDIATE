/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

int x = 10;

int& foo(int a, int b) 
{
	return x;
}

int main()
{
	auto ret1 = foo(1, 2); // int 

	// 평가되지 표현식(unevaluated expression)
	decltype( foo(1, 2) ) ret2 = foo(1,2);  // int&

	// C++14
	decltype(auto) ret3 = foo(1, 2); // int&


}