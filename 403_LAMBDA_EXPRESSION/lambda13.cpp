#include <iostream>
using namespace std;

class Test
{
	int data = 0;
public:
	void foo() // Test* const this
	{
		int v = 0;

		//auto f = [this]() { this->data = 10; };
		//auto f = [this]() { data = 10; };

		// 멤버 데이타를 복사본으로 캡쳐 - C++17
		auto f = [*this]() mutable { data = 10; };
		f();
		cout << data << endl; // 10
	}
};

int main()
{
	Test t;
	t.foo();
}