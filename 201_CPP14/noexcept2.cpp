#include <iostream>
using namespace std;

void algo1()
{
	// 빠르지만 예외 가능성이 있다.
}

void algo2() noexcept  // 지정자
{
	// 느리지만 예외가 나오지 않는다.
}

class Test
{
public:
	Test() noexcept {}
};

int main()
{
	bool b1 = noexcept(algo1()); // 0. 연산자
	bool b2 = noexcept(algo2()); // 1

	cout << b1 << ", " << b2 << endl;

	bool b3 = is_nothrow_constructible<Test>::value;
	cout << b3 << endl;

}




