#include <iostream>
using namespace std;

int main()
{
	auto f1 = [](int a, int b) { return a + b; };

	decltype(f1) f2; // error

	decltype(f1) f3 = f1; // ok.

	decltype(f1) f4 = move(f1); // ok

	
}