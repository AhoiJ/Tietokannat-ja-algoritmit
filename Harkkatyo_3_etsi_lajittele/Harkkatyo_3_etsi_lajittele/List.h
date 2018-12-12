#pragma once
#include "Node.h"
#include "Utility.h"

const int max_list = 1000;
typedef int index;

template <class List_entry>
class List {
public:
	//  Specifications for the methods of the list ADT go here.

	List();
	int size() const;
	bool full() const;
	bool empty() const;
	void clear();
	void traverse(void(*visit)(List_entry &));
	Error_code retrieve(int position, List_entry &x) const;
	Error_code replace(int position, const List_entry &x);
	Error_code remove(int position, List_entry &x);
	Error_code insert(int position, const List_entry &x);

	Node <List_entry> *head;

	//  The following methods replace compiler-generated defaults.
	~List();
	List(const List<List_entry> &copy);
	void operator =(const List<List_entry> &copy);
protected:
	//  Data members for the linked list implementation now follow.
	Node<List_entry> workspace[max_list];//种种
	index available, last_used, hedu;//种种

	int count;
	mutable int current_position;
	mutable Node<List_entry> *current;
	List_entry entry[max_list];

	//  The following auxiliary function is used to locate list positions
	void set_position(int position) const;

	// Mergesort functions
	Node<List_entry> *set_pos(int position) const;
	Error_code List<List_entry>::insertM(int position, const List_entry &x);
	/*
	// Index juttuja
	index new_node();	void delete_node(index n);	int current_position(index n) const;	index set_posIndex(int position) const;
	*/

};

/*		INDEX JUTTUJA	
template <class List_entry>index List<List_entry>::new_node()Post: The index of the first available Node in workspace is returned;the data members available, last_used, and workspace are updatedas necessary.  If the work-space is already full, -1 is returned.{	index new_index;	if (available != -1) {		new_index = available;		available = workspace[available].next;	}	else if (last_used < max_list - 1) {		new_index = ++last_used;	}	else return -1;	workspace[new_index].next = -1;	return new_index;}

template <class List_entry>void List<List_entry>::delete_node(index old_index)Pre:  The List has a Node stored at index old_index.Post: The List index old_index is pushed onto the linked stackof available space; available, last_used, and workspace areupdated as necessary.{	index previous;	if (old_index == head) head = workspace[old_index].next;	else {		previous = set_position(current_position(old_index) - 1);		workspace[previous].next = workspace[old_index].next;	}	workspace[old_index].next = available;	available = old_index;}

    INDEX JUTTUJA LOPPU		*/

template <class List_entry>
List<List_entry>::List()
/*

Post: The List is initialized to be empty.

*/

{
	count = 0;
	current = NULL;
	current_position = -1;
//	head = NULL;
}

template <class List_entry>
void List<List_entry>::clear()
/*
Post: The List is cleared.
*/

{
	Node<List_entry> *p, *q;
	if (current == NULL) return;

	for (p = current->back; p; p = q) {
		q = p->back;
		delete p;
	}
	for (p = current; p; p = q) {
		q = p->next;
		delete p;
	}
	count = 0;
	current = NULL;
	//current_position = -1;
}

template <class List_entry>
int List<List_entry>::size() const
/*
Post: The function returns the number of entries in the List.
*/
{
	return count;
}

template <class List_entry>
bool List<List_entry>::empty() const
/*
Post: The function returns true or false according as the List is empty or not.
*/
{
	return count <= 0;
}

template <class List_entry>
bool List<List_entry>::full() const
/*
Post: The function returns 1 or 0 according as the List is full or not.
*/
{
	return false;
}

template <class List_entry>
void List<List_entry>::traverse(void(*visit)(List_entry &))
/*

Post: The action specified by function (*visit) has been performed on every
entry of the List, beginning at position 0 and doing each in turn.

*/

{
	Node<List_entry> *to_visit = current;
	if (to_visit != NULL)
		for (; to_visit->back; to_visit = to_visit->back)
			;
	for (: to_visit; to_visit = to_visit->next)
		(*visit)(to_visit->entry);
}

template <class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry &x) const
/*
Post: If the List is not full and 0 <= position < n,
where n is the number of entries in the List,
the function succeeds:
The entry in position is copied to x.
Otherwise the function fails with an error code of range_error.
*/

{
	//Node<List_entry> *current;
	if (position < 0 || position >= count)
	{
		return utility_range_error;
	}
	//current = set_position(position);
	set_position(position);
	x = current->entry;
	return success;
}

template <class List_entry>
Error_code List<List_entry>::replace(int position, const List_entry &x)
/*
Post: If 0 <= position < n,
where n is the number of entries in the List,
the function succeeds:
The entry in position is replaced by x,
all other entries remain unchanged.
Otherwise the function fails with an error code of range_error.
*/

{
	if (position < 0 || position >= count) return utility_range_error;
	set_position(position);
	current->entry = x;
	return success;
}

