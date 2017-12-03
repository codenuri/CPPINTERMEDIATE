/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

inline bool cmp1(int a, int b) { return a > b; }
inline bool cmp2(int a, int b) { return a < b; }
struct Less		{ inline bool operator()(int a, int b) const { return a < b; } };
struct Greater	{ inline bool operator()(int a, int b) const { return a > b; } };

template<typename T> void foo(T f)
{
	bool b = f(1, 2);
}
int main()
{
	foo(cmp1);
	foo(cmp2);
	foo(Less());
	foo(Greater());
}
// 문제 1. 컴파일 했을때 foo 함수는 몇개 생성될까요 ?
// 문제 2. 각각의 foo 함수에서 f(1,2) 의 인라인 치환 여부는 ?
// 문제 3. 컴파일했을때 foo를 제외한 함수의 갯수는 ?


