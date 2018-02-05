#include <iostream>
using namespace std;

int main()
{
	int v1 = 0, v2 = 0;

	// capture by value, capture by copy
	//auto f1 = [v1, v2]() mutable { v1 = 10; v2 = 20; };

	// capture by reference
	auto f1 = [&v1, &v2]() { v1 = 10; v2 = 20; };


	f1(); 

	cout << v1 << endl; // 10
	cout << v2 << endl; // 20

}