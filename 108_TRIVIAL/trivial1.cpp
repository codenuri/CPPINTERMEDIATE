#include <iostream>
#include <type_traits>
using namespace std;

class A
{
public:
	virtual void foo() {}
};

int main()
{
	cout << is_trivially_constructible<A>::value << endl;
}

