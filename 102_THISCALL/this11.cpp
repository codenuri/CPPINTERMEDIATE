/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : this11.cpp
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

	obj.fa(); // fa(&obj)   cout << this => 1000
	obj.fb(); // fb(&obj + sizeof(A)) cout << this => 1004


}