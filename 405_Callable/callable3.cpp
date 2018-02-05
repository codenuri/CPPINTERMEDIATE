#include <iostream>
#include <functional>
using namespace std;

template<typename F, typename ... Types>
decltype(auto) chronometry(F&& f, Types&& ... args)
{
//	std::forward<F>(f)(std::forward<Types>(args)...);

	//f(std::forward<Types>(args)...);

	return  invoke(std::forward<F>(f),
	   	std::forward<Types>(args)...);

}

class Dialog
{
public:
	void Close() {} 
};

int main()
{
	Dialog dlg;
	chronometry(&Dialog::Close, &dlg);
	
//	void (Dialog::*f)() = &Dialog::Close;

//	(dlg.*f)();
//	f(&dlg);
//	invoke(f, &dlg);
}