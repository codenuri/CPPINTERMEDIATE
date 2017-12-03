/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor4.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

class Point
{
	int x, y;
public:
//	Point()             : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};
class Rect
{
	Point p1;
	Point p2;
public:
	Rect() : p1(0,0), p2(0,0) //: p1(), p2()
	{
	}
};

int main()
{
	Rect r; // p1税 持失切, p2 持失切, Rect 持失切
}