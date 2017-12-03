/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : this10.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class A { int a; };
class B { int b; };

class C : public A, public B
{
	int c;
};

int main()
{
	C obj;

	A* pA = &obj;
	B* pB = &obj; // &obj + sizeof(A)

	cout << &obj << endl; // 1000 
	cout << pA   << endl; // 1000
	cout << pB   << endl; // 1004
}