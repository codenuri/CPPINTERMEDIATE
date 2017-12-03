/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor3.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

class Animal
{
protected:
	Animal() {}
};

class Dog : public Animal
{
public:
	Dog() : Animal() {}
};

int main()
{
	// 다음중 에러를 모두 골라 보세요.
	Animal a; // error.
	Dog    d; // ok..
}