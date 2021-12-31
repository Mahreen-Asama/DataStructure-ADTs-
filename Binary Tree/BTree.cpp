#include "BTree.h"
/*
	template<class T>
	BTree<T>::BTree()
	{
		//cout<<"default constructor\n";
		height = 5;								//choose by default
		int n = (pow(2, height) - 1);
		data = new T[n];
		status = new bool[n];
		for (int i = 0; i < n; i++)
		{
			status[i] = false;
		}
	}
*/
template<class T>
BTree<T>::BTree(int h) 
{
	/*
	* parametized constructor initializes all the data members 
	* arguments: height of tree
	* return: nothing
	*/
	//cout << "parametized const\n";
	//cout << n << endl;
	height = h;
	int n = (pow(2, height) - 1);
	data = new T[n];
	status = new bool[n];
	for (int i = 0; i < n; i++)
	{
		status[i] = false;
	}
}

template<class T>
BTree<T>::BTree(const BTree& obj)
{
	/*
	* copy constructor initializes object with an existing object
	* arguments: existing object to be copied
	* return: nothing
	*/
	//cout << "copy constructor\n";
	height = obj.height;
	int n = (pow(2, height) - 1);
	data = new T[n];
	status = new bool[n];
	for (int i = 0; i < n; i++)
	{
		data[i] = obj.data[i];
		status[i] = obj.status[i];
	}
}

template<class T>
BTree<T>::~BTree()
{
	/*
	* destructor deallocates heap memory allocated for tree nodes
	* arguments: no
	* return: nothing
	*/
	//cout << "destructor\n";
	delete[]data;
	delete[]status;
}

template<class T>
void BTree<T>::setRoot(T val)
{
	/*
	* function sest val at data[0] as a root of tree and set status[0] as true
	* arguments: value of root node
	* return: nothing
	*/
	//cout << "set root fun\n";
	data[0] = val;
	status[0] = true;
}

template<class T>
T BTree<T>::getRoot()
{
	/*
	* function returns the root of tree if exists.
	* arguments: no
	* return: root value
	*/
	//cout << "get root fuc\n";
	if (status[0])
		return data[0];
	else
	{
		cout << "There is no root & no tree\n";
		//return int_min;
	}
}

template<class T>
T BTree<T>::getNode(int index)
{
	/*
	* function returns the root of tree if exists.
	* arguments: no
	* return: root value
	*/
	if (status[index])
		return data[index];
	else
	{
		cout << "This node doesn't exist\n";
		//return int_min;
	}
}

template<class T>
void BTree<T>::setLeftChild(T par, T val)   //par=value of parent node
{
	/*
	* function sets 'val' as left child of given Parent.
	* arguments: parent value, child value to be set
	* return: nothing
	*/
	//cout << "set left child\n";
	int n = (pow(2, height) - 1);
	int i;
	for (i = 0; i < n; i++)
	{
		if (data[i] == par)					//we need to find index i of that parent 
			break;
	}
	int li = getLeftChild(i);
	data[li] = val;
	status[li] = true;
}

template<class T>
void BTree<T>::setRightChild(T par, T val)   //i=parent node index
{
	/*
	* function sets 'val' as right child of given Parent.
	* arguments: parent value, child value to be set
	* return: nothing
	*/
	//cout << "set right child\n";
	int n = (pow(2, height) - 1);
	int i;
	for (i = 0; i < n; i++)
	{
		if (data[i] == par)					//we need to find index i of that parent 
			break;
	}
	int ri = getRightChild(i);
	data[ri] = val;
	status[ri] = true;
}

template<class T>
int BTree<T>::getParent(int i)				
{
	/*
	* function finds the index of parent node of the child having index i
	* arguments: index i of child
	* return: parent node index
	*/
	//cout << "get parent func\n";
	return (i - 1) / 2;							//int itself truncates to floor value
}

template<class T>
int BTree<T>::getLeftChild(int par)			
{
	/*
	* function returns index of left child of given parent
	* arguments: index of parent
	* return: left child index
	*/
	//cout << "get left child\n";c
	return 2 * par + 1;							//all the left children lie on odd indexes
}

template<class T>
int BTree<T>::getRightChild(int par)
{
	/*
	* function returns index of right child of given parent
	* arguments: index of parent
	* return: left child index
	*/
	//cout << "get right child\n";
	return 2 * par + 2;							//all the right children lie on even indexes
}

template<class T>
int BTree<T>::getHeight()
{
	int n = (pow(2, height) - 1);
	int i, count = 1;
	for (i = n - 1; i >= 0; i--)
	{
		if (status[i] == true)					//got last level child index 
			break;
	}
	int pi = getParent(i);
	while (pi > 0)
	{
		count++;
		pi = getParent(pi);
	}
	return ++count;								//1 add of  root
}
template<class T>
void BTree<T>::remove(T node)
{
	/*
	* function removes the given node and all its descendants.
	* arguments: node to be removed
	* return: nothing
	*/
	//cout << "remove func\n";
	//function first removes left subtree of 'node', then right subtree of 'node', then node, i.e, L R N
	//height of tree will change after removing descendents
	int n = (pow(2, height) - 1);
	int i;
	for (i = 0; i < n; i++)
	{
		if (data[i] == node)				//first we need to find index i of node 
			break;
	}
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left >= n || right >= n || (status[left] == false && status[right] == false))  //degree zero nodes
	{
		status[i] = false;					//remove that node
		height = getHeight();				
		return;
	}
	if (status[left] == true)
		remove(data[left]);					//recursive call for left subtree
	if (status[right] == true)
		remove(data[right]);				//recursive call for right subtree
	status[i] = false;						//remove that node parent(passed)
	height = getHeight();

}

