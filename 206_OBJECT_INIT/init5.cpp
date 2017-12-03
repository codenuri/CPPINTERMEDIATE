/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

class Point
{
	int x, y;
public:
	// explicit : 변환 생성자로 사용될수 없다.
	//		      copy initialization 될수 없다.
	explicit Point()    		 : x(0), y(0) {}
	explicit Point(int a)        : x(a), y(0) {}
	explicit Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	Point p1(5);	// ok.
	//Point p2 = 5;	// ok. 하지만 생성자 explicit 라면 error.

	Point p3(1, 1);		// ok
	//Point p4 = (1, 1);	// error.

	Point p5{ 1,1 };	// ok
	//Point p6 = { 1,1 };	// ok. 하지만 생성자 explicit 라면 error.

	Point p7;
	Point p8{};		// direct
	//Point p9 = {};  // copy. error
}