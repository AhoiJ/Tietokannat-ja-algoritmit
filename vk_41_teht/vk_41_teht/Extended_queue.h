#pragma once
#include "utility.h"

typedef int Queue_entry;

const int maxque = 10;

class Extended_queue {

public:
	Extended_queue();
	bool empty() const;
	bool full() const;
	int size() const;
	void clear();
	Error_code serve_and_retrieve(Queue_entry &item);

private:
	int count;
	int front, rear;
	Queue_entry qEntry[maxque];
};