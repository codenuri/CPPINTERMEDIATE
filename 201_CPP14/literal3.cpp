#include <iostream>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;
//using namespace std::literals::string_literals;
//using namespace std::literals::chrono_literals;
using namespace std::literals;

void foo(string s)      { cout << "string" << endl; }
void foo(const char* s) { cout << "char*" << endl; }

int main()
{
	foo("hello"); // char*
	foo("hello"s); // string operator""s("hello")

	seconds s1 = 10s;
	minutes m1 = 10min;

	//minutes m2 = 120s; // 캐스팅 필요..
	seconds s2 = 10min;
	cout << s2.count() << endl; // 600
}

