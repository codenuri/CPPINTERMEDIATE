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

/*
struct xnullptr_t
{
	//operator void*() { return 0; }
	//operator char*() { return 0; }
	template<typename T>
	operator T*() { return 0; }
};
xnullptr_t xnullptr; // 포인터 0
*/
// C++ 11: nullptr
int main()
{
//	foo(0);			// 1
//	foo(xnullptr);	// 2. xnullptr_t => void* 로의 암시적 변환 필요..
					//    xnullptr.operator void*()
//	goo(xnullptr);  // 3 goo

	int n = 0;
//	double* p1 = xnullptr;

	double* p2 = nullptr; // C++11 의 포인터 0
						  
	nullptr_t a = nullptr;

	int* p = a;
}



































