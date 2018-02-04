#include <iostream>
using namespace std;

// _ : 사용자 사용가능.
// _로 시작하지 않은것 : reserved

int operator""_k(unsigned long long v)
{
	return v * 1000;
}

int main()
{
	int n1 = 10_k; // operator""k(10)

	cout << n1 << endl; // 10000
}


