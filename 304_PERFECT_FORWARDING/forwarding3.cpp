/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

void goo(int& a) { cout << "goo" << endl; a = 30; }
void foo(int  a) { cout << "foo" << endl; }
void hoo(int&& a) { cout << "hoo" << endl; }

template<typename F> void chronometry(F f, int& arg)
{
	f(arg);
}
template<typename F> void chronometry(F f, int&& arg)
{
	// int&& arg = 10
	//f(arg);
	// 해결책 : lvalue인 arg를 rvalue로 다시 캐스팅한다
	f(static_cast<int&&>(arg));
}

int main()
{
	//hoo(10); // ok..
	chronometry(&hoo, 10); // error
	
	int&& arg = 10; // 10 은 rvalue,
					// arg는 lvalue 이다.

	
	int n = 0;

	chronometry(&goo, n);
	chronometry(&foo, 5);

	cout << n << endl;

}