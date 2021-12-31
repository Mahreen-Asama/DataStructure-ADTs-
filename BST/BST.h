#pragma once
#include"BSTNode.h"
#include<iostream>
using namespace std;

template<class T>
class BST
{
	BSTNode<T>* root;

	void deleteBST(BSTNode<T>*);
	BSTNode<T>* copyBST(BSTNode<T>*);
	BSTNode<T>* getParent(BSTNode<T>*);
	void inOrder(BSTNode<T>*);
	void preOrder(BSTNode<T>*);
	void postOrder(BSTNode<T>*);
	int findMaxHeight(int h1, int h2);
	void printCurrentLevel(BSTNode<T>* root, int level);
public:
	BST();
	BST(T);
	~BST();										//wrapper func
	BST(const BST<T>&);							//wrapper func
	void setRoot(T);
	BSTNode<T>* getRoot();
	void insert(T);
	BSTNode<T>* getLeftChild(BSTNode<T>*);
	BSTNode<T>* getRightChild(BSTNode<T>*);
	BSTNode<T>* search(T);
	void deleteNode(BSTNode<T>*);							// is not working correct
	void printNodes(BSTNode<T>*);
	bool isBST(BSTNode<T>*);

	void printTree();										//missing function
	bool isEqual(BSTNode<T>*, BSTNode<T>*);
	bool isInternalNode(BSTNode<T>*);
	bool isExternalNode(BSTNode<T>*);
	int getHeight(BSTNode<T>*);

	void displayDescendents(T);
	void displayAncestors(T);
	BST<T> getMirror(BSTNode<T>*);
	int getNodeCount(BST<T>*);
	T findMin(BSTNode<T>*);
	T findMax(BSTNode<T>*);

	void levelOrder(BSTNode<T>*);

};

