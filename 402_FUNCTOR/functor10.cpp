/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <bitset>
using namespace std;


// 일반함수 : 동작만 있고 상태가 없다.
// 함수객체(fuctor) : 동작과 상태가 있다.
class Random
{
	bitset<10> bs;
public:
	Random() {	bs.reset(); // 모든 비트를 0으로
	}
	int operator()()
	{
		int v = -1;
		do
		{
			v = rand() % 10;
		} while (bs.test(v));

		bs.set(v);
		return v;
	}
};


int main()
{
	Random random;
	Random random1;
	for (int i = 0; i < 10; i++)
		cout << random() << " ";
	random();
}
