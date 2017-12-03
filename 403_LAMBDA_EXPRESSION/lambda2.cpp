/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;


int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	
	sort(x, x+10, less<int>());


	sort(x, x+10, [](int a, int b) { return a < b; });


	bool b = [](int a, int b) { return a < b; }(1, 2);
		// class ClosureType{};ClosureType()(1,2);

	cout << b << endl; // 1
}















