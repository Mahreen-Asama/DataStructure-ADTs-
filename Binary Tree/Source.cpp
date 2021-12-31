#include<iostream>
#include<cmath>
#include"BTree.h"
#include"BTree.cpp"
using namespace std;

int main()
{									//testing by hardcode
	BTree<int> t1(4);
	t1.setRoot(23);

	t1.setLeftChild(23, 15);		//level 1
	t1.setRightChild(23, 2);

	t1.setLeftChild(15, 5);			//level 2
	t1.setRightChild(15, 8);

	t1.setLeftChild(2, 33);			//level 3
	
	t1.setRightChild(33, 11);		//level 4


	cout << "\nInOrder traversal:  "; t1.inOrder();
	cout << "\nlevelOrder traversal:  "; t1.levelOrder();
	cout << "\nHeight of tree: " << t1.getHeight() << endl;

	t1.remove(33);
	cout << "\nInOrder traversal:  "; t1.inOrder();
	cout << "\nlevelOrder traversal:  "; t1.levelOrder();
	cout << "\nHeight of tree: " << t1.getHeight() << endl;

	cout << "\ndescendents: "; t1.displayDescendents(15);
	cout << "\nancestors: "; t1.displayAncestors(8);

	if(t1.isPerfectTree())
		cout << "\nIt is a perfect tree\n";
	else
	cout << "\nTree is not perfect\n";

	if (t1.isCompleteTree())
		cout << "\nIt is a complete tree\n";
	else
		cout << "\nTree is not a complete tree\n";

}