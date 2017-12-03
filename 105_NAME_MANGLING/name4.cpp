/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : name4.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

struct FLOAT 
{
	FLOAT(float) {} // 변환 생성자. 
					// float => FLOAT로 변환허용
};

//template<typename T> 
//void foo(T  )    { cout << "T"      << endl; }
//void foo(int)    { cout << "int"    << endl; }
//void foo(double) { cout << "double" << endl; }
//void foo(float)  { cout << "float"  << endl; }
//void foo(FLOAT)  { cout << "FLOAT"  << endl; }
void foo(...)    { cout << "..."    << endl; }

int main()
{
	float f = 3.4f;
	foo(f);
}






