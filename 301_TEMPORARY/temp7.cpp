int x = 0;

int  foo() { return x; }
int& goo() { return x; }

int main()
{
	foo() = 10; // error
	goo() = 10; // ok
}