/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : this4.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

// this4.cpp - Thread 클래스 만들기
#include <iostream>
#include <windows.h>
using namespace std;


// 라이브러리 내부 클래스
class Thread
{
public:

	void run()
	{
		CreateThread(0, 0, threadMain,(void*)this, 0, 0);
	}

	// 1. 아래 함수는 반드시 static 함수 이어야 합니다.
	// 2. 아래 함수는 this가 없다. 그래서 함수 인자로
	//    this를 전달하는 기술.

	static DWORD __stdcall threadMain(void* p)
	{
		Thread* const self = static_cast<Thread*>(p);

		self->Main(); // Main( self )

		//Main(); // 가상함수 호출
				// this->Main() => Main( this) 로 변해야 한다.

		return 0;
	}

	virtual void Main() // void Main(Thread* const this)
	{}
};






// 라이브러리 사용자 코드
class MyThread : public Thread
{
public:
	virtual void Main() { cout << "스레드 작업" << endl; }
};









int main()
{
	MyThread t;
	t.run();	// 이순간 스레드가 생성되어서 
				// 가상함수 Main()을 실행해야 합니다.
	getchar();
}






