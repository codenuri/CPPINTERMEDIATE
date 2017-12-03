#include <iostream>
#include <experimental/propagate_const>
using namespace std;
using namespace std::experimental;

struct A
{
	void foo()       { cout << "foo()" << endl; }		
	void foo() const { cout << "foo() const" << endl; } 
};
struct B
{
	/*
	A a;
	void goo()       { a.foo(); }
	void goo() const { a.foo(); }
	*/
	//A* p;
	propagate_const<A> p;
	B() { p = new A; }
	void goo()		 { p->foo(); }
	void goo() const { p->foo(); }

};

int main()
{
	B b1; 
	b1.goo();
	const B b2;
	b2.goo();
}