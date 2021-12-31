#pragma once
#include<cmath>
#include<iostream>
using namespace std;

template<class T>
class BTree
{
	/*
	* height ->  represent the height of the tree.
	* n -> tells maximum number of nodes in tree of height h.
	* data -> this array stores the tree nodes.
	* status ->  this array is used to find that whether there is a node on a particular index or not.
				 If there is a valid node exitsts on a particular index the status array holds 'true'
				 on corresponding index, otherwise holds false
	*/
	int height;
	//const int n;				// n is required in every function so, we made it data member
	T* data;						
	bool* status;					
public:
	//BTree();
	BTree(int);
	BTree(const BTree&);
	~BTree();
	void setRoot(T);
	T getRoot();
	T getNode(int);
	void setLeftChild(T, T);
	void setRightChild(T, T);
	int getParent(int = 0);
	int getLeftChild(int = 0);
	int getRightChild(int = 0);
	void remove(T);
	void preOrder(int = 0);					// V L R 
	void postOrder(int = 0);				// L R V
	void inOrder(int = 0);					// L V R
	void levelOrder();
	void displayAncestors(T);
	void displayDescendents(T);
	bool isPerfectTree();
	bool isCompleteTree();
	bool isFullTree();
	int getHeight();						//returns height of tree
	//bool getStatus(int index);
};

