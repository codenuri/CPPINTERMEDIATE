/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <memory>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a, int b) { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
	Point(const Point&)
	{
		cout << "Point(const Point&)" << endl;
	}
};

int main()
{	
	// 메모리 할당은 몇번 될까 ?
	//shared_ptr<Point> sp( new Point(1,2) );


	shared_ptr<Point> sp
		= make_shared<Point>(1, 2);
	
}
