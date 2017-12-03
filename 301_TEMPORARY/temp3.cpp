/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : temp3.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/
#include <iostream>
using namespace std;

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) { cout << "Point()" << endl; }
	~Point()					{ cout << "~Point()" << endl; }
};

int main()
{
	//	Point p1(1, 2);	// 이름 있는 객체
	//	Point(1, 2);	// temporary. unamed object

	Point(1, 2), cout << "X" << endl;

	cout << "----------" << endl;
}

