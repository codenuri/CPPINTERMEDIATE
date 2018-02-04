#include <iostream>
#include <set>
using namespace std;

int main()
{
	set<int> s;

	s.insert(10);
	//pair<set<int>::iterator, bool> ret = s.insert(10); // 실패
	/*
	auto ret = s.insert(10); // 실패

	if (ret.second == false)
	{
		cout << "실패" << endl;
	}
	*/
	/*
	auto [it, success] = s.insert(10); // 실패

	if ( success == false)
	{
		cout << "실패" << endl;
	}
	*/

	if ( auto[it, success] = s.insert(10); success == false)
	{
		cout << "실패" << endl;
	}

}