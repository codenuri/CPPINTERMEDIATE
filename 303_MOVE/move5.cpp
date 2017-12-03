/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class Test
{
public:
	Test() {}
	~Test() {}
	Test(const Test& t) { cout << "Copy" << endl; }
	Test(Test&& t)      { cout << "Move" << endl; }

	Test& operator=(const Test& t) { return *this; } // 복사 대입연산자
	Test& operator=(Test&& t)      { return *this; } // move 대입연산자
};

int main()
{
	Test t1;
	Test t2 = t1;	// 초기화. 복사 생성자
	t2 = t1;		// 대입.   대입 연산자

	t2 = move(t1);


}











