/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

class istream
{
public:
	bool fail() { return false; }

	// C++11 변환 연산자 앞에도 explicit를 붙일수 있다.
	// 암시적 변환은 error. 명시적 허용
	// 단, if 문안에서는 암시적으로 bool로 변환 허용.
	explicit operator bool() { return fail() ? false : true; }
};
istream cin;

int main()
{
	int n = 0;

	//bool b = cin; //error
	bool b = static_cast<bool > (cin); // ok

	//cin << n; // error

	if ( cin ) {}
}
