template<typename T> void goo(T a)
{
}

//void goo(double) = delete;

class Mutex
{
public:

	Mutex(const Mutex&) = delete;
	void operator=(const Mutex&) = delete;

//private:
//	Mutex(const Mutex&);
};

int main()
{
	goo(3.4);

	Mutex m1;
	Mutex m2 = m1; // 복사 생성자.
}