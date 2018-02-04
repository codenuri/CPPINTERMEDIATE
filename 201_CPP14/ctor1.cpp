#include <iostream>
using namespace std;

struct Point
{
	int x, y;
	
	//Point()				: x(0), y(0) {}

	Point() : Point(0,0)
	{
		// 다른 생성자를 호출할수 없을까 ?
		//Point(0, 0);	// 임시객체를 생성하는 표현.

		//new(this) Point(0, 0);

	}
	Point(int a, int b) : x(a), y(b) {}
	//void init() {}
};

int main()
{
	Point p;

	cout << p.x << endl;
	cout << p.y << endl;
}