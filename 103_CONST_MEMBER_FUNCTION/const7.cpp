/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : const7.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/
#include <iostream>
using namespace std;

struct Test
{
	void foo()		 { cout << "foo()" << endl; }		  // 1
	void foo() const { cout << "foo() const" << endl;	} // 2

	void goo() const;
};

void Test::goo() const
{

}


int main()
{
	Test t1;
	t1.foo(); // 1번, 없으면 2번

	const Test t2;
	t2.foo(); // 2번, 없으면 error
}














