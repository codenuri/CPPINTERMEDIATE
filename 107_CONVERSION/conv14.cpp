/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

// 아래 소스에 대한 설명은 https://youtu.be/ncV44oB2GSA  에서 보실수 있습니다.
class istream
{
public:
	bool fail() { return false; }

	// C++11 변환 연산자 앞에도 explicit를 붙일수 있다.
	// 암시적 변환은 error. 명시적 허용
	// if 문안에 객체를 넣을수도 있다.
	explicit operator bool() { return fail() ? false : true; }
};
istream cin;

int main()
{
	int n = 0;

	//bool b = cin; //error
	bool b = static_cast<bool > (cin); // ok

	//cin << n; // error

	if ( cin ) {}  // ok
	if ( cin == false ) {}// error
}