/*

Post: If 0 <= position < n,
where n is the number of entries in the List,
the function succeeds:
The entry in position is removed
from the List, and the entries in all later positions
have their position numbers decreased by 1.
The parameter x records a copy of
the entry formerly in position.
Otherwise the function fails with a diagnostic error code.

*/

template <class List_entry>
Error_code List<List_entry>::remove(int position, List_entry &x)
{
	Node<List_entry> *old_node, *neighbor;
	if (count == 0) return fail;
	if (position < 0 || position >= count) return utility_range_error;
	set_position(position);
	old_node = current;
	if (neighbor = current->back) neighbor->next = current->next;
	if (neighbor = current->next) {
		neighbor->back = current->back;
		current = neighbor;
	}
	else {
		current = current->back;
		current_position--;
	}
	x = old_node->entry;
	delete [] old_node;
	count--;
	return success;
}

template <class List_entry>
List<List_entry>::~List()
/*
Post: The List is empty: all entries have been removed.
*/
{
//	clear();
}

template <class List_entry>
List<List_entry>::List(const List<List_entry> &copy)
/*
Post: The List is initialized to copy the parameter copy.
*/
{
	count = copy.count;
	current_position = copy.current_position;
	Node<List_entry> *new_node, *old_node = copy.current;

	if (old_node == NULL) current = NULL;
	else {
		new_node = current = new Node<List_entry>(old_node->entry);
		while (old_node->next != NULL) {
			old_node = old_node->next;
			new_node->next = new Node<List_entry>(old_node->entry,new_node);
			new_node = new_node->next;
		}
		old_node = copy.current;
		new_node = current;
		while (old_node->back != NULL) {
			old_node = old_node -> back;
			new_node->back = new Node<List_entry>(old_node->entry, NULL, new_node);
			new_node = new_node->back;
		}
	}
}

template <class List_entry>
void List<List_entry>::operator =(const List<List_entry> &copy)
/*
Post: The List is assigned to copy a parameter
*/
{
	List new_copy(copy);
	clear();
	count = new_copy.count;
	current_position = new_copy.current_position;
	current = new_copy.current;
	new_copy.count = 0;
	new_copy.current_position = 0;
	new_copy.current = NULL;
}

template <class List_entry>
void List<List_entry>::set_position(int position) const
/*
Pre:  position is a valid position in the List: 0 <= position < count.
Post: The current Node pointer references the Node at position.
*/
{
	
	if (current_position <= position)
		for (; current_position != position; current_position++)
			current = current->next;
	else
		for (; current_position != position; current_position--)
			current = current->back;
			

}


template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x)
/*
Post: If the List is not full and 0 <= position <= n,
where n is the number of entries in the List, the function succeeds:
Any entry formerly at position and all later entries have their
position numbers increased by 1 and x is inserted at position of the List.
Else: the function fails with a diagnostic error code.
*/
{
	Node<List_entry> *new_node, *following, *preceding;
	if (position < 0 || position > count) return utility_range_error;
	if (position == 0) {
		if (count == 0) following = NULL;
		else {
			set_position(0);
			following = current;
		}
		preceding = NULL;
	}
	else {
		set_position(position - 1);
		preceding = current;
		following = preceding->next;
	}
	new_node = new Node<List_entry>(x, preceding, following);

	if (new_node == NULL) return overflow;
	if (preceding != NULL) preceding->next = new_node;
	if (following != NULL) following->back = new_node;
	current = new_node;
	current_position = position;
	count++;
	return success;
}
/*
template<class List_entry>
inline Node<List_entry>* List<List_entry>::set_position(int position) const
{
	Node <List_entry>*q = head;
	for (int i = 0; i < position; i++)
		q = q->next;
	return q;
}
*/

// Mergesort

template <class List_entry>
Node<List_entry> *List<List_entry>::set_pos(int position) const
/*
Pre:  position is a valid position in the List; 0 <= position < count.
Post: Returns a pointer to the Node in position.
*/
{
	Node<List_entry> *q = head;
	for (int i = 0; i < position; i++) q = q->next;
	return q;
}

template <class List_entry>
Error_code List<List_entry>::insertM(int position, const List_entry &x)
/*
Post: If the List is not full and 0 <= position <= n,
where n is the number of entries in the List, the function succeeds:
Any entry formerly at position and all later entries have their position
numbers increased by 1, and x is inserted at position of the List.
Else: The function fails with a diagnostic error code.
*/
{
	if (position < 0 || position > count)
		return range_error;
	Node<List_entry> *new_node, *previous, *following;
	if (position > 0) {
		previous = set_position(position - 1);
		following = previous->next;
	}
	else following = head;
	new_node = new Node<List_entry>(x, following);
	if (new_node == NULL)
		return overflow;
	if (position == 0)
		head = new_node;
	else
		previous->next = new_node;
	count++;
	return success;
}
