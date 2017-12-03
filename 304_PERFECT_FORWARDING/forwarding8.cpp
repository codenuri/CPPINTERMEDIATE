/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a, int b, int& c)  { cout << "Point()" << endl; }
	~Point()             { cout << "~Point()" << endl; }
	Point(const Point&)  
	{
		cout << "Point(const Point&)" << endl; 
	}
};

int main()
{
	vector<Point> v;

//	Point p(1, 2);
//	v.push_back(p);

	// ¼Ò¸êÀÚ È£Ãâ È½¼ö : 2
	int n = 10;
	v.emplace_back(1, 2, n);
	// ¼Ò¸êÀÚ È£Ãâ È½¼ö : 1
}
