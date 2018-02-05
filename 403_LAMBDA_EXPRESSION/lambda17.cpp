#include <iostream>
#include <functional>
using namespace std;

template<typename F, typename ... Types> 
decltype(auto) chronometry(F f, Types&& ... args)
{
	return f(std::forward<Types>(args)...);
}

int main()
{
	

}

//A FunctionObject type is the type of an object that can be used on the left of the function call operator.