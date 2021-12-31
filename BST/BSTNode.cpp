#include "BSTNode.h"

template<class T>
BSTNode<T>::BSTNode() :left(nullptr), right(nullptr)
{
	//default constructor
}

template<class T>
BSTNode<T>::BSTNode(T d, BSTNode* l, BSTNode* r)
{
	//parametized constructor
	data = d;
	left = l;
	right = r;
}
