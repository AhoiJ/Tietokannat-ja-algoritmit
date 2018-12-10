#pragma once


template <class Node_entry>
struct Node {
	//  data members
	Node_entry entry;
	Node<Node_entry> *next;
	Node<Node_entry> *back;
	//  constructors
	Node();
	Node(Node_entry, Node<Node_entry> *link_back = NULL,
Node<Node_entry> *link_next = NULL);
	Node <List_entry> *set_position(int position) const;
};

template <class List_entry>
Node<List_entry>::Node()
{
	next = NULL;
	//back = NULL;
}

template <class Node_entry>
Node<Node_entry>::Node(Node_entry data, Node<Node_entry> *link_back, Node<Node_entry> *link_next)
{
	entry = data;
	next = link_next;
	back = link_back;
}

template<class Node_entry>
inline Node<List_entry>* Node<Node_entry>::set_position(int position) const
{
	Node <List_entry>*q = head;
	for (int i = 0; i < position; i++)
		q = q->next;
	return q;
}

