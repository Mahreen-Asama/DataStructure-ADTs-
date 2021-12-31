#include<iostream>
#include"BST.h"
#include"BST.cpp"
#include"BSTNode.h"
#include"BSTNode.cpp"
using namespace std;

int main()
{
	BST<int> tree;
	int val;
	for (int i = 0; i < 7; i++)
	{
		cout << "Enter the value to be inserted: ";
		cin >> val;
		tree.insert(val);
	}
	tree.printNodes(tree.getRoot());					//inorder print
	cout << endl;
	tree.levelOrder(tree.getRoot());
	/*
	cout << "\nMax value: " << tree.findMax(tree.getRoot()) << endl;
	cout << "\nMin value: " << tree.findMin(tree.getRoot()) << endl;

	cout << "Enter node to see its ancestors: "; cin >> val;
	tree.displayAncestors(val);										//level display (low to high)
	cout << "Enter node to see its descendents: "; cin >> val;
	tree.displayDescendents(val);						//level order display

	tree.getMirror(tree.getRoot());
	cout << "Tree after mirror reflection: ";
	tree.printNodes(tree.getRoot());					//inorder print
	
	cout << "Enter node value you want to delete: "; cin >> val;
	tree.deleteNode(tree.search(val));
	cout << "now tree is: ";
	tree.printNodes(tree.getRoot());					//inorder print
	*/

	cout << "\nHeight of tree: " << tree.getHeight(tree.getRoot());
	BST<int> tree2 = tree;
	tree2.printNodes(tree2.getRoot());					//copy constructor checking
	tree2.deleteNode(tree2.search(6));
	cout << "\nare trees equal: " << tree.isEqual(tree.getRoot(), tree2.getRoot());
	cout << "\nis internal node: " << tree2.isInternalNode(tree2.search(12));
	cout << "\nis external node: " << tree2.isExternalNode(tree2.search(12));


}