/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

void goo(int& a)  { cout << "goo" << endl; }
void hoo(int&& a) { cout << "hoo" << endl; }


template<typename T> T&& xforward(T& arg)
{
	return static_cast<T&&>(arg);
}

template<typename F, typename T>
void chronometry(F f, T&& arg)
{
	//f(static_cast<T&&>(arg));

	f(forward<T&&>(static_cast<int&&>(arg))); 

	// lvalue 일때 T : int& => int&
	// rvalue 일때 T : int  => int&&
	//f(xforward(arg));
}

int main()
{
	int n = 0;

//	chronometry(&goo, n);
	chronometry(&hoo, 10);

	cout << n << endl;
}




