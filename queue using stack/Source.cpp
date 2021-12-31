#include<iostream>
using namespace std;
#include"MyStack.h"
#include"MyStack.cpp"
#include"QueueS.h"
#include"QueueS.cpp"

int main()
{
	QueueS<int> q1;
	int v;
	for (int i = 0; i < 15; i++)
	{
		cin >> v;
		q1.enQueue(v);
	}
	cout << "before removing:\n";
	q1.showStructure(); cout << " <-- rear\n";
	for (int i = 0; i < 7; i++)
	{
		q1.deQueue();
	}
	cout << "after removing:\n";
	q1.showStructure(); cout << " <-- rear\n\n";

	QueueS<int> q2 = q1;
	cout << "q2 is\n"; q2.showStructure();
	q2.deQueue();
	q1 = q2;
	cout << "q1 is\n"; q1.showStructure();

}