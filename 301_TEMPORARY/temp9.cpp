// 후위형
int operator++(int& n, int )
{
	int temp = n;
	n = n + 1;
	return temp;
}
// 전위형
int& operator++(int& n)
{
	n = n + 1;
	return n;
}
int main()
{
	int n = 3;
	n++; // operator++(n, int)
	++n; // operator++(n)

	++(++n);

	n++ = 10; // error
	++n = 10; // ok
}