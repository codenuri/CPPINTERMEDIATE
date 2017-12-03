/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

// inline2.cpp
// 1. 인라인 함수 문법은 컴파일 시간 동작한다.
// 2. 인라인 함수라도 함수포인터에 담아서 사용하면 호출된다.

	   int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2); // 호출
	int n2 = Add2(1, 2); // 치환
	
	int(*f)(int, int);

	f = &Add2;
	//if (사용자입력이 1 이면)
	//	f = &Add1;

	int n3 = f(1, 2); // 호출 ? 치환 ?
}

