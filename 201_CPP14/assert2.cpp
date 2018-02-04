#include <iostream>
#include <mutex>
using namespace std;

#pragma pack(1)
struct PACKET
{
	char cmd;
	int  data;
};
static_assert(
	sizeof(PACKET) == sizeof(char) + sizeof(int),
	"error, unexpected padding !");


template<typename T> void Swap(T& a, T& b)
{
	// T가 가져야하는 조건을 조사
	static_assert(is_copy_constructible<T>::value,
		"error. T is not copyable");

	T tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	mutex m1;
	mutex m2;
	Swap(m1, m2);
}