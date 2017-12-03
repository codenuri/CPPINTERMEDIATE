/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <bitset>
using namespace std;

// 0 ~ 9 사이의 중복되지 않은 난수를 리턴하는 함수.

// 일반함수 : 동작만 있고 상태가 없다.
bitset<10> bs;
bitset<10> bs1;
void clear_random() { bs.reset(); }
int random()
{
	int v = -1;
	//static bitset<10> bs; // 10개가 0으로 초기화
	do
	{
		v = rand() % 10;
	} while (bs.test(v));

	bs.set(v);	
	return v;
}

int main()
{
	for ( int i = 0; i < 10; i++)
		cout << random() << " "; 
	random();
}
