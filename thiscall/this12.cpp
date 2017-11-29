/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : this12.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class A
{
	int a;
public:
	void fa() { cout << this << endl; }
};
class B
{
	int b;
public:
	void fb() { cout << this << endl; }
};

class C : public A, public B
{
	int c;
};

int main()
{
	C obj;
	cout << &obj << endl; // 1000

	obj.fa();  // 1000
	obj.fb();  // 1004

	void (C::*f)(); // 멤버 함수 포인터

	cout << sizeof(f) << endl; // 32bit 환경에서 8

	f = &C::fa; // f = { fa 주소, 0  };
	f = &C::fb; // f = { fb 주소, sizeof(A)};

	(obj.*f)(); // f.함수주소( &obj + f.this offset )
	/*
	if ( 사용자입력 == 1 )
		f = &C::fa;
	else 
		f = &C::fb;

	(obj.*f)(); // f( &obj  )
	*/
}