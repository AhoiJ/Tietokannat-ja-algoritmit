#include "List.h"
#include <iostream>

using namespace std;

template <class List_entry>
List<List_entry>::List() {
	entry[max_list];
	count = 0;
}

template <class List_entry>
bool List<List_entry>::full() const
// returns true if list not full, false if list full
{
	bool result = false;
	if (count < max_list)
		result = true;
	return result;
}

template <class List_entry>
bool List<List_entry>::empty() const
// returns true if list is empty, false if not empty
{
	bool result = false;
	if (count == 0)
		result = true;
	return result;
}

template <class List_entry>
void List<List_entry>::clear()
// removes all elemets from list
{
	while (!empty()) {
		entry[count] = NULL;
		count--;
	}
}

template <class List_entry>
int List<List_entry>::size() const
/* Post: The function returns the number of entries in the List. */
{
	return count;
}



template <class List_entry>
void List<List_entry>::traverse(void(*visit)(List_entry &))
/*
Post: The action specified by function (*visit) has been performed on every
entry of the List, beginning at position 0 and doing each in turn.
*/
{
	for (int i = 0; i < count; i++)
		(*visit)(entry[i]);
}

template<class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry & x) const
{
	if (position <= count || position >= count)
	{
		x = entry[position];
		return x;
	}else
	return range_error;
}

template<class List_entry>
Error_code List<List_entry>::replace(int position, const List_entry & x)
{
	if (position <= count || position >= count)
	{
		entry[position] = x;
		return x;
	}
	else
		return range_error;
}

template<class List_entry>
Error_code List<List_entry>::remove(int position, List_entry & x)
{
	if (position <= count || position >= count)
	{
		entry[position] = NULL;
		for (int i = count - 1; i >= position; i--)
			entry[i - 1] = entry[i];
		return x;
	}
	else
		return range_error;
}




template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x)
/*
Post: If the List is not full and 0 <= position <= n,
where n is the number of entries in the List, the function succeeds:
Any entry formerly at position and all later entries have their
position numbers increased by 1 and x is inserted at position of the List.
Else: The function fails with a diagnostic error code.
*/
{
	if (full())
		return overflow;

	if (position < 0 || position > count)
		return range_error;

	for (int i = count - 1; i >= position; i--)
		entry[i + 1] = entry[i];

	entry[position] = x;
	count++;
	return success;
}



