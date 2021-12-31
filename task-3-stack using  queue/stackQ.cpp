#include "stackQ.h"

template<class t1>
stackQ<t1>::stackQ()
{
	//q1 = new Queue<t1>;		//by-default 10 size stack will form
}

template<class t1>
stackQ<t1>::stackQ(int s)
{
	//q1 = new Queue<t1>(s);
}

template<class t1>
void stackQ<t1>::push(t1 valu)
{
	/*
	function implements stackQ behaviour(LIFO) using Queue as data-structure
	arguments: latest value to be pushed in stackQ
	retur: nothing
	*/
	if (!q1.isEmpty())			//if queue is not empty, then use that method to implement stackQ using queue
	{
		int s = q1.getSize();
		Queue<t1> q2(s);
		while (!q1.isEmpty())	//take out all elements from q1 and keep in q2
		{
			t1 v = q1.deQueue();
			q2.enQueue(v);		//enQueue will itself check size and adjust if required
		}
		q1.enQueue(valu);		//now keep the latest element entered at front to make LIFO behaviour
		while (!q2.isEmpty())
		{
			t1 v = q2.deQueue();
			q1.enQueue(v);		//now insert in q1 the previous taken out elements
		}
	}
	else
	{
		q1.enQueue(valu);
	}
}

	//following all functions calling respective functiond from Queue ADT
template<class t1>
t1 stackQ<t1>::pop()
{
	//function removes and returns the top-most element of stackQ
	return q1.deQueue();
}

template<class t1>
t1 stackQ<t1>::top()
{
	//function only returns(not removes) the top-most element of stackQ
	return q1.Front();
}

template<class t1>
void stackQ<t1>::print()
{
	//function prints the whole stackQ from top to bottom
	q1.showStructure();
}

template<class t1>
bool stackQ<t1>::isfull()
{
	//function return 1 if stackQ is full && 0 if not
	return q1.isFull();
}

template<class t1>
bool stackQ<t1>::isempty()
{
	//function return 1 if stackQ is empty && 0 if not
	return q1.isEmpty();
}


template<class t1>
int stackQ<t1>::sizee()
{
	//function return 1 if stackQ is empty && 0 if not
	return q1.getSize();
}


template<class t1>
stackQ<t1>::~stackQ()
{
	//delete q1;
}

