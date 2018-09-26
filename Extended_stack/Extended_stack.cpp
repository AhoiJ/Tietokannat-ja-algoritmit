#include <iostream>
#include "Utility.h"
#include "Extended_stack.h"
using namespace std;

Error_code Extended_stack::push(const Stack_entry &item)
/*
Pre:  None.
Post: If the Extended_stack is not full, item is added to the top
      of the Extended_stack.  If the Extended_stack is full,
      an Error_code of overflow is returned and the Extended_stack is left unchanged.
*/

{
   Error_code outcome = success;
   if (count >= maxstack)
      outcome = overflow;
   else
      entry[count++] = item;
   return outcome;
}


Error_code Extended_stack::pop()
/*
Pre:  None.
Post: If the Extended_stack is not empty, the top of
      the Extended_stack is removed.  If the Extended_stack
      is empty, an Error_code of underflow is returned.
*/

{
   Error_code outcome = success;
   if (count == 0)
      outcome = underflow;
   else --count;
   return outcome;
}


Error_code Extended_stack::top(Stack_entry &item) const
/*
Pre:  None.
Post: If the Extended_stack is not empty, the top of
      the Extended_stack is returned in item.  If the Extended_stack
      is empty an Error_code of underflow is returned.
*/

{
   Error_code outcome = success;
   if (count == 0)
      outcome = underflow;
   else
      item = entry[count - 1];
   return outcome;
}



// teht 6 c tehtiin funktiosta friend
Error_code copy_stack(stack<char>& dest, stack<char>& source)
{
	stack <char> temp;
	char c;
	char a[10] = "12345";
	for (int i = 0; i < 5; i++)
	source.push(a[i]);

	// teht 6 a tässä
//	dest = source;
	// teht 6 b
	while (!source.empty()) {
		c = source.top();
		temp.push(c);
		source.pop();
	}
	while (!temp.empty()) {
		c = temp.top();
		source.push(c);
		dest.push(c);
		temp.pop();
	}

	if (dest == source)
		cout << "copy succesfull" << endl;
	else
		cout << "copy unsuccesfull" << endl;
	
	while (!source.empty()) {
		cout << "source:" << source.top() << endl;
		cout << "dest:" << dest.top() << endl;
		dest.pop();
		source.pop();
	}
	

	return Error_code();
}




bool Extended_stack::empty() const
/*
Pre:  None.
Post: If the Extended_stack is empty, true is returned.
      Otherwise false is returned.
*/

{
   bool outcome = true;
   if (count > 0) outcome = false;
   return outcome;
}


Extended_stack::Extended_stack()
/*
Pre:  None.
Post: The Extended_stack is initialized to be empty.
*/
{
   count = 0;
}

/*
void Extended_stack::print_contents()
{
	cout << "Tee tama !!!!" << endl;
}*/

void Extended_stack::clear( ) // Reset the stack to be empty.
{
	count = 0;
}

bool Extended_stack::full( ) const  // If the stack is full, return true; else return false.
{
	return count == maxstack;
}

int Extended_stack::size( ) const // Return the number of entries in the stack.
{
	return count;
}


