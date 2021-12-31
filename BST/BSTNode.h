#pragma once

template<class T>				//forward declaration of template class BSTree
class BST;

template<class T>
class BSTNode
{
	friend class BST<T>;				//to access its private data
	T data;
	BSTNode<T>* left;
	BSTNode<T>* right;

	BSTNode();
	BSTNode(T d, BSTNode* = nullptr, BSTNode* = nullptr);
	~BSTNode()
	{
		delete left;
		delete right;
	}
};

