#include "Queue.h"

//NOTE: time complexity is written in Big-Oh terms for each function
template<class T>
void Queue<T>::resize(int s)		//Time: O(n), where n==count of elements in queue
{
	/*
	function doubles/halfs size of queue according to calling
	arguments: new size of queue
	return: nothing
	*/
	//front==0 && back==size-1 when there is a need to resize
	int ps = size;
	size = s;
	T* temp = que;
	int count2 = count;
	count = 0;
	back = -1;
	que = new T[size];
	int p = front - 1;
	for (int i = 0; i < count2; i++)
	{
		p = (p + 1) % ps;
		enQueue(temp[p]);
	}
	front = 0;
	delete[]temp;
}

template<class T>
Queue<T>::Queue()				//Time: O(1)
{
	/*
	Default Constructor automatically calls when object is created without mentioning size
	arguments: no
	return: nothing
	*/
	size = 10;
	que = new T[size];					//by default size 10
	count = 0;
	front = 0;
	back = -1;
}
template<class T>
Queue<T>::Queue(int s)			//Time: O(1)
{
	/*
	Parametized Constructor automatically calls when object is created by mentioning size
	arguments: no
	return: nothing
	*/
	size = s;
	que = new T[size];					//given size 
	count = 0;
	front = 0;
	back = -1;
}

template<class T>
Queue<T>::Queue(const Queue& obj)	//Time: O(n)
{
	/*
	Copy Constructor automatically calls when an object is created and initialized by another existing object
	arguments: existing object
	return: nothing
	*/
	size = obj.size;
	que = new T[size];
	count = 0;
	back = obj.front - 1;				//starting from front of obj to end of obj
	int p = obj.front - 1;
	for (int i = 0; i < obj.count; i++)
	{
		p = (p + 1) % size;				//to handle circular property, front to end
		enQueue(obj.que[p]);
	}
	front = obj.front;
}

/*
template<class T>
void Queue<T>::operator=(Queue obj)		//Time: O(n)
{
	//Assignment operator automatically calls when an existing object is assigned the value of another existing object
	//arguments: existing object(whose values to be assigned)
	//return: nothing
	size = obj.size;
	que = new T[size];
	count = 0;
	back = obj.front - 1;
	int p = obj.front - 1;
	for (int i = 0; i < obj.count; i++)
	{
		p = (p + 1) % size;
		enQueue(obj.que[p]);
	}
	front = obj.front;
}
*/
template<class T>
void Queue<T>::enQueue(T value)		//Time: O(n), due to resize function
{
	/*
	function updates back pointer of queue and adds value at the back of queue, also increases size if required
	arguments: value to be entered
	return: nothing
	*/
	if (!isFull())       //if queue not full, simply add value
	{
		back = (back + 1) % size;
		que[back] = value;
		count++;
	}
	else                 //if queue is full, then doubles its size then push 
	{
		resize(size * 2);
		back = (back + 1) % size;
		que[back] = value;
		count++;
	}
}

template<class T>
T Queue<T>::deQueue()				//Time: O(n), due to resize function
{
	/*
	function removes element from the front of queue, also resizes queue if required
	arguments: no
	return: value which has been removed
	*/
	if (!isEmpty())
	{
		if (count < size / 4)
			resize(size / 2);
		T r = que[front];
		count--;							//count-- helps to remove....
		front = (front + 1) % size;
		return r;
	}
	else
	{
		cout << "error! queue is empty\n";
	}
}

template<class T>
T Queue<T>::Front()				//Time: O(1)
{
	/*
	function tells the first element present at front of queue
	arguments: no
	return: first element of queue
	*/
	if (!isEmpty())
		return que[front];
	else
		cout << "error! queue is empty\n";
}

template<class T>
T Queue<T>::Back()				//Time: O(1)
{
	/*
	function tells the most recent element added to queue
	arguments: no
	return: element at end of queue
	*/
	if (!isEmpty())
		return que[back];
	else
		cout << "error! queue is empty\n";
}

template<class T>
bool Queue<T>::isFull()			//Time: O(1)
{
	/*
	function returns true(1) if queue is full and false(0) otherwise
	arguments: no
	return: true/false(1/0)
	*/
	return count == size;
}

template<class T>
bool Queue<T>::isEmpty()		//Time: O(1)
{
	/*
	function returns true(1) if queue is empty and false(0) otherwise
	arguments: no
	return: 1 OR 0
	*/
	return count == 0;
}

template<class T>
int Queue<T>::getSize()			//Time: O(1)
{
	/*
	function gives number of elements present in queue
	arguments: no
	return: number of elements
	*/
	return count;
}

template<class T>
void Queue<T>::showStructure()	//Time: O(n)
{
	/*
	function displays whole queue(from front to rear) with its rear pointing to the correct location
	arguments: no
	return: nothing
	*/
	if (!isEmpty())
	{
		int p = front - 1;
		for (int i = 0; i < count; i++)
		{
			p = (p + 1) % size;
			cout << endl << que[p];
		}
	}
	else
		cout << "queue is empty\n";
}

template<class T>
Queue<T>::~Queue()			//Time: O(1)
{
	/*
	Destructor function deletes dynamic memory allocated to make queue
	arguments: no
	return: nothing
	*/
	delete[]que;
}

/*
template<class T>
void Queue<T>::print()		//Time: O(n)
{
	//function prints the whole queue from front to back
	//arguments: no
	//return: nothing
	int p = front - 1;
	for (int i = 0; i < count; i++)
	{
		p = (p + 1) % size;
		cout << que[p] << " ";
	}
	cout << endl;
}
*/
