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
	Point p1;	// 임시객체 아님. 이름있는 객체

	// 핵심 1. 임시객체는 등호(=)의 왼쪽에 올수 없다.
	p1.x = 10;		// ok
	//Point().x = 10;	// error

	// 핵심 2. 임시객체는 주소를 구할수 없다.
	Point* pp1 = &p1;		// ok
	Point* pp2 = &Point();	// error

	// 핵심 3. non-const reference 는 임시객체를 참조할 수 없다.
	//         const     reference 는 임시객체를 참조할 수 있다.
	Point& r1 = p1;			// ok
	Point& r2 = Point();	// error

	const Point& r3 = p1;		// ok
	const Point& r4 = Point();	// ok

	r4.x = 10; // error

	// C++11 : rvalue reference는 상수성 없이 rvalue를 가리킬수있다.
	Point&& r5 = p1; // error, rvalue reference 는 rvalue만 가리킬수 있다.
	Point&& r6 = Point();

}

