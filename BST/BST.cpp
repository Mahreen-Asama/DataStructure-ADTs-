#include "BST.h"

template<class T>
BST<T>::BST()
{
	/*
	* default constructor initializes root to NULL
	* arguments: no
	* return: nothing
	*/
	//cout << "\ndefaultConstructor fun visited\n";
	root = nullptr;
}

template<class T>
BST<T>::BST(T val)
{
	/*
	* parametized constructor is making root node and enters value to it
	* arguments: value to be set at root
	* return: nothing
	*/
	//cout << "\ncopyConstructor fun visited\n";
	root = new BSTNode<T>(val);
}

/*
template<class T>
void BST<T>::deleteBST(BSTNode<T>* root)
{

	//* function deletes left subtree, then right sbtree, then root throught RECURSION

	if (!root)
		return;
	deleteBST(root->left);
	deleteBST(root->right);
	delete root;
}
*/
template<class T>
BST<T>::~BST()
{
	/*
	* destructor will acting as wrapper fuction of above deleting function
	*/
	//cout << "tree destructor\n";
	//deleteBST(root);								//call to deleting function
	delete root;							//all nodes will automatically delete
}

template<class T>
BSTNode<T>* BST<T>::copyBST(BSTNode<T>* root_t1)
{
	if (!root_t1)						//link for help:http://www.cplusplus.com/forum/windows/59865/
		return nullptr;
	BSTNode<T>* temp = new BSTNode<T>(root_t1->data);
	temp->left = copyBST(root_t1->left);
	temp->right = copyBST(root_t1->right);
	return temp;
}
template<class T>
BST<T>::BST(const BST<T>& obj)
{
	//function is acting as a wrapper function to copy tree
	cout << "tree copy constructor\n";
	root = copyBST(obj.root);
}

template<class T>
void BST<T>::setRoot(T val)
{
	/*
	* functions makes root node and sets its value
	* arguments: value of root
	* return: nothing
	*/
	root = new BSTNode<T>(val);
}

template<class T>
BSTNode<T>* BST<T>::getRoot()
{
	//function returns pointer to root node
	return root;
}

template<class T>
void BST<T>::insert(T val)
{
	/*
	* function inserts given value inot tree by traversing through the whole tree,and places value where it
	  fits (not violate rules of BST)
	  arguments: value to be inserted
	  return: nothing
	*/
	if (!root)
	{
		root = new BSTNode<T>(val);
	}
	else
	{
		BSTNode<T>* temp = root;		//to traverse throught the tree
		BSTNode<T>* prev = temp;		//to preserve node at which val is to be inserted as child
		while (temp)
		{
			if (temp->data > val)		//go to left side
			{
				prev = temp;
				temp = temp->left;
			}
			else                        //if val>=data
			{
				prev = temp;
				temp = temp->right;
			}
		}
		if (prev->data > val)			//decide left/right child
			prev->left = new BSTNode<T>(val);
		else
			prev->right = new BSTNode<T>(val);
	}
}

template<class T>
BSTNode<T>* BST<T>::getLeftChild(BSTNode<T>* node)
{
	/*
	* function returns pointer to left child of passed node
	*/
	return node->left;
}

template<class T>
BSTNode<T>* BST<T>::getRightChild(BSTNode<T>* node)
{
	/*
	* function returns pointer to right child of passed node
	*/
	return node->right;
}

template<class T>
BSTNode<T>* BST<T>::search(T val)
{
	/*
	* function searches for given value in tree & returns ptr to it if found
	* arguments: value to be searched
	* return: nothing
	*/
	//cout << "\nsearch func\n";
	BSTNode<T>* temp = root;
	while (temp)
	{
		if (temp->data == val)
		{
			//cout << temp->data << endl;
			return temp;						//return that node
		}
		else
		{
			if (temp->data > val)
				temp = temp->left;
			else
				temp = temp->right;
		}
	}
	return temp;								//if that value not exist in tree, nullptr returns
}

