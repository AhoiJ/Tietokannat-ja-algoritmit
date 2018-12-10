#pragma once
#include <iostream>
#include "Record.h"
#include "Node.h"

using namespace std;

template <class Record>
class Sortable_list :public List<Record> {
public:
	Sortable_list();
	void insertion_sort();
private: //  Add prototypes for auxiliary functions here.
};

template <class Record>
void Sortable_list<Record>::insertion_sort()
/*
Post: The entries of the Sortable_list have been rearranged so that
the keys in all the entries are sorted into nondecreasing order.
Uses: Methods for the class Record; the linked List implementation of Chapter 6.
*/
{
	Node <Record> *first_unsorted,  //  the first unsorted node to be inserted
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

template<class Record>
inline Sortable_list<Record>::Sortable_list()
{

}
