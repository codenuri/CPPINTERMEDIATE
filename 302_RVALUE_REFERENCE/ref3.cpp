/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

void foo(int& a)       { cout << "int&" << endl; }			// 1
void foo(const int& a) { cout << "const int&" << endl; }	// 2
void foo(int&& a)      { cout << "int&&" << endl; }			// 3

int main()
{
	int n = 10;

	foo(n);	// 1번, 1번이 없으면 2번
	foo(10);// 3번, 3번이 없으면 2번

	int& r1 = n;
	foo(r1);	// 1번, 없으면 2번

	int&& r2 = 10;	// 10은 rvalue, 10을 가리키는 이름있는 
					//				r2 참조변수는 lvalue 이다.
	foo(r2);		// 1번. 

	foo(static_cast<int&&>(r2));  // 3번.
}