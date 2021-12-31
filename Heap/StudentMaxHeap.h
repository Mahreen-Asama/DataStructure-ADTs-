#pragma once
#include"Student.h"
#include<cmath>
#include<iostream>
using namespace std;

class StudentMaxHeap
{
	Student* arr;				//Array of students which, arranged like a Max Heap 
	int curSize;				//Current number of students present in the heap 
	int maxSize;				//Maximum number of students that can be present in heap
	int getParent(int i);
	int getLeftChild(int i);
	int getRightChild(int i);
	//void swap(Student& parent, Student& child);
public:
	StudentMaxHeap(int size);
	StudentMaxHeap(const StudentMaxHeap&);
	~StudentMaxHeap();
	bool isEmpty();
	bool isFull();
	StudentMaxHeap& operator = (const StudentMaxHeap&);
	bool insert(string name, double cgpa, int rollNo);
	Student extractTopper();
	void displayStudentList();
	void printHeap();

};

