/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

int x = 10;
int  f1() { return x; }
int& f2() { return x; }

int main()
{
	int v1 = 10, v2 = 10;
	v1 = 20; // v1 : lvalue  20 : rvalue
	20 = v1; // error
	v2 = v1; //

	int* p1 = &v1; // ok
	int* p2 = &10; // error.

	f1() = 10; // error
	f2() = 20; // ok.

	const int c = 10;
	c = 20; // c는 rvalue ? lvalue ?
			// c 는 수정 불가능한 lvalue

	// rvalue가 모두 상수인 것은 아니다.
	//Point().x = 10; // error
	//Point().set(10, 20); // ok

}

