/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : conv6.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <string>
#include <memory>
using namespace std;

class String16
{
public:
	explicit                    String16(const char16_t* o);
};

void foo(String16 s)  // String16 s = "hello"
{}

int main()
{
	foo("hello"); // error
	foo(String16("hello")); // ok..


	String16 s = "hello"; // error

	// STL 의 string 클래스는 생성자가 explicit 가 아님.
	string s1("hello");		// ok
	string s2 = "hello";	// ok


	shared_ptr<int> p1 = new int;	// error  생성자가 explicit
	shared_ptr<int> p2(new int);	// ok..
}