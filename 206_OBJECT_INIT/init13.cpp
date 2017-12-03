/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <vector>
using namespace std;

/*
template<typename T, typename Ax = allocator<T>> class vector
{
	T* buff;
public:
	vector(size_t sz, T v = T() ) {} // 1
	vector(initializer_list<T> s) {} // 2
};
*/

int main()
{
	vector<int> v = { 1,2,3,4,5 }; // ok. 편리해 졌다

	vector<int> v1(10, 3);  // 1번. 10개를 3으로 초기화
	vector<int> v2{ 10,3 }; // 2번, 2개의 요소를 10, 3으로 초기화

	cout << v1.size() << endl; // 10
	cout << v2.size() << endl; // 2
}