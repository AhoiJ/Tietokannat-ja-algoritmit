#include "Extended_queue.h"
#include "utility.h"


Extended_queue::Extended_queue()
{
	count = 0;
	front = 0;
	rear = maxque - 1;
}

bool Extended_queue::empty() const
{
	bool outcome = true;
	if (count > 0) outcome = false;
	return outcome;
}

bool Extended_queue::full() const
{

	return count == maxque;
}

int Extended_queue::size() const
/*
Post:   Return the number of entries in the Extended_queue.
*/
{
	return count;
}

void Extended_queue::clear() 
{
		count = 0;
}

Error_code Extended_queue::serve_and_retrieve(Queue_entry & item)
{
	if (count <= 0) return underflow;
	item = qEntry[front];
	return success;
}
