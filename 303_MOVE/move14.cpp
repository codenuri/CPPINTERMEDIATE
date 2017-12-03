/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <string>
#include "Test.h"
using namespace std;

class Buffer
{
	size_t sz;
//	int*   buf;
	string tag;
	Test   test;
public:
	Buffer(size_t s, string t)
		: sz(s), tag(t) {}
	
	// 사용자가 만들지 않으면 컴파일러가 아래 모양제공.
	// 얕은복사..
	Buffer(const Buffer& b) : sz(b.sz), tag(b.tag), test(b.test)
	{
	}
	
	/*
	// move 생성자 : 모든 멤버를 move 로 옮기도록 작성한다.
	Buffer(Buffer&& b) noexcept
		: sz(move(b.sz)), tag(move(b.tag)), test(move(b.test))
	{
	}
	*/
	// 대입연산자.
	// move 대입연산자.
};

int main()
{
	Buffer b1(1024, "SHARED");
	Buffer b2 = b1; // copy
	Buffer b3 = move(b1); // move
}