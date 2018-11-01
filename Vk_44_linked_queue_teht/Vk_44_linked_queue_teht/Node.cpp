#include "Node.h"
#include <iostream>

using namespace std;

Node::Node()
{
	next = NULL;
}

Node::Node(Node_entry item, Node * add_on)
{
	entry = item;
	next = add_on;
}
