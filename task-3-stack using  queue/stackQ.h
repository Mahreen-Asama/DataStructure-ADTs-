#pragma once
#include"Queue.h"

template<class t1>
class stackQ
{
	Queue<t1> q1;			//to make aggregation relationship with queue ADT
public:
	stackQ();
	stackQ(int);
	void push(t1);
	t1 pop();
	t1 top();
	void print();
	bool isfull();
	bool isempty();
	int sizee();
	~stackQ();
};


