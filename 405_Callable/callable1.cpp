#include <iostream>
#include <functional>
using namespace std;

void foo()
{

}

int main()
{
	void(&r)() = foo;
	r();
	foo();

	less<int> f;
	f(1, 2);

	[](int a, int b) { return  a + b; }(1, 2);



	
}

