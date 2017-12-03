/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : const1.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/
#include <iostream>
using namespace std;

class Point
{
public:
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b) {}

	void set(int a, int b) 
	{
		x = a; 
		y = b; 
	}
	void print()  //const	// 상수 멤버 함수
	{
	//	x = 10;	// error. 모든 멤버를 상수 취급한다.

		cout << x << ", " << y << endl;
	}
};

int main()
{
	const Point p(1, 1);

	p.x = 10;		// error
	p.set(10, 20);	// error
	p.print();		// ok. error.

}
