#include <iostream>
#include <list>
using namespace std;


struct Point3D
{
	int x = 1;
	int y = 2;
	int z = 3;

};
int* begin(Point3D& p3) { return &(p3.x); }
int* end(Point3D& p3) { return &(p3.z)+1; }



int main()
{
	Point3D p3;

	for (auto& n : p3)  // begin(p3)
		cout << n << endl;
}



/*
int main()
{
	list<int> s = { 1,2,3,4,5,6,7,8,9,10 };


//	for (auto& n : s) 
//		cout << n << endl;

	for ( auto p = begin(s); p != end(s); ++p )
	{
		auto& n = *p;

		cout << n << endl;
	}

}

*/
