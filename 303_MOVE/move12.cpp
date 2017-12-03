/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include "Test.h"
using namespace std;

// lvalue를 전달하면 T : lvalue 참조.. => const Test&
template<typename T>
typename remove_reference<T>::type &&
xmove(T&& obj)  
{
	// const Test&&    => Test(Test&&)       : error
	//                 => Test(const Test& ) : 

	return static_cast<const Test&&>(obj);
	return static_cast<typename remove_reference<T>::type &&>(obj);
}


int main()
{
	const Test t1;
	Test t2 = xmove(t1); // move ? copy ? error
						// const Test

	//Test t2 = static_cast<Test&&>(t1); // error
}
