/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/


class Point
{
	int x, y;
public:
	explicit Point(int a, int b) : x(a), y(b) {}
};

void foo(Point p) {}

int main()
{
	foo({ 1,1 });

//	Point p1(1, 1);

//	Point p2{ 1, 1 };	// direct initialize

//	Point p3 = { 1, 1 };// copy initialize. error
}
