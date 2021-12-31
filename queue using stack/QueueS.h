#pragma once
#include"MyStack.h"
#include<iostream>
using namespace std;

template<class T>
class QueueS
{
	MyStack<T>* s1;
public:
	QueueS();
	QueueS(int);
	QueueS(const QueueS&);
	void operator=(QueueS&);
	void enQueue(T);
	T deQueue();
	T Front();
	T Back();
	bool isFull();
	bool isEmpty();
	int getSize();
	void showStructure();	//display the queue status with its rear pointing to the correct location
	~QueueS();
	//void print();
};

