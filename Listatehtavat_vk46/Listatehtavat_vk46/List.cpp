/*

#include "List.h"
#include <iostream>

using namespace std;

template <class T>
List<T>::List() {
	// entry[max_list];
	count = 0;
}

template<class T>
List<T>::~List()
{
}

template <class T>
bool List<T>::full() const
// returns true if list not full, false if list full
{
	bool result = false;
	if (count < max_list)
		result = true;
	return result;
}

template <class T>
bool List<T>::empty() const
// returns true if list is empty, false if not empty
{
	bool result = false;
	if (count == 0)
		result = true;
	return result;
}

template <class T>
void List<T>::clear()
// removes all elemets from list
{
	while (!empty()) {
		entry[count] = NULL;
		count--;
	}
}

template <class T>
int List<T>::size() const
//Post: The function returns the number of entries in the List. 
{
	return count;
}



template <class T>
void List<T>::traverse(void(*visit)(T &))

{
	for (int i = 0; i < count; i++)
		(*visit)(entry[i]);
}

template<class T>
Error_code List<T>::retrieve(int position, T & x) const
{
	if (position <= count || position >= count)
	{
		x = entry[position];
		return x;
	}else
	return range_error;
}

template<class T>
Error_code List<T>::replace(int position, const T & x)
{
	if (position <= count || position >= count)
	{
		entry[position] = x;
		return x;
	}
	else
		return range_error;
}

template<class T>
Error_code List<T>::remove(int position, T & x)
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




template <class T>
Error_code List<T>::insert(int position, const T &x)

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
*/


