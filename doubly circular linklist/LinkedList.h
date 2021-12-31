#pragma once
#include"Node.h"

template<typename T>
class LinkedList
{
public:
	//we can have size of list.....variable
	Node<T>* head;					//points at the start to indicate start of list,
	Node<T>* tail;					//points at the end to indicate end(boundary) of list 
public:
	LinkedList();
	LinkedList(const LinkedList&);
	bool isEmpty();
	void insertAtHead(T);
	void insertAtTail(T);
	bool deleteAtHead();
	bool deleteAtTail();
	bool Delete(T);				//key to be deleted
	void printList();
	~LinkedList();
	Node<T>* getHead();
	Node<T>* getTail();
	//...................................
	Node<T>* getNode(int);
	bool insertBefore(T, T);
	bool insertAfter(T, T);		//value and key
	bool deleteBefore(T);
	bool deleteAfter(T);		//key after to be deleted
	int getLength();
	Node<T>* search(T);			//key to search
};

