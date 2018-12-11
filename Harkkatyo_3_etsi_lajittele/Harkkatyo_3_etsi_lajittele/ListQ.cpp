#include "ListQ.h"


template <class ListQ_entry>
ListQ::ListQ()
{
}

template <class ListQ_entry>
ListQ::~ListQ()
{
}

template <class ListQ_entry>int ListQ<ListQ_entry>::size() const/*Post: The function returns the number of entries in the List.*/{	return count;}template <class ListQ_entry>Error_code ListQ<ListQ_entry>::insert(int position, const ListQ_entry &x)/*Post: If the List is not full and 0 <= position <= n,where n is the number of entries in the List, the function succeeds:Any entry formerly at position and all later entries have theirposition numbers increased by 1 and x is inserted at position of the List.Else: The function fails with a diagnostic error code.*/{	if (full())		return overflow;	if (position < 0 || position > count)		return range_error;	for (int i = count - 1; i >= position; i--)		entry[i + 1] = entry[i];	entry[position] = x;	count++;	return success;}template <class ListQ_entry>void ListQ<ListQ_entry>::traverse(void(*visit)(ListQ_entry &))/*Post: The action specified by function (*visit) has been performed on everyentry of the List, beginning at position 0 and doing each in turn.*/{	for (int i = 0; i < count; i++)		(*visit)(entry[i]);}