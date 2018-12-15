/*
ListMerge.h
=============
*/
#pragma once
#include "NodeMerge.h"
#include "Utility.h"
#include "Record.h"

typedef int index;
const int max_list = 1000;

template <class List_entry>
class ListMerge
{
public:
	ListMerge();

	int size() const;
	//bool full() const;
	//bool empty() const;
	void clear();
	//void traverse(void(*visit)(List_entry &));
	Error_code retrieve(int position, List_entry &x) const;
	//Error_code replace(int position, const List_entry &x);
	//Error_code remove(int position, List_entry &x);
	Error_code insert(int position, const List_entry &x);

	~ListMerge();
//	List_node(const List_node<List_entry> &copy);
//	void operator =(const List_node<List_entry> &copy);
	
	// Mergesort
	Error_code ListMerge<List_entry>::insertM(int position, const List_entry &x);
	NodeMerge<List_entry> *ListMerge<List_entry>::set_pos(int position) const;

	

protected:
	int count;
	//List_entry entry[max_list];
	mutable int current_position;
	NodeMerge<List_entry> *head;
	mutable NodeMerge<List_entry> *current;

	//  The following auxiliary function is used to locate list positions
	NodeMerge<List_entry> *set_position(int position) const;

};

template<class List_entry>
inline int ListMerge<List_entry>::size() const
{
	return count;
}

template <class List_entry>
Error_code ListMerge<List_entry>::retrieve(int position, List_entry &x) const
{
	NodeMerge<List_entry> *current;
	if (position < 0 || position >= count)
	{
		return utility_range_error;
	}
	current = set_position(position);
	set_position(position);
	x = current->entry;
	return success;
}

template <class List_entry>
Error_code ListMerge<List_entry>::insert(int position, const List_entry &x)

//Post: If the List is not full and 0 <= position <= n,
//where n is the number of entries in the List, the function succeeds:
//Any entry formerly at position and all later entries have their position
//numbers increased by 1, and x is inserted at position of the List.
//Else: The function fails with a diagnostic error code.

{
	if (position < 0 || position > count)
		return utility_range_error;
	NodeMerge<List_entry> *new_node, *previous, *following;
	previous = NULL;
	if (position > 0) {
		previous = set_position(position - 1); // vaihdettu 1 rivi ylös
		following = previous->next;
	}
	else following = head;
	new_node = new NodeMerge<List_entry>(x, following);
	if (new_node == NULL)
		return overflow;
	if (position == 0)
		head = new_node;
	else
		previous->next = new_node;
	count++;
	return success;
}


template <class List_entry>
NodeMerge<List_entry> *ListMerge<List_entry>::set_position(int position) const

//Pre:  position is a valid position in the List; 0 <= position < count.
//Post: Returns a pointer to the Node in position.

{
	NodeMerge<List_entry> *q = head;
	for (int i = 0; i < position; i++) q = q->next;
	return q;
}

template <class List_entry>
void ListMerge<List_entry>::clear()
{
	;
}

template <class List_entry>
ListMerge<List_entry>::~ListMerge()
{
	;
}

template <class List_entry>
ListMerge<List_entry>::ListMerge()
{
	this->count = 0;
	this->current_position = -1;
	this->head = NULL;
	this->current = NULL;
}

/*
//		INDEX JUTTUJA
template <class List_entry>
index ListMerge<List_entry>::new_node()

//Post: The index of the first available Node in workspace is returned;
//the data members available, last_used, and workspace are updated
//as necessary.If the work - space is already full, -1 is returned.

{
	index new_index;

	if (available != -1) {
		new_index = available;
		available = workspace[available].next;
	}
	else if (last_used < max_list - 1) {
		new_index = ++last_used;
	}
	else return -1;
	workspace[new_index].next = -1;
	return new_index;
}
*/
/*
template <class List_entry>
void ListMerge<List_entry>::delete_node(index old_index)

//Pre:  The List has a Node stored at index old_index.
	//Post : The List index old_index is pushed onto the linked stack
	//of available space; available, last_used, and workspace are
	//updated as necessary.

{
	index previous;
	if (old_index == head) head = workspace[old_index].next;
	else {
		previous = set_position(current_position(old_index) - 1);
		workspace[previous].next = workspace[old_index].next;
	}
	workspace[old_index].next = available;
	available = old_index;
}
*/
/* INDEX JUTTUJA LOPPU		*/

