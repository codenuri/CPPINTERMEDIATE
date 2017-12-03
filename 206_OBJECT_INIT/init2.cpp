/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

int cnt = 0;

class Test
{
public:
//	int data = 0; // member initializer

	int data = ++cnt;

	Test() {}
	Test(int n) {}  //: data(n) {}
};

int main()
{
	Test t1;	// data = 1	
	Test t2(3);	// data = 3

	cout << cnt << endl; // 1

	cout << t1.data << endl;
	cout << t2.data << endl;
}
