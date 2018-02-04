#include <iostream>
#include <list>
#include <vector>
#include <iterator>
using namespace std;

// 컨테이너의 모든 요소를 출력하는 함수.
template<typename T> void show(T& c)
{
//	auto p1 = c.begin();
//	auto p2 = c.end();

	auto p1 = begin(c);
	auto p2 = end(c);

	while (p1 != p2)
	{
		cout << *p1 << endl;
		++p1;
	}
}

int main()
{
	list<int> c = { 1,2,3 };
	//vector<int> c = { 1,2,3 };
	
	show(c);

	int x[3] = { 1,2, 3 };

	show(x);

}