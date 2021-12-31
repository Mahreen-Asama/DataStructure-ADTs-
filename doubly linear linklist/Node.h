#pragma once
#include<iostream>
using namespace std;

template<typename T>
class Node
{
public:
	T data;
	Node<T>* next;
	Node<T>* prev;

	Node();
	Node(T, Node* = NULL, Node* = NULL);
};

