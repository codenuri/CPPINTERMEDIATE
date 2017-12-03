/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

struct Point
{
	int x, y;
};

class Complex
{
	int re, im;
public:
	Complex(int r, int i) : re(r), im(i) {}
};

int main()
{
//	int n = 0;
//	int x[2] = { 1,2 };
//	Point p = { 1,2 };
//	Complex c(1, 2);
	/*
	int  n{ 0 };
	int  x[2]{ 1,2 };
	Point   p{ 1,2 };
	Complex c{ 1, 2 };
	*/

	int  n = { 0 };
	int  x[2] = { 1,2 };
	Point   p = { 1,2 };
	Complex c = { 1, 2 };


	int n2 = 3.4; // ok
	//int n3 = { 3.4 }; // error.

	//char c1{ 300 }; // error
	char c2{ 100 }; // ok

}