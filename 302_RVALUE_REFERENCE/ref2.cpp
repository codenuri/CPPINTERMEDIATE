/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

int main()
{
	int n = 10;

	// 규칙 1. not const lvalue reference 는 lvalue 만 참조 가능
	int& r1 = n;	// ok
	int& r2 = 10;	// error

	// 규칙 2. const lvalue reference 는 lvalue 와 rvalue를 모두 참조 가능
	const int& r3 = n;	// ok
	const int& r4 = 10;	// ok   

	//const Point& r = Point(1, 1);
	//r.x = 10;

	// 규칙 3. rvalue reference 는 rvalue 만 가리킬수 있다. C++11 문법.
	int&& r1 = n;	// error
	int&& r2 = 10;	// ok.
}