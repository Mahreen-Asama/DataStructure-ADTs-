#pragma once
#include<iostream>
using namespace std;
#include<string>

class Student
{
	friend class StudentMaxHeap;
	friend ostream& operator <<(ostream&, const Student&);
private:
	string name;
	double cgpa;
	int rollNumber;

	// Methods…
	Student();
	Student(string, double, int);
	Student(const Student&);
	Student& operator=(const Student&);

};


