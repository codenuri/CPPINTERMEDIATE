#include <iostream>
using namespace std;

struct Base
{
	int v = 10;
};

struct Derived : public Base
{
	int v = 20;
};

int main()
{
	Derived d;
	cout << d.v << endl; // 20
	cout << d.Base::v << endl; // 10

	// 값 캐스팅 : 임시객체 생성
	cout << (static_cast<Base>(d)).v << endl; // 10
	cout << (static_cast<Base&>(d)).v << endl; // 10

	(static_cast<Base>(d)).v = 30; // error
	(static_cast<Base&>(d)).v = 30; // ok
	
}