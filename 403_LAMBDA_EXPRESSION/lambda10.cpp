#include <iostream>
using namespace std;

int main()
{
	int v1 = 0, v2 = 0;

	//auto f1 = [v1, v2]() { v1 = 10; v2 = 20;};// error 
	
	// mutable lambda : () 연산자 함수를 비상수 함수로
	auto f1 = [v1, v2]() mutable { v1 = 10; v2 = 20; };

	f1(); // 람다 표현식 실행..

	cout << v1 << endl; // 0
	cout << v2 << endl; // 0

}