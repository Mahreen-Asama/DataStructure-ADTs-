#include<iostream>
#include<string>
#include"Queue.h"
#include"Queue.cpp"
#include"stackQ.h"
#include"stackQ.cpp"
using namespace std;

/*
--> implementing stack using queue:-
--> there can be several ways(composition,aggregation,inheritance) to implement stack using queue
--> here, I am using 'aggregation' method; keeping "that queue itself exits without stack" so there 
	should be aggregation relationship between them instead of composition
--> i.e; queue is used as data-structure to implement stack functionality(LIFO/FILO)
--> similarly,link-list....etc can also be used as data structure to implement stack...
*/
int main()
{
	stackQ<int> s1;
	int v, n;
	cout << "enter size of stack: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "enter value: "; cin >> v;
		s1.push(v);
	}
	cout << "stack is\n";
	s1.print(); cout << endl;
	//cout << "size " << s1.sizee() << endl;
	cout << "how many values you want to pop: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		s1.pop();
	}
	cout << "after pop, stack is\n";
	s1.print(); cout << endl;

}