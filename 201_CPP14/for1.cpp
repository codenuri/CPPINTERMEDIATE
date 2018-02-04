#include <iostream>
#include <list>
using namespace std;

int main()
{
	//int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// foreach()
	for ( auto& n : s ) // 배열, STL 컨테이너..
		cout << n << endl;

//	for (int i = 0; i < 10; i++)
//		cout << x[i] << endl;
}


