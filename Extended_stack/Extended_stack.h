#ifndef _EXTENDED_STACK_H
#define _EXTENDED_STACK_H
#include <stack>
#include "Utility.h"
#include <iostream>
#include <iostream>
// Section 2.2:
// template <class T, class Container = deque<T> > class stack;
using namespace std;

typedef int Stack_entry;

const int maxstack = 10;   //  small value for testing

class Extended_stack {
public:

	Extended_stack( );
	Error_code pop( );
	Error_code push(const Stack_entry &item);
	Error_code top(Stack_entry &item) const;

	friend Error_code copy_stack(stack <char> &dest, stack<char> &source);
	
	bool empty( ) const;
	void clear( ); // Reset the stack to be empty.
	bool full( ) const ; // If the stack is full, return true; else return false.
	int size( ) const; // Return the number of entries in the stack.

private:
	int count;
	Stack_entry entry[maxstack];
	stack <char> dest;
	stack <char> source;
};

#endif