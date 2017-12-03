/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <type_traits>
#include "Test.h"		
using namespace std;

int main()
{
	vector<Test> v(2);
	v.resize(4);
	cout << "--" << endl;
}


/*
int main()
{
	Test* p1 = static_cast<Test*>(
		operator new(sizeof(Test) * 2));

	for (int i = 0; i < 2; i++)
		new(&p1[i]) Test;
	//-----------------------------

	Test* p2 = static_cast<Test*>(
		operator new(sizeof(Test) * 4));

	for (int i = 0; i < 2; i++)
	{
		new(&p2[i]) Test(move_if_noexcept(p1[i]));
	}

	for (int i = 2; i < 4; i++)
		new(&p2[i]) Test;
	//---------------
	// 최초 버퍼 파괴
	for (int i = 1; i >= 0; i--)
		p1[i].~Test();

	operator delete(p1);
	cout << "---" << endl;
	//--------------------
	for (int i = 3; i >= 0; i--)
		p2[i].~Test();

	operator delete(p2);
}
*/





















