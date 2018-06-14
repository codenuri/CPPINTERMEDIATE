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
// temp5.cpp

Point foo()
{
	Point pt(1, 1); // 2. 생성자
	return pt;		// return Point(pt) 임시객체 생성
					// 3. 복사 생성자

	// 임시객체를 사용한 리턴
	// RVO ( Return Value Optimization )
	return Point(1, 1);
}					
int main()
{
	Point ret(0, 0); // 1. 생성자
	ret = foo();
	cout << endl;

}

