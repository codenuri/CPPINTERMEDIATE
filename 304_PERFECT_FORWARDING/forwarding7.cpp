/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

void foo(int a, int& b, double d) { b = 30; }
void goo() {}

template<typename F, typename ... Types>
decltype(auto) chronometry(F f, Types&& ... args)
{
	return f(std::forward<Types>(args)... );
}


int main()
{
	int x = 10;

	chronometry(&foo, 1, x, 3.4);
	chronometry(&goo);

	cout << x << endl; // 30
}




