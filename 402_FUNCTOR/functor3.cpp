/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <algorithm>	
#include <iostream>
using namespace std;

// 변하지 않은 전체 흐름속에서.. 변경되어야 하는 부분을 분리한다.
// qsort() 함수와 유사한 방법

// 일반함수는 자신만의 타입이 없다.
// signature가 동일하면 모두 같은 타입이다.
void Sort(int* x, int n, bool(*cmp)(int, int))
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			//	if (x[i] > x[j])

			if (cmp(x[i], x[j]))
				swap(x[i], x[j]);
		}
	}
}

inline bool cmp1(int a, int b) { return a > b; }
inline bool cmp2(int a, int b) { return a < b; }

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };
	Sort(x, 10, cmp2);
}
