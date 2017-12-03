/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : this7.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <string>
#include "ecourse.hpp"	
using namespace std;
using namespace ecourse;

// 윈도우에서 발생하는 이벤트 처리함수.
int foo(int hwnd, int msg, int param1, int param2)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN: cout << hwnd << "LBD" << endl; break;
	case WM_KEYDOWN: cout << hwnd << "KEYDOWN" << endl; break;
	}
	return 0;
}

int main()
{
	int h1 = ec_make_window(foo); // 윈도우창 생성.
	int h2 = ec_make_window(foo); // 윈도우창 생성.

	ec_process_message();
}