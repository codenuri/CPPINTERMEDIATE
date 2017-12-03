/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : new2.cpp
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

void* operator new(size_t sz)
{
	cout << "my new" << endl;
	return malloc(sz);
}

void operator delete(void* p) noexcept
{
	cout << "my delete" << endl;
	free(p);
}

int main()
{
	Point* p = new Point;	// 1. 메모리 할당 - operator new( sizeof(Point))
							// 2. 생성자 호출
	delete p;
}


