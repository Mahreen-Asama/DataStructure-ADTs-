#include "Node.h"

template<typename T>
Node<T>::Node()
{
	data = 0;
	next = nullptr;
	prev = nullptr;
}

template<typename T>
Node<T>::Node(T inData, Node* nPtr, Node* pptr)
{
	data = inData;
	next = nPtr;
	prev = pptr;
}