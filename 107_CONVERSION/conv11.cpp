/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

/*
template<typename T> T* memAlloc(int sz)
{
	return (T*)malloc(sz);
}
*/

class memAlloc
{
	int size;
public:
	inline memAlloc(int sz) : size(sz) {}

	template<typename T> operator T*()
	{
		return (T*)malloc(size);
	}
};

int main()
{
	double* p1 = memAlloc(40); // 클래스이름() : 임시객체..
							   // 임시객체.operator double*()
	int*    p2 = memAlloc(40);

}




