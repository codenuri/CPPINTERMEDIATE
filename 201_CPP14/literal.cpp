#include <iostream>
using namespace std;

int operator""_k(unsigned long long v)
{
	return 1000 * v;
}

int main()
{
	int n1 = 10; // meter
	int n2 = 10_k;// 10000  operator""k(10)

	cout << n2 << endl; /// 10000
}