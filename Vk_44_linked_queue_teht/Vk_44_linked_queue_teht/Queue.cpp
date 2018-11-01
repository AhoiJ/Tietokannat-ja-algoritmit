#include "Queue.h"


Queue::Queue()
/*
Post: The Queue is initialized to be empty.
*/
{
	front = rear = NULL;
}

bool Queue::empty() const
{
	bool outcome = true;
	if (front == rear) 
		outcome = false;

	return outcome;
}

Error_code Queue::append(const Queue_entry &item)
/*
Post: Add item to the rear of the Queue and return a code of success
or return a code of overflow if dynamic memory is exhausted.
*/
{
	Node *new_rear = new Node(item);
	if (new_rear == NULL) return overflow;
	if (rear == NULL) front = rear = new_rear;
	else {
		rear->next = new_rear;
		rear = new_rear;
	}
	return success;
}

Error_code Queue::serve()
/*
Post: The front of the Queue is removed.  If the Queue
is empty, return an Error_code of underflow.
*/
{
	if (front == NULL) return underflow;
	Node *old_front = front;
	front = old_front->next;
	if (front == NULL) rear = NULL;
	delete old_front;
	return success;
}

Queue_entry Queue::retrieve(Queue_entry & item) const
{
	item = Queue_entry(front);
	return item;
}

Queue::~Queue()
{
	while (!empty()) {
		delete rear;
		rear = rear->next;
	}
}

Queue::Queue(Queue & original)
{
	Queue temp;
	Queue new_que;
	Queue_entry x;
	while (!original.empty())
	{
		original.retrieve(x);
		temp.append(x);
		new_que.append(x);
		original.serve();
	}
	while (!temp.empty())
	{
		temp.retrieve(x);
		original.append(x);
		temp.serve();
	}
}

void Queue::operator=(const Queue & original)
{
}