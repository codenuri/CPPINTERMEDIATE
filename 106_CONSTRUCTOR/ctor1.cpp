/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor1.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Base
{
public:
//	Base()      { cout << "B()"    << endl; }
	Base(int a) { cout << "B(int)" << endl; }
	~Base()     { cout << "~B()"   << endl; }
};

class Derived : public Base
{
public:
	Derived()     : Base(0) { cout << "D()" << endl; }
	Derived(int a): Base(a) { cout << "D(int)" << endl; }
	~Derived()     { cout << "~D()" << endl; }
};

int main()
{
	//Derived d;
	Derived d(5);
}