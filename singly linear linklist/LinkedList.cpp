#include "LinkedList.h"

template<typename T>
LinkedList<T>::LinkedList() :head(NULL), tail(NULL)
{
	/*
	* default constructor initializes head and tail pointers to NULL
	* arguments: no
	* return: nothing
	*/
	//cout << "\ndefaultConstructor fun visited\n";
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList& obj)
{
	/*
	* copy constructor initializes object with an existing object
	* arguments: existing object to be copied
	* return: nothing
	*/
	//cout << "\ncopyConstructor fun visited\n";

	Node<T>* temp = obj.head;
	while (temp)
	{
		//creating newNodes for newlist to copy
		insertAtTail(temp->data);				//bydefault insert at tail
		temp = temp->next;
	}
}

template<typename T>
bool LinkedList<T>::isEmpty()
{
	/*
	* function tells whether list is empty (zero nodes) or not, upon calling
	* arguments: no
	* return: nothing
	*/
	//cout << "\nisEmpty fun visited\n";

	return head == NULL;
}

template<typename T>
void LinkedList<T>::insertAtHead(T value)
{
	/*
	* function, upon calling, inserts an element(node) at the start of list
	* arguments: value/data to be inserted in newnode
	* return: nothing
	*/
	//cout << "\ninsertAtHead fun visited\n";

	Node<T>* newNode = new Node<T>(value);
	if (isEmpty())
	{
		head = tail = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
}

template<typename T>
void LinkedList<T>::insertAtTail(T value)     //by default we insert elements at tail
{
	/*
	* function, upon calling, inserts an element(node) at the end of list
	* arguments: value/data to be inserted in newnode
	* return: nothing
	*/
	//cout << "\ninsertAtTAil fun visited\n";

	Node<T>* newNode = new Node<T>(value);
	if (isEmpty())
	{
		head = tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
}

template<typename T>
bool LinkedList<T>::deleteAtHead()
{
	/*
	* function deletes/removes the very first node from list
	* arguments: no
	* return: false if list was empty & true if element deleted
	*/
	//cout << "\ndeleteAtHead fun visited\n";

	if (!isEmpty())
	{
		Node<T>* temp = head;
		head = head->next;			//now head is next element
		delete temp;
		if (isEmpty())
			tail = NULL;
		return true;
	}
	else
		return false;
}

template<typename T>
bool LinkedList<T>::deleteAtTail()
{
	/*
	* function deletes/removes the very last node from list
	* arguments: no
	* return: false if list was empty & true if element deleted
	*/
	//cout << "\ndeleteAtTAil fun visited\n";

	if (!isEmpty())
	{
		if (head == tail)				//if only one node was in list
		{
			delete tail;
			head = tail = NULL;
		}
		else
		{
			Node<T>* temp = tail;
			Node<T>* h = head;
			while (h->next->next)		//reaching at 2nd last element
			{
				h = h->next;
				//hh = h->next;
			}
			tail = h;					//2nd last element is tail now...
			tail->next = NULL;
			delete temp;				//deleted last element
		}
		return true;
	}
	else
		return false;					//nothing in list to delete
}

template<typename T>
bool LinkedList<T>::Delete(T key)
{
	/*
	* function deletes/removes the node matches with 'key'
	* arguments: key to be matched
	* return: true if key found & false if not
	*/
	//cout << "\ndelete fun visited\n";

	if (!isEmpty())
	{
		Node<T>* found = search(key);		//search that node
		if (found)
		{
			if (found == head)
				deleteAtHead();		
			else if (found == tail)
				deleteAtTail();
			else
			{
				Node<T>* h = head;
				while (h->next != found)	//reach at element previous to 'found' 
				{
					h = h->next;
				}
				h->next = found->next;		//make new connection
				delete found;				//delete the founded element
			}
			return true;
		}
		else
			return false;					//cout << "Key not found\n";
	}
}

template<typename T>
void LinkedList<T>::printList()
{
	/*
	* function prints list's data from head(start) to tail(end)
	* arguments: no
	* return: nothing
	*/
	//cout << "\nprint fun visited\n";

	Node<T>* temp = head;					//to traverse through the list
	while (temp)							//until list ends(temp points NULL)
	{
		cout << temp->data << " --> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;					//last node's next ptr points at NULL
}

template<typename T>
LinkedList<T>::~LinkedList()
{
	/*
	* destructor deallocates heap memory allocated for linkList nodes
	* arguments: no
	* return: nothing
	*/
	//cout << "\ndestructor fun visited\n";

	Node<T>* temp = head;
	while (temp)
	{
		head = head->next;			//deleting each node one by one
		delete temp;
		temp = head;
	}
}


template<typename T>
Node<T>* LinkedList<T>::getHead()
{
	return head;
}
template<typename T>
Node<T>* LinkedList<T>::getTail()
{
	return tail;
}

template<typename T>
Node<T>* LinkedList<T>::getNode(int n)
{
	/*
	* function seraches for nth node in list and returns pointer to it,returns last node pointer if n>length
	* arguments: 'n' to search for nth node
	* return: pointer to nth node 
	*/
	//cout << "\ngetNode fun visited\n";
	int length = 0;
	Node<T>* c = head;
	while (c)
	{
		c = c->next;				//counting nodes
		length++;
	}
	if (n == length || n > length)
	{
		//cout << "temp data: " << tail->data << endl;
		return tail;				//returns last node pointer if n > length
	}
	else
	{
		Node<T>* temp = head;
		for (int i = 0; i < n - 1; i++)
		{
			temp = temp->next;
		}
		//cout << "temp data: " << temp->data << endl;
		return temp;
	}
}

template<typename T>
bool LinkedList<T>::insertBefore(T val, T key)
{
	/*
	* function inserts an element(node) before the node matched with 'key'
	* arguments: value/data to be inserted in newnode && key to be matched
	* return: true/false if key founds or not
	*/
	//cout << "\ninsertBefore fun visited\n";

	if (!isEmpty())
	{
		Node<T>* found = search(key);
		if (found)						//if key is matched with some node's data
		{
			if (found == head)
				insertAtHead(val);		//itself increment length
			else
			{
				Node<T>* newNode = new Node<T>(val);
				newNode->next = found;
				Node<T>* h = head;
				while (h->next != found)	
				{
					//reaching at element before 'found' to make its connection with newnode
					h = h->next;
				}
				h->next = newNode;		//new conection
			}
			return true;
		}
		else
			return false;
	}
}

template<typename T>
bool LinkedList<T>::insertAfter(T val, T key)
{
	/*
	* function inserts an element(node) after the node matched with 'key'
	* arguments: value/data to be inserted in newnode && key to be matched
	* return: true/false if key founds or not
	*/
	//cout << "\ninsertAfter fun visited\n";

	if (!isEmpty())
	{
		Node<T>* found = search(key);
		if (found)						//if key is matched with some node's data
		{
			Node<T>* newNode = new Node<T>(val);
			newNode->next = found->next;
			found->next = newNode;
			if (found == tail)			//move tail forward
				tail = newNode;
			return true;
		}
		else
			return false;				//cout << "Key Not found!" << endl;
	}
}

template<typename T>
bool LinkedList<T>::deleteBefore(T key)
{
	/*
	* function deletes/removes the node which comes before that matched key node
	* arguments: key to be matched
	* return: true if node found and false otherwise
	*/
	//cout << "\ndeleteBefore fun visited\n";

	if (!isEmpty())
	{
		Node<T>* found = search(key);		//search that node
		if (found)
		{
			if (found != head)				//no element exists previous to head
			{
				Node<T>* h = head;
				if (h->next == found)		//if key matches with node next to head, means here delete head
				{
					delete head;
					head = found;
				}
				else
				{
					while (h->next->next != found)	
					{
						//reaching at element previous to targeted (delete)node 
						h = h->next;
					}
					Node<T>* temp = h->next;
					h->next = found;			//new connection
					delete temp;
				}
			}
			return true;
		}
		else
			return false;						//cout << "Key not found\n";
	}
}

template<typename T>
bool LinkedList<T>::deleteAfter(T key)
{
	/*
	* function deletes/removes the node which comes after that matched key node
	* arguments: ley to be matched
	* return: true if node found and false otherwise
	*/
	//cout << "\ndeleteAfter fun visited\n";

	if (!isEmpty())
	{
		Node<T>* found = search(key);			//search that node
		if (found)
		{
			if (found != tail)					//no element exists next to tail
			{
				if (found->next == tail)
					tail = found;
				Node<T>* temp = found->next;	//next element to found is targeted element
				found->next = temp->next;		//made new connection
				delete temp;
			}
			return true;
		}
		else
			return false;						//cout << "Key not found\n";
	}
}

template<typename T>
int LinkedList<T>::getLength()
{
	/*
	* fuction tells total number of elments present in list
	* arguments: no
	* return: count of elements
	*/
	//cout << "\nlength fun visited\n";

	int length = 0;
	Node<T>* c = head;				//traverse through the list
	while (c)
	{
		c = c->next;
		length++;					//count nodes
	}
	return length;
}

template<typename T>
Node<T>* LinkedList<T>::search(T key)
{
	/*
	* function searches for matched 'key' element in the list upon calling
	* arguments: key to be matched
	* return: searched/matched element
	*/
	//cout << "\nsearch fun visited\n";

	Node<T>* temp = head;			//to traverse through the list
	while (temp)					//until list ends(temp points NULL)
	{
		if (temp->data == key)
		{
			//cout << "value is: " << temp->data << endl;
			return temp;
		}
		else
			temp = temp->next;
	}
	return NULL;					//if no such node exist having that 'key'
}