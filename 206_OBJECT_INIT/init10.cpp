/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <initializer_list>
using namespace std;

int main()
{
	// brace-init-list
	// VC++ : int* first, *last
	// g++  : int* first, count
	initializer_list<int> s = { 1, 2, 3, 4, 5 };

	auto p = begin(s); // 상수를 가리키는 반복자
	//*p = 20; // error

	cout << *p << endl;

}