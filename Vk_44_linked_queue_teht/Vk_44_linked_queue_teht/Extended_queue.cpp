#include "Extended_queue.h"
#include <iostream>

using namespace std;

int Extended_queue::size() const{	Node *window = front;	int count = 0;	while (window != NULL) {		window = window->next;		count++;	}	return count;}