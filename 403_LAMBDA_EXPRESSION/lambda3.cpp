/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	// lambda expression 활용 1. 함수 인자로 사용
	//sort(x, x+10, [](int a, int b) { return a < b; });


	//[](int a, int b) { return a + b; };//임시객체생성

	//int n = [](int a, int b) { return a + b; }(1,2);

	// lambda expression 활용 2. auto 변수에 담아서
	//						함수 처럼 사용.
	auto f = [](int a, int b) { return a + b; };

	cout << f(1, 2) << endl; // 3

}
