/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : new5.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point()  { cout << "Point()" << endl; }
	~Point() { cout << "~Point()" << endl; }
};

// placement new : 생성자를 호출하기 위해 만든 new
// 
/*
void* operator new(size_t sz, void* p)
{
	return p;
}
*/
int main()
{
	Point p;	

	//new Point; // 인자가 1개인 operator new()호출.

	new(&p) Point; // 인자가 2개인 operator new()호출.
					// 메모리 할당이 아닌 생성자를
					// 호출하는 코드
	p.~Point(); 
}