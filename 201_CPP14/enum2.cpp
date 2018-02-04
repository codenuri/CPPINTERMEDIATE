#include <iostream>
#include <type_traits>
using namespace std;

// C++98/03
//enum Color { red = 1, green = 2 };

// C++11
enum class Color : char { red = 1, green = 2 };

int main()
{
//	int n1 = Color::red; // error

	Color n1 = Color::red; // ok
	int   n2 = static_cast<int>(Color::red); // ok

	int n3 = red; // error

//	int red = 0;
//	int n3 = red;

	cout << typeid(underlying_type_t<Color>).name()
		<< endl;

}
