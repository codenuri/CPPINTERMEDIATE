/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : const2.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include "Point.h"
using namespace std;

int main()
{
	const Point p(1, 1);

	p.x = 10;		// error
	p.set(10, 20);	// error
	p.print();		// error.
					// 호출되게 하려면 print()를
					// 반드시 상수멤버함수가 되어야한다.
}

// 상수객체는 상수 멤버함수만 호출할수 있다.