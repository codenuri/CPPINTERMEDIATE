
template<typename T> struct Point
{
	T x, y;
};

typedef Point Pixel; // ??? error

template<typename T> 
using Pixel = Point<T>;

//typedef int DWORD;
//typedef void(*FP)(int);

using DWORD = int;
using FP = void(*)(int);

int main()
{
	DWORD n; // int
	FP    p; // void(*p)(int)

	Point<int> p1;
	Pixel<int> p2; // Point<int> p2
}
