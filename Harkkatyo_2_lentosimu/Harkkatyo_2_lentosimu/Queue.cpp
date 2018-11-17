#include "Queue.h"
#include <iostream>

using namespace std;

Queue::Queue()
/*
Post: The Queue is initialized to be empty.
*/
{
	count = 0;
	rear = maxqueue - 1;
	front = 0;
}

bool Queue::empty() const
/*
Post: Return true if the Queue is empty, otherwise
return false.
*/
{
	return count == 0;
}

Error_code Queue::append(const Queue_entry &item)
/*
Post: item is added to the rear of the Queue. If the Queue is full
return an Error_code of overflow and leave the Queue unchanged.
*/
{
	if (count >= maxqueue) return overflow;
	count++;
	rear = ((rear + 1) == maxqueue) ? 0 : (rear + 1);
	entry[rear] = item;
	return success;
}

Error_code Queue::serve()
/*
Post: The front of the Queue is removed. If the Queue
is empty return an Error_code of underflow.
*/
{
	if (count <= 0) return underflow;
	count--;
	front = ((front + 1) == maxqueue) ? 0 : (front + 1);
	return success;
}

Error_code Queue::retrieve(Queue_entry &item)
/*
Post: The front of the Queue retrieved to the output
parameter item. If the Queue
is empty return an Error_code of underflow.
*/
{
	if (count <= 0) return underflow;
	item = entry[front];
	return success;
}


Plane::Plane()
/*
Post:  The Plane data members flt_num, clock_start,
state are set to illegal default values.
*/
{
	flt_num = -1;
	clock_start = -1;
	state = null;
}

Plane::Plane(int flt, int time, Plane_status status)
/*
Post:  The Plane data members flt_num, clock_start,
and state are set to the values of the parameters flt,
time and status, respectively.
*/

{
	flt_num = flt;
	clock_start = time;
	state = status;
	cout << "Plane number " << flt << " ready to ";
	if (status == arriving)
		cout << "land." << endl;
	else
		cout << "take off." << endl;
}

void Plane::refuse() const
/*
Post: Processes a Plane wanting to use Runway, when
the Queue is full.
*/

{
	cout << "Plane number " << flt_num;
	if (state == arriving)
		cout << " directed to another airport" << endl;
	else
		cout << " told to try to takeoff again later" << endl;
}

void Plane::land(int time) const
/*
Post: Processes a Plane that is landing at the specified time.
*/

{
	int wait = time - clock_start;
	cout << time << ": Plane number " << flt_num << " landed after "
		<< wait << " time unit" << ((wait == 1) ? "" : "s")
		<< " in the takeoff queue." << endl;
}


void Plane::fly(int time) const
/*
Post: Process a Plane that is taking off at the specified time.
*/

{
	int wait = time - clock_start;
	cout << time << ": Plane number " << flt_num << " took off after "
		<< wait << " time unit" << ((wait == 1) ? "" : "s")
		<< " in the takeoff queue." << endl;
}


int Plane::started() const
/*
Post: Return the time that the Plane entered the airport system.
*/
{
	return clock_start;
}
