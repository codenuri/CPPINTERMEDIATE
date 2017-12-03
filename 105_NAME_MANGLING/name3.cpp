/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : name3.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <typeinfo>
using namespace std;

void foo(int a) 
{
}
// a.exe | c++filt -t
int main()
{
	void(*f1)(int) = &foo; // ok. 함수 주소 꺼내기
	void(*f2)(int) = foo;  // 함수 이름은 함수 주소로 암시적 형변환

	typedef void(*PF)(int); // 함수 포인터 타입
	typedef void F(int);    // 함수 타입..

	cout << typeid(&foo).name() << endl; // void(*)(int)
	cout << typeid(foo).name() << endl;  // void(int)
}
