/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

void foo(int n)   { cout << "int" << endl; }	// 1
void foo(void* p) { cout << "void*" << endl; }	// 2

void goo(char* p) { cout << "goo" << endl; }	// 3

int main()
{
	foo(0);			// 1
	foo((void*)0);	// 2

#ifdef __cplusplus
	#define NULL	0
#else
	#define NULL (void*)0
#endif

	foo(NULL);		// 2

	goo(NULL);	// void* => char* 로의 암시적 변환 필요.
				// C   : ok
				// C++ : 암시적 변환 안됨.
}



















