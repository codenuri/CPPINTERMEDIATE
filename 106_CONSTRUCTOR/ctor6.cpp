/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Intermediate
* MODULE     : ctor6.cpp
* Copyright (C) 2018 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

struct stream_buf
{
	stream_buf(size_t sz) 
	{ 
		cout << "stream_buf" << endl; 
	}
};
struct stream
{
	stream(stream_buf& buf) 
	{
		cout << "stream : using stream_buf" << endl; 
	}
};

// 버퍼를 가지고 있는 stream
struct mystream : public stream
{
	stream_buf buf;
public:
	mystream(int sz) : buf(sz), stream(buf) {}
};


int main()
{
//	stream_buf buf(1024);
//	stream st(buf);

	mystream mst(1024);
}