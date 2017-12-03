/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
#include <functional>  // less<>, greater<>
using namespace std;

//struct Less    { inline bool operator()(int a, int b) const { return a < b; } };
//struct Greater { inline bool operator()(int a, int b) const { return a > b; } };

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	less<int> f1;
	sort(x, x + 10, f1);

	sort(x, x + 10, less<int>());
}