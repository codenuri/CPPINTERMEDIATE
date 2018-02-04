#include <iostream>
using namespace std;

class second
{
	int value;
public:
	second(long long s) : value(s) {}
};

class minute
{
	int value;
public:
	minute(long long s) : value(s) {}
};

second operator""_s(unsigned long long v)
{
	return v;
}

minute operator""_m(unsigned long long v)
{
	return v;
}

int main()
{
	second n1 = 10_s; 
	minute n2 = 10_m;
}


