/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/


// T&& : lvalue 와 rvalue를 모두 전달 가능.
//	    lvalue 전달하면 T는 lvalue reference 로 결정
//      rvalue 전달하면 T는 값 타입으로 결정..

template<typename T> void f4(T&& a) {}

int main()
{
	int n = 10;

	// 사용자가 T의 타입을 명시적으로 전달할때
	f4<int>(10 );	// f4(int&& a)   => rvalue 를 전달
	f4<int&>(n );	// f4(int& && a) => f4(int& a) => lvalue 를 전달
	f4<int&&>(10 ); // f4(int&& && a)=> f4(int&& a) => rvalue 전달 

	// T의 타입을 명시적으로 전달하지 않을때
	f4(n);	// ok. 컴파일러가 T를 int& 로 결정.
	f4(10);	// ok. 컴파일러가 T를 int  로 결정. f4(T&& ) => f4(int && ) 
}

