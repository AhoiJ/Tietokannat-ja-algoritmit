#pragma once

#include "Utility.h"

// Section 3.3:

typedef char Queue_entry;

const int maxqueue = 1000; //  small value for testing

class Queue {
public:
	Queue();
	bool empty() const;
	Error_code serve();
	Error_code append(const Queue_entry &item);
	Error_code retrieve(Queue_entry &item) const;

	void print(char *title_p);

protected:
	int count;
	int front, rear;
	Queue_entry entry[maxqueue];
};
