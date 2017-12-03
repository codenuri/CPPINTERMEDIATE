/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : Point.h
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

// Point.h
class Point
{
public:
	int x, y;
	Point(int a = 0, int b = 0);
	void set(int a, int b);
	void print() const;
};