/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : new1.cpp
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
	Point* p1 = static_cast<Point*>(
				operator new(sizeof(Point)));

	operator delete(p1);

	/*
	// malloc : 메모리만 할당
	Point* p1 = (Point*)malloc(sizeof(Point));
	free(p1);

	// new : 메모리 할당 + 생성자 호출
	Point* p2 = new Point;	
	delete p2;									
	*/
}


