#pragma once

#include "ListMerge.h"

template <class Record>
class Sortable_list_merge :public ListMerge<Record> {
public:
	void insertion_sort();
	void selection_sort();
	void merge_sort();
	
	NodeMerge<Record> *Sortable_list_merge<Record>::divide_from(NodeMerge<Record> *sub_list);
	NodeMerge<Record> *Sortable_list_merge<Record>::merge(NodeMerge<Record> *first, NodeMerge<Record> *second);
	

private: //  Add prototypes for auxiliary functions here.
	int max_key(int low, int high);
	void swap(int low, int high);
	void recursive_merge_sort(NodeMerge<Record> *&sub_list);

};


template <class Record>
void Sortable_list_merge<Record>::insertion_sort()
/*
Post: The entries of the Sortable_list have been rearranged so that
the keys in all the entries are sorted into nondecreasing order.
Uses: Methods for the class Record; the linked List implementation of Chapter 6.
*/
{
	NodeMerge <Record> *first_unsorted,  //  the first unsorted node to be inserted
		*last_sorted,     //  tail of the sorted sublist
		*local_current,         //  used to traverse the sorted sublist
		*trailing;        //  one position behind current

	if (current != NULL) {          //  Otherwise, the empty list is already sorted.
		last_sorted = current;       //  The first node alone makes a sorted sublist.
		while (last_sorted->next != NULL) {
			first_unsorted = last_sorted->next;
			if (first_unsorted->entry < current->entry) {
				//  Insert *first_unsorted at the head of the sorted list:
				last_sorted->next = first_unsorted->next;
				first_unsorted->next = current;
				current = first_unsorted;
			}
			else {
				//  Search the sorted sublist to insert *first_unsorted:
				trailing = current;
				local_current = trailing->next;
				while (first_unsorted->entry > local_current->entry) {
					trailing = local_current;
					local_current = trailing->next;
				}

				//  *first_unsorted now belongs between *trailing and *current.

				if (first_unsorted == local_current)
				{
					last_sorted = first_unsorted;  //  already in right position
				}

				else
				{
					last_sorted->next = first_unsorted->next;
					first_unsorted->next = local_current;
					trailing->next = first_unsorted;
				}
			}
		}
	}
}



template <class Record>
void Sortable_list_merge<Record>::selection_sort()
{
	for (int position = count - 1; position > 0; position--) {
		int max = max_key(0, position);
		swap(max, position);
	}
}


template <class Record>
int Sortable_list_merge<Record>::max_key(int low, int high)
/*
Pre:  low and high are valid positions in the Sortable_list and low <= high.
Post: The position of the entry between low and high with the largest
key is returned.
Uses: The class Record, the contiguous List implementation of Chapter 6.
*/
{
	int largest, current;
	largest = low;
	for (current = low + 1; current <= high; current++)
		if (entry[largest] < entry[current])
			largest = current;
	return largest;
}

template <class Record>
void Sortable_list_merge<Record>::swap(int low, int high)
{
	Record temp;
	temp = entry[low];
	entry[low] = entry[high];
	entry[high] = temp;
}


// MERGESORT
template <class Record>
void Sortable_list_merge<Record>::merge_sort()
//Post: The entries of the sortable list have been rearranged so that
//their keys are sorted into nondecreasing order.
//Uses: The linked List implementation of Chapter 6 and recursive_merge_sort.
{
	recursive_merge_sort(this->head); // Mik� t�m� head????
}

template <class Record>
void Sortable_list_merge<Record>::recursive_merge_sort(NodeMerge<Record> *&sub_list)

//Post: The nodes referenced by sub_list have been rearranged so that their
//keys are sorted into nondecreasing order.  The pointer parameter
//sub_list is reset to point at the node containing the smallest key.
//Uses: The linked List implementation of Chapter 6;
//the functions divide_from, merge, and recursive_merge_sort.

{
	if (sub_list != NULL && sub_list->next != NULL) {
		NodeMerge<Record> *second_half = divide_from(sub_list);
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
NodeMerge<Record> *Sortable_list_merge<Record>::divide_from(NodeMerge<Record> *sub_list)
{
	NodeMerge<Record> *position, //  traverses the entire list
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
NodeMerge<Record> *Sortable_list_merge<Record>::merge(NodeMerge<Record> *first, NodeMerge<Record> *second)
{
	NodeMerge<Record> *last_sorted; //  points to the last node of sorted list
	NodeMerge<Record> combined;     //  dummy first node, points to merged list

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
	if (first == NULL)
		last_sorted->next = second;
	else
		last_sorted->next = first;
	return combined.next;
}

