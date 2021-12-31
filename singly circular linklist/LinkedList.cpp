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
	* copy constructor initializes object that is to be initialized with an existing object
	* arguments: existing object to be copied
	* return: nothing
	*/
	//cout << "\ncopyConstructor fun visited\n";

	Node<T>* temp = obj.head;
	while (temp != obj.tail)
	{
		//creating newNodes for newlist to copy
		insertAtTail(temp->data);				//bydefault insert at tail
		temp = temp->next;
	}
	insertAtTail(temp->data);					//last node data
	tail->next = head;						//circular LL
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
	* function, upon calling, inserts an element(node) at the start of list & makes circular connection
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
	tail->next = head;
}

template<typename T>
void LinkedList<T>::insertAtTail(T value)     //by default we insert elements at tail
{
	/*
	* function, upon calling, inserts an element(node) at the end of list & makes circular connection
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
	tail->next = head;
}

template<typename T>
bool LinkedList<T>::deleteAtHead()
{
	/*
	* function deletes/removes the very first node from list, keep balance circular behave
	* arguments: no
	* return: false if list was empty & true if element deleted
	*/
	//cout << "\ndeleteAtHead fun visited\n";

	if (!isEmpty())
	{
		
		if (head == tail)		//in case of circular take care of NULL
		{
			delete head;
			head = tail = NULL;
		}
		else
		{
			Node<T>* temp = head;
			head = head->next;			//now head is next element
			delete temp;
			tail->next = head;		//circular behave
		}
		return true;
	}
	else
		return false;
}

template<typename T>
bool LinkedList<T>::deleteAtTail()
{
	/*
	* function deletes/removes the very last node from list, keep balance circular behave
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
			while (h->next != tail)		//reaching at 2nd last element
			{
				h = h->next;
			}
			tail = h;					//2nd last element is tail now...
			tail->next = head;			//circular behave
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
				deleteAtHead();				//itself balance circular behvae
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
	* function prints list's data from head(start) to tail(end), + first node data (to show circular LL)
	* arguments: no
	* return: nothing
	*/
	//cout << "\nprint fun visited\n";

	Node<T>* temp = head;					//to traverse through the list
	while (temp != tail)					//until list ends(temp points NULL)
	{
		cout << temp->data << " --> ";
		temp = temp->next;
	}
	cout << temp->data << " --> ";			//data of tail
	temp = temp->next;
	cout << temp->data << endl;				//data of first node, circular behave				
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
	while (temp != tail)
	{
		head = head->next;			//deleting each node one by one
		delete temp;
		temp = head;
	}
	delete temp;					//tail deleted
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
	while (c != tail)
	{
		length++;
		c = c->next;				//counting nodes
	}
	length++;					//last node count
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
				insertAtHead(val);		//itself check circular behave
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
		if (found)							//if key is matched with some node's data
		{
			Node<T>* newNode = new Node<T>(val);
			newNode->next = found->next;				//circular behave will set here
			found->next = newNode;
			if (found == tail)				//move tail forward
				tail = newNode;
			return true;
		}
		else
			return false;					//cout << "Key Not found!" << endl;
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
					deleteAtHead();
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
				if (found->next == tail)		//delete tail 
				{
					deleteAtTail();
				}
				else
				{
					Node<T>* temp = found->next;	//next element to found is targeted element
					found->next = temp->next;		//made new connection
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
	while (c != tail)
	{
		length++;					//count nodes
		c = c->next;
	}
	length++;
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
	while (temp != tail)			//until list ends(temp points NULL)
	{
		if (temp->data == key)
		{
			//cout << "value is: " << temp->data << endl;
			return temp;
		}
		else
			temp = temp->next;
	}
	if (temp->data == key)			//last node
		return temp;
	return NULL;					//if no such node exist having that 'key'
}