/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <typeinfo>
#include <vector>
using namespace std;

int main()
{
	// 배열.
	int x[3] = { 1,2,3 }; // x : int[3]

	auto  a1 = x;	// int a1[3] = x; error
					// int* a1 = x; 

	auto& a2 = x;	// int (&a2)[3] = x; // ok
					// a2 : int (&)[3]
	
	decltype(x) d;  // int [3]

	cout << typeid(a1).name() << endl; // int*
	cout << typeid(a2).name() << endl; // int(&)[3]
	cout << typeid(d).name() << endl;  // int [3]

	//------------------------

	auto a3 = 1;	// int
	auto a4{ 1 };	// int
	auto a5 = { 1 };// int ? initializer_list => initializer_list

	cout << typeid(a4).name() << endl;
	cout << typeid(a5).name() << endl;

	//--------------------------

	vector<int> v1(10, 0);
	auto a6 = v1[0];	// int

	vector<bool> v2(10, 0);
	auto a7 = v2[0];	// bool xx

	cout << typeid(a6).name() << endl; // int
	cout << typeid(a7).name() << endl; // temporary proxy 참고

}