template<class T>
void BST<T>::deleteNode(BSTNode<T>* node)
{
	/*
	* function deletes the node whhich is passed and replaces its place with some other node
	*/

	//As it's a BT, so, max degree of a node <=2, hence 4 cases will form 
	if (node == root)										//case 1, delete root of yr tree
	{
		cout << "\nroot deleted\n";
		/*
		root can also be delete here, we will make some other node as Root, some other node will be
		selected by choosing lasgest value from left subtree or smallest value from right subtree
		*/
		T value;
		if (node->left)
			value = findMax(node->left);
		else
			value = findMin(node->right);

		BSTNode<T>* valueNode = search(value);				//swapping them, just swap data
		valueNode->data = node->data;
		node->data = value;

		BSTNode<T>* n = search(valueNode->data);	  //search it and delete it, it has become degree 0 node now
		deleteNode(n);
		// a recursive call bcz may be, max/min vlaue nodes are of degree 1 or zero...
	}
	else if (node->left == nullptr && node->right == nullptr)	// case 1, degree of node =0
	{
		cout << "\ndegree 0 node deleted\n";
		BSTNode<T>* p = getParent(node);					//to set parent ptr to null
		if (p->left == node)								//if node was left child of p
			p->left = nullptr;
		else
			p->right = nullptr;
		delete node;
	}
	else if (node->left && node->right)						// case 3, degree of node=2
	{
		cout << "degree 2 node deleted\n";
		T value = findMax(node->left);						//get max value from left subtree
		BSTNode<T>* valueNode = search(value);
		valueNode->data = node->data;
		node->data = value;									//swap the data

		deleteNode(search(valueNode->data));			// a recursive call
	}
	else                                        // case 2, degree of node =1
	{
		cout << "\ndegree 1 node deleted\n";
		BSTNode<T>* child;								//get child of node
		if (node->left)
		{
			child = getLeftChild(node);
			cout << "\nleft child: " << child->data << endl;
		}
		else
		{
			child = getRightChild(node);
			cout << "\nright child: " << child->data << endl;
		}
		BSTNode<T>* parent = getParent(node);			//get parent of  node
		cout << "\nparent: " << parent->data << endl;

		if (parent->left == node)						//make direct connection of grandparent & child
		{
			parent->left = child;
			cout << "\nparent left data: " << parent->left->data << endl;

		}
		else
		{
			parent->right = child;
			cout << "\nparent right data: " << parent->right->data << endl;

		}
		delete node;
	}
}

template<class T>
void BST<T>::printNodes(BSTNode<T>* root)
{
	//it will act as a wrapper function to inorder traversal print
	inOrder(root);
}

template<class T>
bool BST<T>::isBST(BSTNode<T>* root)
{
	//Takes an Object of tree as a parameter and returns true if it is a BST, false otherwise.
	// we need to use some traversal 
	if (!root)
		return true;
	if (isBST(root->left) && isBST(root->right))
	{
		bool ch = true;
		if (root->left)
		{
			if (root->data > root->left->data)				//comparing BST condition
				ch = true;
			else
				ch = false;
		}
		if (root->right)
		{
			if (root->data <= root->right->data)			//comparing BST condition
				ch = true;
			else
				ch = false;
		}
		return ch;
	}
	else
		return false;
}

template<class T>
void BST<T>::printTree()
{
	//function prints tree in hierarchial format
}

template<class T>
bool BST<T>::isEqual(BSTNode<T>* r1, BSTNode<T>* r2)
{
	/*
	* function Takes roots of two trees and as input parameter and returns true if they are equal.
	*/
	if (r1 == nullptr && r2 == nullptr)
		return true;									//base case
	else if ((r1 == nullptr && r2 != nullptr) || (r1 != nullptr && r2 == nullptr))
		return false;									//means some extra node exist in either tree

	if ((isEqual(r1->left, r2->left)) && (isEqual(r1->right, r2->right)) && (r1->data == r2->data))
		return true;
	else
		return false;
}

template<class T>
bool BST<T>::isInternalNode(BSTNode<T>* node)
{
	/*
	* function Returns true if given node is an internal node.(degree >0)
	*/
	if (node->right || node->left)
		return true;
	else
		return false;
}

template<class T>
bool BST<T>::isExternalNode(BSTNode<T>* node)
{
	/*
	* function Returns true if given node is an external node.(degree =0)
	*/
	if (node->right == nullptr && node->left == nullptr)
		return true;
	else
		return false;
}

template<class T>
int BST<T>::findMaxHeight(int h1, int h2)
{
	if (h1 > h2)
		return h1;
	else
		return h2;
}
template<class T>
int BST<T>::getHeight(BSTNode<T>* root)
{
	/*
	* function Returns the height of tree.
	* return the maxmm of the height of the left and right sub-trees, plus 1 to account for the current node
	*/
	if (!root)
		return 0;
	return findMaxHeight(getHeight(root->left), getHeight(root->right)) + 1;
	//link : https://www.educative.io/edpresso/how-to-find-the-height-of-a-binary-tree
}

