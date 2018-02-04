class Base
{
public:
	virtual void f1(int) {}
	virtual void f2() const {}
	virtual void f3() {}
			void f4() {}
};
class Derived : public Base
{
public:
	virtual void f1(int) override {}
	virtual void f2() const override {}
	virtual void f3() override {}
	//void f4() override {}
};

int main()
{

}