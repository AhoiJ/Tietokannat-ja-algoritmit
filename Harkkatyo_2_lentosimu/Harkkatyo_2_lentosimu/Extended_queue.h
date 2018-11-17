#pragma once
#include "Queue.h"
#include "Plane.h"

class Extended_queue : public Queue {
public:
	bool full() const;
	int size() const;
	void clear();
	Error_code serve_and_retrieve(Queue_entry &item);
};
