#include "Node.h"

template<typename T>
Node<T>::Node()
{
	data = 0;
	next = NULL;
}

template<typename T>
Node<T>::Node(T inData, Node* nPtr)
{
	data = inData;
	next = nPtr;
}