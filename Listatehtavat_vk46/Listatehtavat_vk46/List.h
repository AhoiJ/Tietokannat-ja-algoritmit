#pragma once
#include "Utility.h"

const int max_list = 100; // make smaller for tests default = 100

template <class List_entry>
	class List {
	public:
		//  methods of the List ADT
		List();	// done
		int size() const;	// done
		bool full() const;	// done
		bool empty() const; // done
		void clear(); // done
		void traverse(void(*visit)(List_entry &)); // done
		Error_code retrieve(int position, List_entry &x) const; // done
		Error_code replace(int position, const List_entry &x); // done
		Error_code remove(int position, List_entry &x); // done
		Error_code insert(int position, const List_entry &x);	// done

	protected:
		//  data members for a contiguous list implementation
		int count;
		List_entry entry[max_list];
};


