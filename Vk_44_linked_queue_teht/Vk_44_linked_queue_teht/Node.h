#pragma once
#include <iostream>
typedef int Node_entry;

using namespace std;

struct Node {
	//  data members
	Node_entry entry;
	Node *next;
	//  constructors
	Node();
	Node(Node_entry item, Node *add_on = NULL);
};
