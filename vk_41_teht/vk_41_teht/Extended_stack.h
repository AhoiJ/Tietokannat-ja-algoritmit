#pragma once
#ifndef _EXTENDED_STACK_H
#define _EXTENDED_STACK_H

#include "Utility.h"

// Section 2.2:

typedef int Stack_entry;

const int maxstack = 10;   //  small value for testing

class Extended_stack {
public:
	Extended_stack();
	Error_code pop();
	Error_code push(const Stack_entry &item);
	Error_code top(Stack_entry &item) const;
	Error_code Extended_stack::serve_and_retrieve(Stack_entry &item);
	bool empty() const;
	void clear(); // Reset the stack to be empty.
	bool full() const; // If the stack is full, return true; else return false.
	int size() const; // Return the number of entries in the stack.

private:
	int count;
	Stack_entry entry[maxstack];
};

#endif