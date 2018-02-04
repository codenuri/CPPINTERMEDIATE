#include <iostream>
#include <type_traits>
using namespace std;

struct Point
{
	int x, y;

	Point() {} // 사용자가 생성자 제공.

	//Point() = default; // 컴파일러가 제공.

//	Point(const Point& ) = default;
//	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	Point p1{};  

	cout << p1.x << endl; // default 생성자 - 0
						  // 사용자가 제공 - garbage




	cout << is_trivially_constructible<Point>::value
		 << endl;
}
