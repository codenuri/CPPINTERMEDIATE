/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : this3.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

// this3.cpp - thiscall 활용 예제
#include <iostream>
#include <windows.h> // windows 용 함수들..
using namespace std;

DWORD __stdcall foo(void* p)
{
	return 0;
}

int main()
{
	CreateThread(0, 0, 
				foo,		// 스레드로 수행할 함수
				(void*)"A", // 스레드 함수로 보낼인자
				0, 0);
}




// 빌드 하는 법
// mingw : g++ this3.cpp

// VC    : cl this3.cpp /nologo /EHsc  

//		   주의! "VC++ 확장 문법 사용"을 사용해야 함.
//			/Za 옵션을 지정하면 컴파일 안됨.