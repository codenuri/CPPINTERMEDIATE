/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor11.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <memory>
using namespace std;

struct Resource
{
	Resource() { cout << "acquire Resource" << endl; }
	~Resource() { cout << "release Resource" << endl; }
};

// 해결책 2. two-phase constructor

class Test
{
	Resource* p;
public:
	Test() : p(0)
	{
		// 예외 가능성이 있는 어떠한 작업도 하지 않는다.
		// 가상함수 호출()
	}

	// 자원 할당 전용함수
	void Construct()
	{
		p = new Resource;
		//cout << "Test()" << endl;
		// 가상함수 호출()
		throw 1;
	}

	~Test()
	{
		delete p;
		cout << "~Test()" << endl;
	}
};


int main()
{
	try
	{
		Test t;
		t.Construct(); // 필요한 자원 할당.
	}
	catch (...)
	{
		cout << "예외 발생" << endl;
	}
}

