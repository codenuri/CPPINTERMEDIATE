/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : new9.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <Windows.h>
#include <iostream>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b)
	{
		cout << "Point(int, int)" << endl;
	}
};

int main()
{
	// IPC : 공유메모리를 사용한 프로세스간 통신, mmap()

	HANDLE hMap = CreateFileMappingA(INVALID_HANDLE_VALUE, 0, PAGE_READWRITE, 0, sizeof(Point), 0);
	
	Point* p = (Point*)MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);

	new(p) Point(0, 0);

}