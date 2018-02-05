#include <iostream>
using namespace std;

// Concept Ts
//void foo(auto n) {}

int main()
{
	// generic lambda : C++14
	auto f1 = [](auto a, auto b)  { return a + b; };

	cout << f1(1, 2.1) << endl; // 3.1


	// nullary lambda
	auto f2 = [] {return 10; }; 


	// C++17 : () 함수를 constexpr 함수로..
	auto f3 = [](int a, int b) constexpr
	{
		return a + b; 
	};

	int y[f3(1, 2)];

	
}

