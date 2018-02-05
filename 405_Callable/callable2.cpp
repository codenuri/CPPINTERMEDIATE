#include <iostream>
#include <functional>
using namespace std;


template<typename F, typename ... Types>
decltype(auto) chronometry(F&& f, Types&& ... args)
{
	std::forward<F>(f)(std::forward<Types>(args)...); 
}

int main()
{
	chronometry(less<int>(), 10, 20);
}