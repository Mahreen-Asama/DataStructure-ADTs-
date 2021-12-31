#include "StudentMaxHeap.h"

StudentMaxHeap::StudentMaxHeap(int size)	//Constructor
{
	maxSize = size;
	curSize = 0;
	arr = new Student[maxSize];
}
StudentMaxHeap::StudentMaxHeap(const StudentMaxHeap& obj)	//copy constructor
{
	maxSize = obj.maxSize;
	curSize = obj.curSize;
	arr = new Student[maxSize];
	for (int i = 0; i < curSize; i++)
	{
		arr[i] = obj.arr[i];
	}
}
StudentMaxHeap::~StudentMaxHeap()			//destructor
{
	delete[]arr;
}
bool StudentMaxHeap::isEmpty()
{
	/*
	* function Checks whether the heap is empty or not
	*/
	return curSize == 0;
}
bool StudentMaxHeap::isFull()
{
	/*
	* function checks whether heap is full or not
	*/
	return curSize == maxSize;
}
StudentMaxHeap& StudentMaxHeap::operator = (const StudentMaxHeap& obj)	
{
	delete[]arr;							//Overloaded assignment operator 
	maxSize = obj.maxSize;
	curSize = obj.curSize;
	arr = new Student[maxSize];
	for (int i = 0; i < curSize; i++)
	{
		arr[i] = obj.arr[i];
	}
	return *this;
}
int StudentMaxHeap::getParent(int i)
{
	/*
	* function returns index of parent node of given node's index
	*/
	return (i - 1) / 2;
}
int StudentMaxHeap::getLeftChild(int i)
{
	/*
	* function returns index of left child of given parent
	*/
	return 2 * i + 1;
}
int StudentMaxHeap::getRightChild(int i)
{
	/*
	* function returns index of right child of given parent
	*/
	return 2 * i + 2;
}
bool StudentMaxHeap::insert(string name, double cgpa, int rollNo)
{
	/*
	* function inserts a node in heap tree and satisfies heap properties
	* arguments: node data
	* return: true if data inserted succesfully && false otherwise
	*/
	// O(logn) is possible along only one path fromm node to root...
	if (!isFull())
	{
		Student s1(name, cgpa, rollNo);
		arr[curSize] = s1;							//inserting value....
		if (curSize > 0)							//need to check all the nodes 
		{
			//cout << "\ncomparison\n";
			Student parent = arr[getParent(curSize)];
			Student child = arr[curSize];
			int i = curSize;
			while (i > 0)
			{
				if (child.cgpa < parent.cgpa)							//then ok
					break;
				if (child.cgpa == parent.cgpa && child.rollNumber > parent.rollNumber)
					break;
				if (child.cgpa == parent.cgpa && child.rollNumber < parent.rollNumber)
				{
					
					arr[getParent(i)] = child;
					arr[i] = parent;
					break;
				}
				arr[getParent(i)] = child;
				arr[i] = parent;
				i = (i - 1) / 2;
				parent = arr[getParent(i)];
				child = arr[i];
			}
		}
		curSize++;
		return true;
	}
	return false;									//if heap was full
}
Student StudentMaxHeap::extractTopper()
{
	/*
	* This function will remove the record from the Max Heap which has the highest CGPA. 
	* arguments: none
	* return: student object wiht highest GPA
	*/
	if (!isEmpty())
	{
		Student temp = arr[0];					//swap them
		arr[0] = arr[curSize - 1];
		arr[curSize - 1] = temp;
		curSize--;								//root removed
		int pi = 0;
		while (true)
		{
			if (getLeftChild(pi) >= curSize || getRightChild(pi) >= curSize)
				break;
			Student left = arr[getLeftChild(pi)];
			Student right = arr[getRightChild(pi)];
			if (right.cgpa > left.cgpa)
			{
				if (right.cgpa > arr[pi].cgpa)
				{
					Student temp = right;				//swap (parent,child)
					arr[getRightChild(pi)] = arr[pi];
					arr[pi] = temp;
					
				}
				pi = getRightChild(pi);
			}
			else
			{
				if (left.cgpa > arr[pi].cgpa)
				{
					Student temp = left;				//swap (parent,child)
					arr[getLeftChild(pi)] = arr[pi];
					arr[pi] = temp;

				}
				pi = getLeftChild(pi);
			}
		}
	}
	return arr[curSize];
}
void StudentMaxHeap::displayStudentList()
{
	/*
	This function will display the students list in descending order of CGPAs.If two students have
	the same CGPA, then the student with smaller roll number will be displayed before the student
	with larger roll number.
	*/
	//heap sort can be used here
	Student* arr2 = new Student[curSize];
	for (int i = 0; i < curSize; i++)
		arr2[i] = arr[i];

	//now sort array2
	for (int i = 0; i < curSize; i++)
	{
		for (int j = i + 1; j < curSize; j++)
		{
			if (arr2[i].cgpa < arr2[j].cgpa)
			{
				Student temp = arr2[i];
				arr2[i] = arr2[j];
				arr2[j] = temp;
			}
			else if (arr2[i].cgpa == arr2[j].cgpa)				//if gpa equal, sort on the basis of roll#
			{
				if (arr2[i].rollNumber > arr2[j].rollNumber)
				{
					Student temp = arr2[i];
					arr2[i] = arr2[j];
					arr2[j] = temp;
				}
			}
		}
	}
	for (int i = 0; i < curSize; i++)
		cout << arr2[i] << endl;
	delete[]arr2;
	
}
void StudentMaxHeap::printHeap()
{
	/*
	*  function will display a level order traversal of the StudentMaxHeap
	*/
	int minLevels = ceil(log2(curSize + 1));
	//cout << "\nminlevels: " << minLevels << endl;
	int j = 0, count = 0;
	for (int i = 1; i <= minLevels; i++)
	{
		int n = pow(2, i - 1);					//max number of nodes in a level
		for (j = count; j < n + count; j++)
		{
			if (j == curSize)
				break;							//last level some empty
			cout << arr[j] << "\t";
		}
		count = j;
		cout << endl;
	}
}