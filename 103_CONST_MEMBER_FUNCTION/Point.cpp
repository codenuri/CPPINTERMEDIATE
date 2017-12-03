/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : Point.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

// Point.cpp
#include <iostream>
#include "Point.h"

Point::Point(int a, int b) : x(a), y(b) 
{
}
void Point::set(int a, int b)
{
	x = a;
	y = b;
}
void Point::print() const
{
	std::cout << x << ", " << y << std::endl;
}