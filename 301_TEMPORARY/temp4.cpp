/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) { cout << "Point()" << endl; }
	~Point()					{ cout << "~Point()" << endl; }
};

// 임시객체와 함수 인자
void foo(const Point& p) 
{
}
int main()
{
	Point p(1,1);
	foo(p);

	foo(Point(1, 1));

	// STL에서 임시객체를 사용하는 경우
//	sort(x, x + 10, less<int>());

	cout << "end" << endl;

}

