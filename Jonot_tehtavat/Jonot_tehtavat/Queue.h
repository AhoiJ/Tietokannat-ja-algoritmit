#pragma once
#include <iostream>
#include "Utility.h"
typedef char Queue_entry;

// using namespace std;

const int maxqueue = 10; //  small value for testing

class Queue {
public:
	Queue();
	bool empty() const;
	char get_command();
	Error_code serve();
	Error_code append(const Queue_entry &item);
	Error_code retrieve(Queue_entry &item) const;

protected:
	int count;
	int front, rear;
	Queue_entry entry[maxqueue];
};

