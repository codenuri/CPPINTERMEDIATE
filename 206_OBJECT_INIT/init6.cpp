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
	Point() : x(0), y(0) {}
	Point(int a) : x(a), y(0) {}
	explicit Point(int a, int b) : x(a), y(b) {}
};

void foo(Point p) {}

int main()
{
	Point p1{ 1,1 };
//	Point p2 = { 1,1 };

	foo( { 1,1 } ); 
}