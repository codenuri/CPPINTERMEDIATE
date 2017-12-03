/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Test
{
public:
	Test() {}
	~Test() {}
	Test(const Test& t) { cout << "Copy" << endl; }
	Test(Test&& t) noexcept     { cout << "Move" << endl; }

	Test& operator=(const Test& t)
	{
		cout << "Copy=" << endl;
		return *this;
	}
	Test& operator=(Test&& t) noexcept
	{
		cout << "Move=" << endl;
		return *this;
	}
};

int main()
{
	/*
	Test* p1 = new Test[2];
	Test* p2 = new Test[4];

	for (int i = 0; i < 2; i++)
		//	p2[i] = p1[i];   // copy 대입
		p2[i] = move(p1[i]); // move 대입
	*/
	vector<Test> v(2);
	v.resize(4);

}


















