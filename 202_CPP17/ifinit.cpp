#include <iostream>
using namespace std;

int foo()
{
	return 0;
}

int main()
{
	// 예전 스타일.
	int ret = foo();

	if (ret == 0)
	{
	}

	// C++17 스타일
	// if ( init 구문; 조건문 )
	if (int ret = foo(); ret == 0)
	{
		cout << "ret is 0" << endl;
	}

	// switch 문에도 초기화 구문을 추가할수 있습니다.
	switch (int n = foo(); n)
	{
	case 0: break;
	case 1: break;
	}
}











