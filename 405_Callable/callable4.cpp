#include <iostream>
#include <functional>
using namespace std;

void foo(int a, int b) {}

class Dialog
{
public:
	int color;

	void setColor(int c) { color = c; }
};

int main()
{
	invoke(&foo, 10, 20); // foo(10,20)
	Dialog dlg;
	invoke(&Dialog::setColor, &dlg, 2); 
						// dlg.setColor(2);

	// 멤버 변수 포인터
	invoke(&Dialog::color, &dlg) = 20;
			// dlg.color = 20

	cout << dlg.color << endl; // 20

}

