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
	int*   buf;
	string tag;
	Test   test;
public:
	Buffer(size_t s, string t) 
		: sz(s), tag(t), buf(new int[s] ) {}

	~Buffer() { delete[] buf; }

	// 깊은 복사
	Buffer(const Buffer& b) : sz(b.sz), tag(b.tag), test(b.test)
	{
		buf = new int[sz];
		memcpy(buf, b.buf, sizeof(int)*sz);
	}

	// move 생성자 : 모든 멤버를 move 로 옮기도록 작성한다.
	Buffer(Buffer&& b) noexcept
		: sz(move(b.sz)), tag(move(b.tag)), test(move(b.test))
	{
		buf = move(b.buf);
		b.buf = 0; // 자원 포기.
	}
	
	// 대입연산자.
	// move 대입연산자.
};

int main()
{
	Buffer b1(1024, "SHARED");
	//Buffer b2 = b1; // copy

	Buffer b2 = move(b1); // copy
}