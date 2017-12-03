/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : this1.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

// this1.cpp - 멤버함수의 호출원리

// 1. 멤버 함수는 1번째 인자로 객체의 주소(this) 가 추가된다.

// 2. static 멤버 함수는 인자로 객체의 주소(this) 가 추가되지 않는다.

class Point
{
	int x = 0, y = 0;
public:
	void set(int a, int b) // void set(Point* const this, int a, int b)
	{
		x = a;	// this->x = a;
		y = b;	// this->y = b;
	}
	static void foo(int a) // void foo( int a)
	{
		x = a;				// this->x = a;   변경해야 하는데.. this 가 없다. error
	}
};
// cl this1.cpp /FAs  => this1.asm
// g++ this1.cpp -S   => this1.s
int main()
{
	Point::foo(10); // push 10
					// call Point::foo

	Point p1;
	Point p2;

	// this call
	p1.set(10, 20);	// set(&p1, 10, 20)
					// push 20
					// push 10
					// lea  ecx, &p1    rcx, &p1 // 객체 주소는 레지스터로
					// call Point::set
}




