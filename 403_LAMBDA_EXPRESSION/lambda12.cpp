#include <iostream>
#include <memory>
#include <string>
#include <tuple>
using namespace std;

int main()
{
	int v1 = 0, v2 = 0, v3 = 0;

	// capture by copy, capture by reference
	auto f1 = [v1]() {};
	auto f2 = [&v1]() {};
	auto f3 = [v1, &v2]() {};


	
	// default capture
	auto f4 = [=]() {};	// capture by copy
	auto f5 = [&]() {}; // capture by reference
	auto f6 = [=, &v1]() {};
	auto f7 = [&, v1]() {};
	//auto f8 = [=, v1]() {}; // error



	auto f9  = [x = v1, v2 = v2, v3]() {};
	auto f10 = [v1, y = v2, &r = v3]() {};

	

	string s = "hello";
	auto f11 = [s1 = move(s)] ()  { };

	f11();
	cout << s << endl; // empty string


	unique_ptr<int> p(new int);
	auto f12 = [p = move(p)]() {};
}



void foo(int a, int b)
{
	//int a, b;
	auto f = [a, b]() { return a + b; }// ok
	auto f = [=]() { return a + b; } // ok
}



template<typename ... Types> void goo(Types ... args)
{
	int x = 0;
	auto f = [=]() { auto t = make_tuple(args...); };
	auto f = [args...]() { auto t = make_tuple(args...); };
}


