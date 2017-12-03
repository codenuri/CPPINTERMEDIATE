/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/


void f1(int&  a) {} 
void f2(int&& a) {} 
template<typename T> void f3(T&  a) {} 
template<typename T> void f4(T&& a) {}

// int&  : int 형의 lvalue 전달 가능.
// int&& : int 형의 rvalue 전달 가능.
// T&    : 모든 타입의 lvalue 전달 가능.(함수 생성)

// T&&   : 모든 타입의 lvalue 와 rvalue 모두 전달 가능.(함수 생성)
//		   "universal reference"  => "forwarding reference"
//			lvalue 를 전달하면 foo(n)  => T : int&    T&& : int& && => int&
//          rvalue 를 전달하면 foo(10) => T : int     T&& : int&&    





