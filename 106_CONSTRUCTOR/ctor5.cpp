/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor5.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

struct BM { BM() { cout << "BM()" << endl; } };
struct DM { DM() { cout << "DM()" << endl; } };

struct Base
{
	BM bm;
	int x;
	Base() { cout << "Base()" << endl; }
};

struct Derived : public Base
{
	DM dm;
	int y;
	Derived() : dm(), Base()
	{
		cout << "Derived()" << endl; 
	}
};

int main()
{
	Derived d;
}






