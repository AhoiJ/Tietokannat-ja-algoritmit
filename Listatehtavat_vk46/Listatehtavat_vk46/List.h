//#pragma once
#include "Utility.h"
#include <iostream>

using namespace std;

const int max_list = 10; // make smaller for tests default = 100

template <class T>
	class List {
	public:
		//  methods of the List ADT
		List();	// done
		~List();
		int size() const;	// done
		bool full() const;	// done
		bool empty() const; // done
		void clear(); // done
		void traverse(void(*visit)(T &)); // done
		Error_code retrieve(int position, T &x) const; // done
		Error_code replace(int position, const T &x); // done
		Error_code remove(int position, T &x); // done
		Error_code insert(int position, const T &x);	// done

	private:
		//  data members for a contiguous list implementation
		int count;
		T entry[max_list];
};


	template <class T>
	List<T>::List() {
		// entry[max_list];
		this->count = new count = 0;
		this->entry = new entry;
	}

	template<class T>
	List<T>::~List()
	{
		delete[]-> this.entry;
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
		/* Post: The function returns the number of entries in the List. */
	{
		return count;
	}



	template <class T>
	void List<T>::traverse(void(*visit)(T &))
		/*
		Post: The action specified by function (*visit) has been performed on every
		entry of the List, beginning at position 0 and doing each in turn.
		*/
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
		}
		else
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

