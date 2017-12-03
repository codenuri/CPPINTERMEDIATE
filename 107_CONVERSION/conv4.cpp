/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : conv4.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class OFile
{
	FILE* file;
public:
	// explicit 생성자 : 인자가 한개인 생성자가 암시적 변환을
	//					허용하는 것을 막는다.

	explicit OFile(const char* filename, const char* mode = "wt")
	{
		file = fopen(filename, mode);
	}
	~OFile() { fclose(file); }

	operator FILE*() { return file; }
};

void foo(OFile f) {}

int main()
{
	OFile f("a.txt");
	foo(f); // ok..

	//foo("hello"); // const char* => OFile 로 암시적 변환 발생.
				  // 변환 생성자
	//foo(static_cast<OFile>("hello"));

}


















