#include <iostream>
#include <type_traits>
using namespace std;

template<typename T> void printv(T v)
{
	if constexpr (is_pointer<T>::value)	
		cout << v << " : " << *v << endl;
	else
		cout << v << endl;
}

int main()
{
	int n = 10;
	printv(n);
	printv(&n);
}