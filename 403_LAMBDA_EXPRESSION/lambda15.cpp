
int main()
{
	int(*f)(int, int) = [](int a, int b) 
	{
		return a + b; 
	};

	int v = 0;

	// capture 구문을 사용하면
	// 함수포인터로 암시적 변환 될수 없다.
	int(*f1)(int, int) = [v](int a, int b)
	{
		return a + b + v;
	};

}
