/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

// aggregate initialization
// aggregate type : {} 로 초기화 가능한것. 구조체, 배열.
struct Point
{
	int x, y;
	
	void foo() {}

//	virtual void foo() {} 

//	Point() = default;
//	Point() {}				// 1
//	Point(int a, int b) { }	// 2
};

int main()
{
	Point p1;			// 1. ok
	Point p2 { 1,2 };	// 2. ???
}
