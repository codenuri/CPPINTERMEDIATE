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
	~Point() { cout << "~Point()" << endl; }
};
// temp6.cpp

Point p; // 전역변수

Point foo() // 값리턴 : 임시객체가 리턴된다.
{
	return p;
}

Point& goo() // 참조리턴 : 임시객체가 생성되지 않는다.
{
	return p;
}
int main()
{
	//Point ret = foo();

	foo().x = 10; // error
	goo().x = 20; // ok
	cout << p.x << endl;
}

