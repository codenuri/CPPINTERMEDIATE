#include <iostream>
#include <type_traits>
using namespace std;

template<typename T> void copy_type(T* dst, T* arc, int sz)
{
	if (is_trivially_copyable<T>::value)
	{
		cout << "복사 생성자가 trivial" << endl;
		memcpy(dst, src, sizeof(T)*sz);
	}
	else
	{
		cout << "복사 생성자가 trivial 하지 않은 경우" << endl;
		while (sz--)
		{
			new(dst) T(*src);
			++dst, ++src;
		}
	}
}