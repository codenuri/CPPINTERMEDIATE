/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang@codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : hello.cpp
* BUILD      : g++ hello.cpp -std=c++1z    
*              cl  hello.cpp /std:c++latest
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
#include <thread>
#include <string>
#include <functional>
using namespace std::literals;

class stop_watch
{
	std::string message;
	std::chrono::high_resolution_clock::time_point start;
public:
	inline stop_watch(std::string msg = "") : message(msg) { start = std::chrono::high_resolution_clock::now(); }

	inline ~stop_watch()
	{
		std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
		std::cout << message << " " << time_span.count() << " seconds." << std::endl;;
	}
};

template<typename F, typename ... A> 
decltype(auto) chronometry(F&& f, A&& ... args)
{
	stop_watch sw;
	return std::invoke(std::forward<F>(f), std::forward<A>(args)...);
}

class Hello
{
	std::string msg;
public:
	Hello(std::string s) : msg(s) {}

	void Say() 
	{
		std::cout << msg << std::endl; 
		std::this_thread::sleep_for(3s);
		std::cout << "bye..." << std::endl;
	}
};

int main()
{
//	Hello h("hello");
//	h.Say();
	
	// 특정 함수의 실행시간을 측정하는 함수.
	chronometry(&Hello::Say, Hello("hello"s)); 
}


