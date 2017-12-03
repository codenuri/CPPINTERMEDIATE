/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include "Test.h"		
using namespace std;

// T&  : lvalue 만 받을수 있다.
// T&& : lvalue 와 rvalue를 모두 받을수 있다. 
// 인자로 lvalue 전달 : T => Test&  T&& : Test& && => Test&
//        rvalue 전달 : T => Test   T&& : Test &&  => Test&&
template<typename T> 
typename remove_reference<T>::type &&
xmove(T&& obj)
{
	// 목표 : rvalue로 캐스팅.
	//return static_cast<T&&>(obj);

	return static_cast<typename remove_reference<T>::type &&>(obj);
}

int main()
{
	Test t1;
	Test t2 = t1;		 // copy
	Test t3 = xmove(t1); // move
	Test t4 = xmove( Test() ); // move
}





















