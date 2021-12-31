#include "QueueS.h"

template<class T>
QueueS<T>::QueueS()
{
	s1 = new MyStack<T>;
}

template<class T>
QueueS<T>::QueueS(int s)
{
	s1 = new MyStack<T>(s);
}

template<class T>
QueueS<T>::QueueS(const QueueS& obj)
{
	s1 = new MyStack<T>(*(obj.s1));	//copy constructor of stack class will call here
}

template<class T>
void QueueS<T>::operator=(QueueS& obj)
{
	*s1 = *(obj.s1);				//assignmnt operator of stack class shpuld call here
}

template<class T>
void QueueS<T>::enQueue(T value)
{
	//enterin rverse order
	if(isEmpty())
	{
	s1->push(value);			//at start
	}
	else
	{
		MyStack<T> s2;
		while (!s1->isEmpty())
		{
			int v = s1->pop();
			s2.push(v);
		}
		s1->push(value);
		while (!s2.isEmpty())
		{
			int v = s2.pop();
			s1->push(v);
		}
	}
	
}

template<class T>
T QueueS<T>::deQueue()
{
	return s1->pop();
}

template<class T>
T QueueS<T>::Front()
{
	return s1->Top();
}

template<class T>
T QueueS<T>::Back()
{
	return s1->stack[0];
}

template<class T>
bool QueueS<T>::isFull()
{
	return s1->isFull();
}

template<class T>
bool QueueS<T>::isEmpty()
{
	return s1->isEmpty();
}

template<class T>
int QueueS<T>::getSize()
{
	return s1->getSize();
}

template<class T>
void QueueS<T>::showStructure()
{
	if (!isEmpty())
	{
		s1->print();
	}
	else
		cout << "queue is empty\n";
}

template<class T>
QueueS<T>::~QueueS()
{
	delete s1;
}