// Mergesort

template <class List_entry>
NodeMerge<List_entry> *ListMerge<List_entry>::set_pos(int position) const

//Pre:  position is a valid position in the List; 0 <= position < count.
//Post: Returns a pointer to the Node in position.

{
	NodeMerge<List_entry> *q = head;
	for (int i = 0; i < position; i++) q = q->next;
	return q;
}


template <class List_entry>
Error_code ListMerge<List_entry>::insertM(int position, const List_entry &x)

//Post: If the List is not full and 0 <= position <= n,
//where n is the number of entries in the List, the function succeeds:
//Any entry formerly at position and all later entries have their position
//numbers increased by 1, and x is inserted at position of the List.
//Else: The function fails with a diagnostic error code.

{
	if (position < 0 || position > count)
		return utility_range_error;
	NodeMerge<List_entry> *new_node, *previous, *following;
	if (position > 0) {
		previous = set_position(position - 1);
		following = previous->next;
	}
	else following = head;
	new_node = new NodeMerge<List_entry>(x, following);
	if (new_node == NULL)
		return overflow;
	if (position == 0)
		head = new_node;
	else
		previous->next = new_node;
	count++;
	return success;
}
/*
template <class Record>
void ListMerge<Record>::merge_sort()
//Post: The entries of the sortable list have been rearranged so that
//their keys are sorted into nondecreasing order.
//Uses: The linked List implementation of Chapter 6 and recursive_merge_sort.
{
	recursive_merge_sort(head);
}

template <class Record>
void ListMerge<Record>::recursive_merge_sort(Node<Record> *&sub_list) // Ei sortable list

//Post: The nodes referenced by sub_list have been rearranged so that their
//keys are sorted into nondecreasing order.  The pointer parameter
//sub_list is reset to point at the node containing the smallest key.
//Uses: The linked List implementation of Chapter 6;
//the functions divide_from, merge, and recursive_merge_sort.

{
	if (sub_list != NULL && sub_list->next != NULL) {
		Node<Record> *second_half = divide_from(sub_list);
		recursive_merge_sort(sub_list);
		recursive_merge_sort(second_half);
		sub_list = merge(sub_list, second_half);
	}
}

//Post: The list of nodes referenced by sub_list has been reduced
//to its first half, and a pointer to the first node in the second half
//of the sublist is returned.  If the sublist has an odd number of
//entries, then its first half will be one entry larger than its second.
//Uses: The linked List implementation of Chapter 6.


template <class Record>
Node<Record> *ListMerge<Record>::divide_from(Node<Record> *sub_list)
{
	Node<Record> *position, //  traverses the entire list
		*midpoint, //  moves at half speed of position to midpoint
		*second_half;

	if ((midpoint = sub_list) == NULL) return NULL;  //  List is empty.
	position = midpoint->next;
	while (position != NULL) { //  Move position twice for midpoint's one move.
		position = position->next;
		if (position != NULL) {
			midpoint = midpoint->next;
			position = position->next;
		}
	}
	second_half = midpoint->next;
	midpoint->next = NULL;
	return second_half;
}


//Pre:  first and second point to ordered lists of nodes.
//Post: A pointer to an ordered list of nodes is returned.
//The ordered list contains all entries that were referenced by
//first and second.  The original lists of nodes referenced
//by first and second are no longer available.
//Uses: Methods for Record class; the linked List implementation of Chapter 6.


template <class Record>
Node<Record> *ListMerge<Record>::merge(Node<Record> *first, Node<Record> *second)
{
	Node <Record> *last_sorted; //  points to the last node of sorted list
	Node <Record> combined;     //  dummy first node, points to merged list

	last_sorted = &combined;
	while (first != NULL && second != NULL) { //  Attach node with smaller key
		if (first->entry <= second->entry) {
			last_sorted->next = first;
			last_sorted = first;
			first = first->next;   //  Advance to the next unmerged node.
		}
		else {
			last_sorted->next = second;
			last_sorted = second;
			second = second->next;
		}
	}

	//  After one list ends, attach the remainder of the other.
	if (first == NULL) {
		last_sorted->next = second;
	}
	else
		last_sorted->next = first;
	return combined.next;
}
*/