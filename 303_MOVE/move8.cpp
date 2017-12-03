/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
#include <type_traits>
#include "Test.h"		// class Test {}
using namespace std;

int main()
{
	Test t1;
	Test t2 = t1; // copy
	Test t3 = move(t2); // move
	 
	bool b = is_nothrow_move_constructible<Test>::value;
	cout << b << endl;

	Test t4 = move_if_noexcept(t1);



	/*
	Test* p1 = new Test[2];
	Test* p2 = new Test[4];
	
	for (int i = 0; i < 2; i++)
		p2[i] = move( p1[i] );
		*/
}


















