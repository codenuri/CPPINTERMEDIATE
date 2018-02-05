#include <iostream>
using namespace std;

int main()
{
	int v1 = 0, v2 = 0;

	// capture

	auto f0 = []()       { return 0; };
	auto f1 = [v1, v2]() { return v1 + v2; };

	cout << sizeof(f0) << endl; // 1
	cout << sizeof(f1) << endl; // 8

}