/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>

class Test
{
public:
	Test()  { std::cout << "Test()" << std::endl; }
	~Test() { std::cout << "~Test()" << std::endl; }

	Test(const Test& t) 
	{ 
		std::cout << "Copy" << std::endl;
	}
	Test(Test&& t) noexcept
	{
		std::cout << "Move" << std::endl;
	}

	Test& operator=(const Test& t)
	{
		std::cout << "Copy=" << std::endl;
		return *this;
	}
	Test& operator=(Test&& t) noexcept
	{
		std::cout << "Move=" << std::endl;
		return *this;
	}
};