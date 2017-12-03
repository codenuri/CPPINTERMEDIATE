/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : this13.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/
#include <iostream>
using namespace std;

class Point
{
public:
	int x, y;
};

int main()
{
	int   n = 10;
	int* p1 = &n;

	//void(Point::*f)() = &Point::print; // 멤버 함수 포인터
	
	int Point::*p2 = &Point::x; // 멤버 변수 포인터
							    // 0
	int Point::*p3 = &Point::y; // 4
								// C의 offset_of

	//cout << p3 << endl;
	printf("%d, %d\n", p2, p3);

	Point pt;

	pt.y = 10;
	pt.*p3 = 20;

	cout << pt.y << endl; // 20
}