/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : new4.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point()  { cout << "Point()"  << endl; }
	~Point() { cout << "~Point()" << endl; }
};

int main()
{
	Point p;

	//p.Point(); // error.
	p.~Point(); // ok.
	

}