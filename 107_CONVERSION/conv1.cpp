/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : conv1.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point()             : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}

	// 변환 연산자 : 객체를 다른 타입으로 변환할때 호출된다.
	// 특징 : 리턴 타입을 표기하지 않는다.
	operator int()
	{
		return x;
	}
};

int main()
{
	int    n = 3;
	double d = n; // 암시적 형변환 발생.

	Point p1(1, 2);
	n = p1;		// p1.operator int()

	cout << n << endl; // 1
}
















