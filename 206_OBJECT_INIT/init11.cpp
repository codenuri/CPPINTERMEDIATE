/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <initializer_list>
using namespace std;

void foo( initializer_list<int> e )
{
	auto p1 = begin(e);
	auto p2 = end(e);

	for (auto n : e)
		cout << n << " ";
	cout << endl;
}

int main()
{
	initializer_list<int> e1 = { 1,2,3 };
	initializer_list<int> e2  { 1,2,3,4,5 };

	foo(e1);
	foo({ 1,2,3,4 });
	foo({ 1,2,3,4,5,6,7 });

}