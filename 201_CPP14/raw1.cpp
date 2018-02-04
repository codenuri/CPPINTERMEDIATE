#include <iostream>
using namespace std;

int main()
{
//	const char* s1 = "C:\\aa\\bb\\cc";

//	const char* s1 = R"(C:\aa\bb\cc)";

//	const char* s1 = R"(C:\aa\b"b\cc)";


	const char* s1 = R"*AAA**(C:\aa\b)"b\cc)*AAA**";

	cout << s1 << endl;
}