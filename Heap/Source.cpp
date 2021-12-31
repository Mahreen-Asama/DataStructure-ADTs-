#include<iostream>
#include<string>
#include"StudentMaxHeap.h"
using namespace std;

int main()
{
	int n;
	cout << "Enter maximum # of students: "; cin >> n;
	StudentMaxHeap smh(n);
	do
	{
		cout << "\n\t****************************************************";
		cout << "\n1- Insert a new student\n2- Remove and display the student with maximum cgpa";
		cout << "\n3- Display the list of students (dessending order of CGPA)";
		cout << "\n4- Display the list of students (Level order Traversal)\n5- Exit";
		cout << "\n\nEnter your choice: "; cin >> n;
		string name;
		double cgpa;
		int rollNo;
		switch (n)
		{
		case 1:
			cout << "\nEnter name: "; cin >> name;
			cout << "Enter roll#: "; cin >> rollNo;
			cout << "Enter cgpa: "; cin >> cgpa;
			if (smh.insert(name, cgpa, rollNo))
				cout << "\ndata inserted successfully\n";
			else
				cout << "\nsorry! we couldn't insert data_heap is already full\n";
			break;
		case 2:
			cout << "********Data of student with maximum cgpa is*******\n";
			cout << smh.extractTopper() << endl;
			break;
		case 3:
			cout << "********Data of all Students_(name,roll#,cgpa)********\n\n";
			smh.displayStudentList();
			break;
		case 4:
			cout << "********Level Order Traversal (name,roll#,cgpa)*********\n\n";
			smh.printHeap();
			break;
		case 5:
			n = 6;									//to get out of loop
			break;
		default:
			cout << "Wrong choice!\n"; n = 1;		//just to re_run
		}
	} while (n > 0 && n < 6);

	/*
	StudentMaxHeap s2(8);				checking copy constructor & assignment operator
	s2 = smh;
	cout << "s2 print heap\n";
	s2.printHeap();
	StudentMaxHeap s3 = s2;
	cout << "s3 print heap\n";
	s3.printHeap();
	*/
}