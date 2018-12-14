#pragma once

#include <iostream>
using namespace std;

template <class Node_entry>
struct NodeMerge {
	//  data members
	Node_entry entry;
	NodeMerge<Node_entry> *next;
	//  constructors
	NodeMerge();
	NodeMerge(Node_entry, NodeMerge<Node_entry> *link = NULL);
};

template<class Node_entry>
inline NodeMerge<Node_entry>::NodeMerge()
{
	next = NULL;
}

template<class Node_entry>
inline NodeMerge<Node_entry>::NodeMerge(Node_entry item, NodeMerge* add_on)
{
	entry = item;
	next = add_on;
}
