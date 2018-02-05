#include <iostream>
using namespace std;

template<typename ... Types> class mi : public Types... // public lambda1, public lambda2
{
public:
	mi(Types&& ... args) : Types(args)... {} 

	// 기반 클래스의 특정함수를 사용할수 있게..
	using Types::operator()...;
};

int main()
{
	mi f([](int a, int b)        { return a + b; },			// class lambda1{}; lambda1();
	 	 [](int a, int b, int c) { return a + b + c; });    // class lambda2{}; lambda2();

	cout << f(1, 2) << endl; // 3
	cout << f(1, 2, 3) << endl; // 6
}