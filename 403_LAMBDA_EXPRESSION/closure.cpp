/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

// ClosureType.h
// [](int a, int b) { return a < b; }

class ClosureType
{
public:
	bool operator()(int a, int b) const
	{
		return a < b;
	}
	~ClosureType() = default;
	ClosureType(const ClosureType&) = default;
	ClosureType(ClosureType&&) = default;
	ClosureType& operator=(const ClosureType&) = delete;

	// convert to function pointer
	operator bool(*)(int, int)()  { return &static_method; }

	static bool static_method(int a, int b) 
	{
		return a < b;
	}
};

sort(x, x + 10, ClosureType() );