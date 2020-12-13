#ifndef doublyList_h
#define doublyList_h
using namespace std;


//LIST
template <typename T>
class doublyList
{
	//NODE
	struct doublyNode
	{
		T data;
		doublyNode* next;
		doublyNode* prev;
	};
	
public:
	
	/* _______________________________________________________________
	Post-condition: The default constructor intializes head, tail,
	iterator, newNode and count.
	 _______________________________________________________________*/
	doublyList():head{NULL},tail{NULL},iterator{NULL},newNode{NULL},count{new int{0}}{};//default constructor
	
	/* _______________________________________________________________
	Post-condition: A new doubly list is created as a copy of the
	other list that was past into the copy constructor. This makes
	a deep copy of the list by copying hte pointed to data as well
	_______________________________________________________________*/
	doublyList(const doublyList<T>& otherList); 	       //copy constructor
	
	/* _______________________________________________________________
	 Pre-condition: a list that could have any amount of data in it
	 Post-condition: the initial list is deleted is assigned all of the
	 values of the list given on the right hand side.
	 _______________________________________________________________*/
	void operator=(const doublyList<T> &);
	
	/* _______________________________________________________________
	Post-condition: a node is added to List with given data.
	_______________________________________________________________*/
	void addNode(T data);
	
	/* _______________________________________________________________
	Post-condition: returns if list is empty
	_______________________________________________________________*/
	bool isEmpty();
	
	/* _______________________________________________________________
	Post-condition: prints the contents of the list
	_______________________________________________________________*/
	void printList();
	
	/* _______________________________________________________________
	Post-condition: returns the count of the list
	_______________________________________________________________*/
	int Count() const;
	
	/* _______________________________________________________________
	 
	 Post-condition: returns a list that is the reverse of the list
	 that calls reverse.
	_______________________________________________________________*/
	doublyList<T> reverse();
	
	/* _______________________________________________________________
	 Pre-condition: a list where the value is not yet deleted.
	 Post-condition: searches for given value and deletes the node
	 where that calue is.
	_______________________________________________________________*/
	void deleteNode(T valToDelete);
	
	/* _______________________________________________________________
	 Post-condition: iterates to the middle of the list and then
	 puts a new node with valToPut in that node
	_______________________________________________________________*/
	void putInMiddle(T valToPut);
	
protected:
	doublyNode* newNode;
	doublyNode* head;
	doublyNode* tail;
	doublyNode* iterator;
		
private:
	void copyList(const doublyList<T>& otherList);
	int* count;
};


//copy constructor
template <typename T>
doublyList<T>::doublyList(const doublyList<T>& otherList)
{
	doublyNode* current;
	count = new int;
	*count = otherList.Count();
	current = otherList.tail;
	head = NULL;
	tail = NULL;
	
	//going from tail so that it stays in correct order
	while(current != NULL)
	{
		addNode(current->data);
		current = current->prev;
	}
}

//overloaded assignment operator
template <typename T>
void doublyList<T>::operator=(const doublyList<T>& otherList)
{
	head = NULL;
	tail = NULL;
	doublyNode *nodePtr = otherList.head;
	doublyNode *trailingPtr = nodePtr;
	
    
	//adding data one by one from otherList
	//also making sure to delete the old node
	while(nodePtr != NULL)
	{
		addNode(nodePtr->data);
        nodePtr = nodePtr->next;
		delete trailingPtr;
		trailingPtr = nodePtr;
	}
}

//count getter
template <typename T>
 int doublyList<T>::Count() const
{
	return *count;
}

template <typename T>
void doublyList<T>::printList()
{
	if(isEmpty())
	{
		cout << "Can't print empty list" <<endl;
	}
	else
	{
	iterator = head;
	while(iterator != NULL)
	{
		cout << iterator->data << endl;
		iterator = iterator->next;
		
	}
	cout << endl;
	}
}

template <typename T>
void doublyList<T>::addNode(T indata)
{
	doublyNode* newNode = new doublyNode;
	newNode->data = indata;
	newNode->prev = NULL;
	newNode->next = NULL;
	
	if(head == NULL)
	{
		head = newNode;
		tail = newNode;
		newNode->next = NULL;
		newNode->prev = NULL;
	}
	else
	{
		head->prev    = newNode;
		newNode->next = head;
		newNode->prev = NULL;
		head = newNode;
	}
	++(*count);
	
}

template <typename T>
bool doublyList<T>::isEmpty()
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

template <typename T>
doublyList<T> doublyList<T>::reverse()
{
	doublyList<T> reverseList;
	reverseList.head = NULL;
	reverseList.tail = NULL;
	
	doublyNode* current = tail;
	
	while(current != NULL)
	{
		reverseList.addNode(current->data);
		current = current->prev;
	}
	return reverseList;
}

template <typename T>
void doublyList<T>::deleteNode(T valToDelete)
{
	if(isEmpty())
	{
		cout << "Cannot delete from empty list" << endl;
	}
	else
	{
		iterator = head;
		while(iterator != NULL)
		{
			if(iterator->data == valToDelete)
			{
				//last val
				if((iterator == head)&&(head->next == NULL))
				{
					delete iterator;
					head = NULL;
					tail = NULL;
				}
				//val at tail
				else if(iterator == tail)
				{
					tail = tail->prev;
				}
				//val at head
				else if(iterator == head)
				{
					head = head->next;
				}
				//val between head and tail
				else
				{
					iterator->next->prev  =  iterator->prev;
					iterator->prev->next  =  iterator->next;
				}
				--(*count);
				return;
			}
			iterator = iterator->next;
		}
		cout << "Node to be deleted does not exist" << endl;
	}
}

template <typename T>
void doublyList<T>::putInMiddle(T valToPut)
{
	int mid = ((*count-1)/2);
	
	if(isEmpty()||head->next == NULL)
	{
		addNode(valToPut);
	}
	else
	{
		iterator = head;
		int i = 0;
		
		doublyNode* newNode = new doublyNode;
		newNode->data = valToPut;
		
		while(iterator != NULL)
		{
			if(i == mid)
			{
				newNode->next = iterator->next;
				iterator->next = newNode;
				return;
			}
			++i;
			iterator = iterator->next;
		}
	}
}


#endif /* doublyList_h */
