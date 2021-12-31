#include<iostream>
#include"Node.h"
#include"Node.cpp"
#include"LinkedList.h"
#include"LinkedList.cpp"
using namespace std;

//NOTE: to check template, we need to do 3 changings
//		1) Linkedlist<datatype> list         2) datatype inputVal       3) datatype key
//here we are using same variable again and again to take input for different functions

int main()
{
	//........................checking functionality of class functions.............................

	cout << "\t*** Enter linkList data for 10 elements and check its functionality ***";
	cout << "\n\t.......................................................\n";
	LinkedList<int> list;
	int inputVal;
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter a value to insert at head: ";
		cin >> inputVal;
		list.insertAtHead(inputVal);								//insert At Head
	}
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter a value to insert at tail: ";
		cin >> inputVal;
		list.insertAtTail(inputVal);								//insert At Tail
	}
	cout << "\nLinkedList is:\n";
	list.printList();												//printList
	cout << "Length of list is: " << list.getLength() << endl;		//getLength

	LinkedList<int> list2 = list;
	cout << "\nDuplicate of this list is:\n";
	list2.printList();
	cout << "Length of list2 is: " << list2.getLength() << endl;		//getLength

	//..................................................................................................
	//..................................................................................................
	cout << "\n........................Deleting a specific value...............................\n";
	int key;
	cout << "\nEnter the value you want to remove from list: ";
	cin >> key;
	if (list.Delete(key))												//Delete(key)
	{
		cout << "value deleted successfully\n";
		cout << "\nNewList is:\n";
		list.printList();												//printList
		cout << "Length of list is: " << list.getLength() << endl;		//getLength
	}
	else
	{
		cout << "value not found\n";
	}

	//..................................................................................................
	//..................................................................................................
	cout << "\n.............................Delete value at Head.....................................\n";
	cout << "Enter 1 if you want to delete value at Head and 0 if not: "; cin >> key;
	if (key)
	{
		if (list.deleteAtHead())		//if list is not empty				deleteAtHead
		{
			cout << "value deleted successfully\n";
			cout << "\nNewList is:\n";
			list.printList();												//printList
			cout << "Length of list is: " << list.getLength() << endl;		//getLength
		}
		else
		{
			cout << "There is nothing to delete_List is Empty\n";
		}
	}

	//..................................................................................................
	//..................................................................................................
	cout << "\n.............................Delete value at Tail..................................\n";
	cout << "Enter 1 if you want to delete value at Tail and 0 if not: "; cin >> key;
	if (key)
	{
		if (list.deleteAtTail())		//if list is not empty				deleteAtTail
		{
			cout << "value deleted successfully\n";
			cout << "\nNewList is:\n";
			list.printList();												//printList
			cout << "Length of list is: " << list.getLength() << endl;		//getLength
		}
		else
		{
			cout << "There is nothing to delete_List is Empty\n";
		}
	}

	//..................................................................................................
	//..................................................................................................
	cout << "\n........................insert_Before value...............................\n";
	cout << "\nEnter the value you want to find in the list: ";
	cin >> key;
	cout << "Enter the value you want to insert before found value";
	cin >> inputVal;
	if (list.insertBefore(inputVal, key))								//insertBefore
	{
		cout << "value inserted successfully\n";
		cout << "\nNewList is:\n";
		list.printList();												//printList
		cout << "Length of list is: " << list.getLength() << endl;		//getLength
	}
	else
	{
		cout << "value not found\n";
	}

	//..................................................................................................
	//..................................................................................................
	cout << "\n.........................insert_After value.............................\n";
	cout << "\nEnter the value you want to find in the list: ";
	cin >> key;
	cout << "Enter the value you want to insert after found value";
	cin >> inputVal;
	if (list.insertAfter(inputVal, key))								//insert_After
	{
		cout << "value inserted successfully\n";
		cout << "\nNewList is:\n";
		list.printList();												//printList
		cout << "Length of list is: " << list.getLength() << endl;		//getLength
	}
	else
	{
		cout << "value not found\n";
	}

	//..................................................................................................
	//..................................................................................................
	cout << "\n........................Delete_Before value...............................\n";
	cout << "\nEnter the value you want to find in the list to delete value before it: ";
	cin >> key;
	if (list.deleteBefore(key))											//deleteBefore
	{
		cout << "value deleted successfully\n";
		cout << "\nNewList is:\n";
		list.printList();												//printList
		cout << "Length of list is: " << list.getLength() << endl;		//getLength
	}
	else
	{
		cout << "value not found\n";
	}

	//..................................................................................................
	//..................................................................................................
	cout << "\n........................Delete_After value...............................\n";
	cout << "\nEnter the value you want to find in the list to delete value after it: ";
	cin >> key;
	if (list.deleteAfter(key))											//deleteAfter
	{
		cout << "value deleted successfully\n";
		cout << "\nNewList is:\n";
		list.printList();												//printList
		cout << "Length of list is: " << list.getLength() << endl;		//getLength
	}
	else
	{
		cout << "value not found\n";
	}

	//..................................................................................................
	//..................................................................................................
	cout << "\n........................get an element...............................\n";
	cout << "Enter number(position) of element whose address you want to get: ";
	cin >> key;
	cout << "address of element is: " << list.getNode(key) << endl;

	//..................................................................................................
	//..................................................................................................
	cout << "\n........................Search an element...............................\n";
	cout << "\nEnter the value you want to search in the list: ";
	cin >> key;
	 if (!list.search(key))
		 cout << "value not found\n";
	 else
		cout << "address of element is: " << list.search(key);

	cout << "\n\n\t THANK U FOR VISITING\n\n";
	return 0;

}