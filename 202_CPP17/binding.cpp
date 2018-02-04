#include <iostream>
#include <tuple>
using namespace std;

struct Point
{
	int x;
	int y;
};
int main()
{
	Point pt = { 1,2 };
	//int a = pt.x;
	//int b = pt.y;

	auto  [a,  b] = pt;
	auto& [rx, ry] = pt;


	int x[2] = { 1,2 };
	auto[e1, e2] = x;


	pair<int, double> p(1, 3.4);
	auto[n, d] = p;

	tuple<int, short, double> t3(1, 2, 3.4);
	auto[a1, a2, a3] = t3;
}