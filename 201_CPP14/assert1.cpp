#include <iostream>
#include <cassert>
using namespace std;

void foo(int age)
{
	assert(age > 0);
	static_assert(age > 0, "error");
	// ......
}

int main()
{
//	static_assert(sizeof(void*) >= 8,"error. 32bit");
//	static_assert(sizeof(void*) >= 16); // C++17

	foo(-10);
}
