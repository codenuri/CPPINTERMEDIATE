#include <iostream>
#include <string>
using namespace std;

class Base
{
	string name;
public:
	Base(string s) : name(s) {}
};

class Derived : public Base
{
public:
	using Base::Base;

	//Derived(string s) : Base(s) {}
};

int main()
{
	Derived d("aa");
}
