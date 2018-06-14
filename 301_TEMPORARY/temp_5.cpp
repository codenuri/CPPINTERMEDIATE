#include <iostream>
using namespace std;

class Test
{
public:
	int data;

	void foo() &  { cout << "foo &" << endl; } // lvalue 객체에 대해서만 호출.
	void foo() && { cout << "foo &&" << endl; } 

	int& goo() & { return data; }
};

int main()
{
	Test t;
	t.foo();
	int& ret = t.goo();

	int& ret2 = Test().goo(); // error

	Test().foo();

}