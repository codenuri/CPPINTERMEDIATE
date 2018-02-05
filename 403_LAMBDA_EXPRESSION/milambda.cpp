#include <iostream>
using namespace std;

int main()
{
	auto f = [](int a, int b) { return a + b; };

	f(1, 2);
	f(1, 2, 3);
	f(1, 2, 3, 4);
}

