/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

// inline1.cpp

	   int Add1(int a, int b) { return a + b; }
inline int Add2(int a, int b) { return a + b; }

int main()
{
	int n1 = Add1(1, 2); // 호출
	int n2 = Add2(1, 2); // 치환
						 // 장점 : 속도가 빠르다
						 // 단점 : 목적코드가 커진다.

	// g++ inline1.cpp -S        => inline1.s
	// cl  inline1.cpp /FAs /Ob1 => inline1.asm
}

