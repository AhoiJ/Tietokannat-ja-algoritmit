#pragma once
#include "Utility.h"

template <class Node_entry>struct Node {	//  data members	Node_entry entry;	Node<Node_entry> *next;	//  constructors	Node();	Node(Node_entry, Node<Node_entry> *link = NULL);};

template <class ListQ_entry>
class ListQ {
public:
	//  methods of the List ADT
	ListQ();
	int size() const;
	bool full() const;
	bool empty() const;
	void clear();
	void traverse(void(*visit)(ListQ_entry &));
	Error_code retrieve(int position, ListQ_entry &x) const;
	Error_code replace(int position, const ListQ_entry &x);
	Error_code remove(int position, ListQ_entry &x);
	Error_code insert(int position, const ListQ_entry &x);

protected:
	//  data members for a contiguous list implementation
	int count;
	ListQ_entry entryQ[max_list];
};
