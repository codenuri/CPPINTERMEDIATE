/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : const6.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

struct Cache
{
	char cache[16];
	bool cache_valid = false;
};

class Point
{
	int x, y;
	Cache* pCache;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) 
	{
		pCache = new Cache;
	}

	const char* toString() const
	{
		if (pCache->cache_valid == false)
		{
			sprintf(pCache->cache, "%d, %d", x, y);
			pCache->cache_valid = true;
		}
		return pCache->cache;
	}
	~Point() { delete pCache; }
};

int main()
{
	Point p1(1, 1);

	cout << p1.toString() << endl;
	cout << p1.toString() << endl;

}
