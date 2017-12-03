/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : const4.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/
#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	const char* toString() const
	{
		static char s[16];
		sprintf(s, "%d, %d", x, y);
		return s;
	}
};

int main()
{
	const Point p1(1, 1);

	cout << p1.toString() << endl;
}
