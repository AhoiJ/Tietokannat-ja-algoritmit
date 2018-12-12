#pragma once
#include <iostream>

using namespace std;

template <class Node_entry>
struct Node {
	//  data members
	//index next;
	Node_entry entry;
	Node<Node_entry> *next;
	Node<Node_entry> *back;
	//  constructors
	Node();
	Node(Node_entry, Node<Node_entry> *link_back = NULL,
				Node<Node_entry> *link_next = NULL);
	
};

template <class List_entry>
Node<List_entry>::Node()
{
	next = NULL;
	back = NULL;
}

template <class Node_entry>
Node<Node_entry>::Node(Node_entry data, Node<Node_entry> *link_back, Node<Node_entry> *link_next)
{
	entry = data;
	next = link_next;
	back = link_back;
}


