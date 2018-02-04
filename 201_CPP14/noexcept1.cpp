#include <iostream>
using namespace std;
/*
// c++98
int foo()  // 예외가 있을수도 있고, 없을수도 있다.
int foo() throw(int) // 예외가 있다는 의미.
int foo() throw()    // 예외가 없다는 의미.
{
	throw 1;
	return 0;
}
*/
// C++11
//void goo() noexcept(true) // 예외가 없다.
void goo() noexcept // 위와 동일.
{
	throw 1;
}

void goo() 
{
	throw 1;
}

int main()
{
	goo();

	try
	{
		goo();
	}
	catch (...)
	{
		cout << "exception..." << endl;
	}
}




