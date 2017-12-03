/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : const5.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Point
{
	int x, y;

	// mutable  멤버 변수 : 상수멤버함수 안에서도 값을 변경가능.
	mutable char cache[16];
	mutable bool cache_valid = false;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	const char* toString() const
	{
		if (cache_valid == false)
		{
			sprintf(cache, "%d, %d", x, y);
			cache_valid = true;
		}
		return cache;
	}
};

int main()
{
	Point p1(1, 1);

	cout << p1.toString() << endl;
	cout << p1.toString() << endl;

}
