/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : refCount.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

class RefCountBase
{
protected:
	mutable int mCount; 
	~RefCountBase() {  }
	RefCountBase() : mCount(0) {}
public:
	void addRef() const { ++mCount; }
};

template<typename T> class RefCount : public RefCountBase
{
public:
	void release()  const
	{
		if (--mCount == 0)
			delete static_cast<const T*>(this);
	}
};
class Truck : public RefCount<Truck> {};
class Bus   : public RefCount<Bus > {};

int main()
{
	const Truck* p = new Truck;
	p->addRef();
	p->release();
}
















