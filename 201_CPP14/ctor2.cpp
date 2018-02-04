class Base
{
public:
	void foo(int a) {}
};

class Derived : public Base
{
public:
	using Base::foo;

	void foo() { }
};

int main()
{
	Derived d;
	d.foo(10); // error
	d.foo();
}