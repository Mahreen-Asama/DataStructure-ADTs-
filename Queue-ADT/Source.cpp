#include<iostream>
#include<string>
#include"Queue.h"
#include"Queue.cpp"
using namespace std;

int main()
{
	//Note: to check template, there is need to change datatype of variable "v" and queue(obviously) 
	Queue<double> queue;
	double v; int n = 0;
	cout << "enter size of queue: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "enter value: "; cin >> v;
		queue.enQueue(v);
	}
	cout << "\n******before deQueue******\n";
	queue.showStructure(); cout << "--> rear\n";

	//...........................remove elements from queue..................................
	cout << "\nhow many values you want to remove from queue: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		queue.deQueue();
	}
	cout << "\n******after deQueue******\n";
	queue.showStructure();  cout << "--> rear\n";

	/*
	cout<<"showing circular behaviour:\n";
	for (int i = 0; i < 3; i++)
		queue.enQueue(i);
	queue.showStructure();  cout << "--> rear\n";
	*/

}