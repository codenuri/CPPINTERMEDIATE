/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : conv3.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;
// RAII : Resource Acquision Is Initialization
class OFile
{
	FILE* file;
public:
	OFile(const char* filename, const char* mode = "wt")
	{
		file = fopen(filename, mode);
	}
	~OFile() {	fclose(file);	}

	operator FILE*() { return file; }
};
int main()
{
	OFile f("a.txt");

	// C 함수를 사용해서 화일 작업
	fputs("hello", f);
	fprintf(f, "n = %d", 10);	// OFile => FILE* 로 암시적 변환되면 가능.
							// f.operator FILE*()
	
	String s1 = "hello";
	char s2[10];

	strcpy(s2, s1); // String => const char* 암시적 변환..
}









/*
int main()
{
	FILE* f = fopen("a.txt", "wt");

	fputs("hello", f);

	if (....)
		return false;

	//fclose(f);
}
*/















