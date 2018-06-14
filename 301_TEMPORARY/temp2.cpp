/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : temp2.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/
#include <iostream>

// 핵심 1. 임시객체를 생성하는 방법 - "클래스이름(생성자인자)"
//      2. 임시객체의 수명 - 문장의 끝.

struct Point
{
	int x, y;
	Point(int a = 0, int b = 0) { std::cout << "Point()"  << std::endl; }
	~Point()					{ std::cout << "~Point()" << std::endl; }
};

int main()
{
//	Point p1(1, 2);	//  named object.
//	Point(1, 2);	// unamed object. temporary.

	Point(1, 2), std::cout << "X" << std::endl;

	std::cout << "----------" << std::endl;
}

