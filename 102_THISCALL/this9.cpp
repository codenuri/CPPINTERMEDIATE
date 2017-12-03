/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : this9.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

struct A { int a; };
struct B { int b; };

struct C : public A, public B
{
	int c;
};
int main()
{
	C obj;
	cout << &obj << endl; // 1000번지 일때

	A* pA = &obj;
	B* pB = &obj;

	cout << pA << endl;
	cout << pB << endl;
}




