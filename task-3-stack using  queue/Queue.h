#pragma once
#include<iostream>
using namespace std;

template<class T>
class Queue
{
	/*
	size->   no. of memory cells allocated for que
	*que->   pointer to point dynamic memory allocated for stack
	front->  pointer to hold index of highest priority element of queue
	back->   pointer to hold index of lowest priority element of queue
	count->  number of elements present in queue
	*/
protected:
	int size;
	T* que;
	int front;
	int back;				//back==rear
	int count;
	void resize(int);		//private function to resize queue
public:
	Queue();
	Queue(int);
	Queue(const Queue&);
	//void operator=(Queue);
	void enQueue(T);
	T deQueue();
	T Front();
	T Back();
	bool isFull();
	bool isEmpty();
	int getSize();
	void showStructure();	//display the queue status with its rear pointing to the correct location
	~Queue();
	//void print();
};

