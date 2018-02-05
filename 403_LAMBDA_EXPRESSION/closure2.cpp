
class ClosureType
{
	int v;
public:
	ClosureType(int a) : v(a) {}
	int operator()(int a, int b) const
	{
		return a + b + v;
	}
	static int method(int a, int b) 
	{
		return a + b + v; // ??
	}

	typedef int(*F)(int, int);

	operator F() 
	{
		//return &ClosureType::operator();
		return &ClosureType::method;
	}
};

