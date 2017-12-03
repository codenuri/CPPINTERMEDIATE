/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : const3.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

// 객체의 상태를 변경하지 않은 모든 멤버함수는(getxxx)
// 반드시 const 멤버 함수가 되어야 한다.
struct Rect
{
	int ox, oy, width, height;

	Rect(int x = 0, int y = 0, int w = 0, int h = 0) 
		: ox(x), oy(y), width(w), height(h) {}

	int getArea() const {	return width * height; }
};

void foo(  const Rect& r) // call by value 보다는 const & 가 좋다.
{
	int n = r.getArea(); // error.
}

int main()
{
	Rect r(0, 0, 10, 10);

	int n = r.getArea(); // ok.

	foo(r);
}