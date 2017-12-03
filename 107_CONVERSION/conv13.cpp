/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

void true_function() {}

class istream   // basic_istream
{
public:
	bool fail() { return false; }

	// 방법 1. bool 로 변환 - 단점. shift  연산이 허용된다.
	//operator bool() { return fail() ? false : true; }

	// 방법 2. void* 로의 변환 - C++ 98/03
	// operator void*() { return fail() ? 0 : this; }

	// 방법 3. 함수 포인터로의 변환.
	//typedef void(*F)();
	//operator F() { return fail() ? 0 : &true_function; }

	// 방법 4. 멤버 함수 포인터로의 변환. - Safe BOOL
	//          if() 문에 넣을수 있는 side effect가 가장 적다..
	struct Dummy
	{
		void true_function() {}
	};
	typedef void(Dummy::*F)();
	operator F() { return fail() ? 0 : &Dummy::true_function; }

};
istream cin;

int main()
{
	int n = 0;
	if ( cin ) {}
//	cin << n;
//	delete cin;

//	void(*f)() = cin;
}