template<class T>
void BTree<T>::preOrder(int i)				// V L R , i will start from zero (header file)
{
	/*
	* function display tree nodes using preOrder Traversal.
	* arguments: required for recursive call
	* return: nothing
	*/
	//cout << "preOrder func\n";
	int n = (pow(2, height) - 1);
	if (i >= n)								//base case
		return;
	if (status[i])
		cout << data[i] << " ";
	else
	{
		//cout << "N ";						//showing null , no child
	}
	preOrder(2 * i + 1);					//left subtrre
	preOrder(2 * i + 2);					//right subtree
}

template<class T>
void BTree<T>::postOrder(int i)				// L R V
{
	/*
	* function display tree nodes using postOrder Traversal.
	* arguments: required for recursive call
	* return: nothing
	*/
	//cout << "postOrder func\n";
	int n = (pow(2, height) - 1);
	if (i >= n)								//base case
		return;
	postOrder(2 * i + 1);					//left subtrre
	postOrder(2 * i + 2);					//right subtree
	if (status[i])
		cout << data[i] << " ";
	else
	{	
		//cout << "N ";						//showing null , no child
	}
}

template<class T>
void BTree<T>::inOrder(int i)				// L V R
{
	/*
	* function display tree nodes using inOrder Traversal.
	* arguments: required for recursive call
	* return: nothing
	*/
	//cout << "inOrder func\n";
	int n = (pow(2, height) - 1);
	if (i >= n)								//base case
		return;
	inOrder(2 * i + 1);						//left subtrre
	if (status[i])
		cout << data[i] << " ";
	else
	{	
		//cout << "N ";						//showing null , no data
	}
	inOrder(2 * i + 2);						//right subtree
}

template<class T>
void BTree<T>::levelOrder()
{
	/*
	* function display tree nodes using levelOrder Traversal.
	* arguments: required for recursive call
	* return: nothing
	*/
	//cout << "levelOrder func\n";
	int n = (pow(2, height) - 1);
	for (int i = 0; i < n; i++)
	{
		if (status[i])
			cout << data[i] << " ";
		else
		{
			//cout << "N ";					//showing null , no data
		}
	}
}

template<class T>
void BTree<T>::displayAncestors(T node)
{
	/*
	* function displays ancestors of given node upto root node
	* arguments: node of which ancestors we want to see
	* return: nothing
	*/
	//cout << "display Ancestors\n";
	//ansestors of a node is path from that node to root node(excluding that node)
	int n = (pow(2, height) - 1);
	int i;								
	for (i = 0; i < n; i++)
	{
		if (data[i] == node)				//first we need to know the index of that node
			break;
	}
	int pi = getParent(i);					//now get first parent of that node
	while (pi > 0)							//while we reach at root
	{
		cout << data[pi] << " ";
		pi = getParent(pi);
	}
	cout << data[0] << " ";					
}

template<class T>
void BTree<T>::displayDescendents(T node)
{
	/*
	* function displays descendents of given node upto leaf nodes
	* arguments: node to see descendents
	* return: nothing
	*/
	//cout << "display descendants\n";
	//descendents of a node are  its left and right subtrees (all)
	int n = (pow(2, height) - 1);
	int i;								
	for (i = 0; i < n; i++)
	{
		if (data[i] == node)				//first we need to know the index of that node
			break;
	}
	inOrder(i * 2 + 1);						//print node's left subtree
	inOrder(i * 2 + 2);						//print node's right subtree
}

template<class T>
bool BTree<T>::isPerfectTree()
{
	/*
	* function returns true if the tree is perfect, otherwise false
	* arguments: no
	* return: true / false
	*/
	int n = (pow(2, height) - 1);
	for (int i = 0; i < n; i++)
	{
		if (status[i] == false)				//if any node missing/child missing
			return false;
	}
	return true;
}

template<class T>
bool BTree<T>::isCompleteTree()
{
	/*
	* function returns true if the tree is complete, otherwise false
	* arguments: no
	* return: true / false
	*/
	int n = (pow(2, height) - 1);
	int i;									//i will store index of first valid NULL value in status array
	int LLNodes = pow(2, height - 1);		//max # of nodes in last level (height = last level #)
	for (i = 0; i < n; i++)
	{
		if (status[i] == false && i < n - LLNodes)	//some level before last level is not full (not allow)
			return false;
		if (status[i] == false && i >= n - LLNodes)	//last level is not full (allowed)
			break;
	}
	for (int j = i; j < n; j++)
	{
		if (status[j] == true)				//after 1st null value in last level, next all values must null
			return false;					//to ensure last keys as left as possible
	}
	return true;							//if complete tree all conditions satisfyy
}

template<class T>
bool BTree<T>::isFullTree()
{
	/*
	* function returns true if the tree is full, otherwise false
	* arguments: no
	* return: true / false
	*/
	int n = (pow(2, height) - 1);
	int left, right;
	for (int i = 0; i < n; i++)
	{
		left = getLeftChild(i);
		right = getRightChild(i);
		if (status[left] != status[right])	  // not allow 1 child, only zero or 2
			return false;
	}
	return true;
}