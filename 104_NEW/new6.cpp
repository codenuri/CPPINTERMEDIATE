/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : new6.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point() { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

int main()
{
	// malloc : 메모리만 할당
	Point* p1 = (Point*)malloc(sizeof(Point));


	// new : 객체의 생성 ( 메모리 할당 + 생성자 호출)
	Point* p2 = new Point;


	Point* p3 = new Point;		// 새로운메모리에 객체를 생성해 달라
	Point* p4 = new(p1) Point;	// 기존 메모리에 객체를 생성해 달라.
} 