/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : this5.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include "ecourse.hpp"	// cl
using namespace std;
using namespace ecourse;

void foo(int id)
{
	cout << "foo : " << id << endl;
}

int main()
{
	int n1 = ec_set_timer(500, foo); // 500ms 마다 foo 호출
	int n2 = ec_set_timer(1000, foo); // 1000ms 마다 foo 호출

	ec_process_message();
}