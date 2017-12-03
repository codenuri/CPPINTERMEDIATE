/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Test
{
public:
	Test() {}
	~Test() {}
	Test(const Test& t) { cout << "Copy" << endl; }
	Test(Test&& t)      { cout << "Move" << endl; }

	Test& operator=(const Test& t) 
	{
		cout << "Copy=" << endl; 
		return *this; 
	} 
	
	Test& operator=(Test&& t) 
	{
		cout << "Move=" << endl; 
		return *this; 
	} 
};




template<typename T> void Swap(T& x, T& y)
{
//	Test temp = x; // 복사 생성자
//	x = y;		   // 복사 대입
//	y = temp;

	Test temp = move(x); // static_cast<Test&&>
	x = move(y);
	y = move(temp);
}

int main()
{
	Test t1, t2;
	//Swap(t1, t2);
	swap(t1, t2);

}











