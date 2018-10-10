#pragma once

#include "utility.h"
const int maxqueue = 1000; //  small value for testing

typedef int Queue_entry;

class Queue {
public:
	Queue();

	bool empty() const;
	Error_code serve();
	Error_code append(const Queue_entry &item);
	Error_code retrieve(Queue_entry &item) const;

protected:
	int count;
	int front, rear;
	Queue_entry entry[maxqueue];
};