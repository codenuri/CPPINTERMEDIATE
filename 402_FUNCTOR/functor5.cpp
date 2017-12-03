/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <algorithm>
using namespace std;

// 일반 함수
inline bool cmp1(int a, int b) { return a > b; }
inline bool cmp2(int a, int b) { return a < b; }

// functor
struct Less    { inline bool operator()(int a, int b) const { return a < b; }};
struct Greater { inline bool operator()(int a, int b) const { return a > b; }};

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	// STL sort : 모든 인자가 템플릿으로 되어 있다
	// 1. 비교정책으로 일반함수를 전달할때.
	// 장점 : 정책을 교체해도 sort()기계어는 한개이다. - 코드 메모리 절약
	// 단점 : 정책 함수가 인라인 치환될수 없다.
	sort(x, x + 10, cmp1); // sort( int*, int*, bool(*)(int, int)) 인 함수 생성.
	sort(x, x + 10, cmp2); // sort( int*, int*, bool(*)(int, int)) 인 함수 생성.

	// 2. 비교정책으로 함수객체 전달할때.
	// 장점 : 정책함수가 인라인 치환될수 있다 - 빠르다.!
	// 단점 : 정책을 교체한 횟수 만큼의 sort()기계어 생성.
	Less    f1;
	Greater f2;
	sort(x, x + 10, f1); // sort( int*, int*, Less) 인 함수 생성.
	sort(x, x + 10, f2); // sort( int*, int*, Greater) 인 함수 생성.
}