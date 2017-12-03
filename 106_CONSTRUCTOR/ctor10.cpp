/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor10.cpp
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

// 해결책 1. Raw Pointer 대신 스마트 포인터 사용

class Test
{
//	Resource* p;
	unique_ptr<Resource> p;
public:
	Test() : p(new Resource)
	{
		cout << "Test()" << endl;
		throw 1;
	}
	~Test()
	{
		//delete p;
		cout << "~Test()" << endl;
	}
};

int main()
{
	try
	{
		Test t;
	}
	catch (...)
	{
		cout << "예외 발생" << endl;
	}
}

