/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <type_traits>
using namespace std;

template<typename T> T&& xforward(T& arg)
{
	return static_cast<T&&>(arg);
}
/*
template<typename T> T&& xforward(typename remove_reference<T>::type && arg)
{
	return static_cast<T&&>(arg);
}
*/
struct Arg
{
	int i = 1;
	int  get() && { cout << "&&" << endl; return i; } // call to this overload is rvalue
	int& get() &  { cout << "&" << endl; return i; }  // call to this overload is lvalue
};
void foo(int&)  { cout << "foo int&" << endl;}
void foo(int&&) { cout << "foo int&&" << endl; }

template<class T>
void wrapper(T&& arg)
{
//	using Type = decltype(xforward<T>(arg).get());
//	foo(xforward<Type>( xforward<T>(arg).get()) );

	using Type = decltype(static_cast<T&&>(arg).get());
	foo(static_cast<Type&&>(static_cast<T&&>(arg).get()) );

}

int main()
{
	wrapper(Arg());

	Arg a;
	wrapper(a);
}