template<class T>
void BST<T>::displayDescendents(T val)
{
	/*
	* function displays descendants of given node's value
	* arguments: node value
	* return: nothing
	*/
	BSTNode<T>* node = search(val);
	if (node)							//if value found
	{
		levelOrder(node->left);			//display left subtree
		levelOrder(node->right);		//display right subtree
	}
}

template<class T>
void BST<T>::displayAncestors(T val)
{
	/*
	* function displays ancestors of given node's value
	* arguments: node value
	* return: nothing
	*/
	BSTNode<T>* node = search(val);
	if (node != root)
	{
		BSTNode<T>* p = getParent(node);				//searching above and above parents
		while (p != root)
		{
			cout << p->data << " ";
			p = getParent(p);
		}
		cout << p->data << " ";							//display root at end
	}
}

template<class T>
BST<T> BST<T>::getMirror(BSTNode<T>* root)
{
	/*
	* function returns the mirror image of *this tree (using recursion)
	* arguments: root of tree
	* return: mirror image
	*/
	if (!root)
		return *this;							//base case
	getMirror(root->left);
	getMirror(root->right);
	if (root->left || root->right)
	{
		BSTNode<T>* temp = root->right;
		root->right = root->left;
		root->left = temp;
	}
	return *this;
}

template<class T>
int BST<T>::getNodeCount(BST<T>* tree)
{
	/*
	* function Return the number of nodes in given tree (using recursion)
	*/
	if (!tree)
		return 0;
	return getNodeCount(tree->root->left) + getNodeCount(tree->root->right) + 1;

	// ptr pointing to a tree -> contains address of root of tree(1st data member)
	// count leftsubtree nodes + rightsubtree nodes + root(1)
}

template<class T>
T BST<T>::findMin(BSTNode<T>* root)
{
	/*
	* function returns minimum value of tree (using recusrsion)
	*/
	BSTNode<T>* temp = root;
	BSTNode<T>* prev = temp;
	while (temp)
	{
		prev = temp;						//left most leaf is min value
		temp = temp->left;
	}
	return prev->data;
}

template<class T>
T BST<T>::findMax(BSTNode<T>* root)
{
	/*
	* function returns maximum value of tree (using recusrsion)
	*/
	BSTNode<T>* temp = root;
	BSTNode<T>* prev = temp;
	while (temp)
	{
		prev = temp;							//right most leaf is max value
		temp = temp->right;
	}
	return prev->data;
}

template<class T>
void BST<T>::inOrder(BSTNode<T>* root)			// L V R
{
	// function displays inOrder traversal of BST through recursion 
	if (!root)									//base case
		return;
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}

template<class T>
void BST<T>::preOrder(BSTNode<T>* root)			// V L R
{
	// function displays preOrder traversal of BST through recursion 
	if (!root)									//base case
		return;
	cout << root->data << " ";
	inOrder(root->left);
	inOrder(root->right);
}

template<class T>
void BST<T>::postOrder(BSTNode<T>* root)		// L R V
{
	// function displays postOrder traversal of BST through recursion 
	if (!root)									//base case
		return;
	inOrder(root->left);
	inOrder(root->right);
	cout << root->data << " ";
}

template<class T>
void BST<T>::levelOrder(BSTNode<T>* root)
{
	//function acts as a wrapper function to printn levels of tree
	int h = getHeight(root);
	int i;
	for (i = 1; i <= h; i++)
		printCurrentLevel(root, i);
}
template<class T>
void BST<T>::printCurrentLevel(BSTNode<T>* root, int level)
{
	/*
	function Prints all nodes at a current level (throough recursion)
	*/
	if (root == nullptr)
		return;
	if (level == 1)
		cout << root->data << " ";
	else if (level > 1)
	{
		printCurrentLevel(root->left, level - 1);
		printCurrentLevel(root->right, level - 1);
	}
}

template<class T>
BSTNode<T>* BST<T>::getParent(BSTNode<T>* node)
{
	//function return ptr to parent of passed node
	BSTNode<T>* temp = root;
	BSTNode<T>* prev = temp;
	while (temp)
	{
		if (temp == node)
			return prev;						//prev is parent
		else
		{
			prev = temp;						//storing prev node
			if (temp->data > node->data)
				temp = temp->left;
			else
				temp = temp->right;
		}
	}
	return prev;
}

