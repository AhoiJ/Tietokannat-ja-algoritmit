#include "Utility.h"
//#include "List.h"
#include <iostream>

using namespace std;

//Error_code insert_first(const int &x, List<int> &a_list);

//Error_code remove_first(int &x, List<int> &a_list);

//const int max_list = 10; // make smaller for tests default = 100

template <typename T>
class List {
public:
	//  methods of the List ADT
	List( int size = 10);	// done
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
	int count = 0;
	int max_list;
	T *entry;
};


template <typename T>
List<T>::List(int size = 10) {

	max_list = size;
	count = 0;
	this-> entry = new T [this->max_list];
}

template<typename T>
List<T>::~List()
{
	delete[] this->entry;
}

template <typename T>
bool List<T>::full() const
// returns true if list not full, false if list full
{
	bool result = true;
	if (count < max_list)
		result = false;
	return result;
}

template <typename T>
bool List<T>::empty() const
// returns true if list is empty, false if not empty
{
	bool result = false;
	if (count == 0) {
		result = true;
		cout << "list is empty" << endl;
	}
	return result;
}

template <typename T>
void List<T>::clear()
// removes all elemets from list
{
	while (!empty()) {
		entry[count] = NULL;
		count--;
	}
}

template <typename T>
int List<T>::size() const
/* Post: The function returns the number of entries in the List. */
{
	return count;
}



template <typename T>
void List<T>::traverse(void(*visit)(T &))
/*
Post: The action specified by function (*visit) has been performed on every
entry of the List, beginning at position 0 and doing each in turn.
*/
{
	for (int i = 0; i < count; i++)
		(*visit)(entry[i]);
}

template<typename T>
Error_code List<T>::retrieve(int position, T & x) const
{
	if (position <= count || position >= count)
	{
		x = entry[position];
		return success;
	}
	else
		return fail;
}

template<typename T>
Error_code List<T>::replace(int position, const T & x)
{
	if (position <= count || position >= count)
	{
		entry[position] = x;
		return success;
	}
	else
		return fail;
}

template<typename T>
Error_code List<T>::remove(int position, T & x)
{
	if (position <= count || position >= count)
	{
		x = entry[position];
		entry[position] = NULL;
		for (int i = count - 1; i >= position; i--) {
			entry[i - 1] = entry[i];
		}
		count--;
		return success;
	}
	else
		return fail;
}




template <typename T>
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
	{ 
		return fail;
	}
	else

	for (int i = count - 1; i >= position; i--)
		entry[i + 1] = entry[i];

	this->entry[position] = x;
	count++;
	return success;
}


Error_code insert_first(const int &x, List<int> &a_list);
Error_code remove_first(const int &x, List<int> &a_list);
Error_code insert_last(const int &x, List<int> &a_list);
Error_code remove_last(const int &x, List<int> &a_list);
Error_code median_list(int &x, List<int> &a_list);
Error_code interchange(int pos1, int pos2, List<int> &a_list); 
void reverse_traverse(List<int> &a_list, void(*visit)(int &));


int main () {

	List <int> lista;
	int j = 61;
	int k = 0;
	// teht 1.1
	insert_first(j, lista);
	lista.retrieve(0, k);
	cout << k << endl;
	// end of teht 1.1 / start of teht 1.2
//	remove_first(k, lista);
//	lista.empty();
	/* prints whole list
	while (!lista.empty()) {
		cout << k << endl;
		lista.retrieve(lista.size()-1, k); // jos retrievessä käyttää lista.size() täytyy laittaa -1 koska arrayt alkaa nollasta
		lista.remove(lista.size(), j);
	}*/
	// end of teth 1.2 /start of teht 1.3
	insert_last(13, lista);
	// end of teht 1.3 /start of teht 1.4
	remove_last(k, lista);
	// end of teht 1.4 / start of teht 1.5   testitarkoituksissa kommentoi remove_last pois tai laita lisää kamaa ennen loppuja
	median_list(k, lista);
	// end of teht 1.5 / start of teht 1.6
	interchange(0, 1, lista);
	// end of teht 1.6 /start of teht 1.7
	reverse_traverse(List<int> &a_list, void(*visit)(List_entry &)); // wtf

	system("pause");
	return 0;
}

Error_code insert_first(const int &x, List<int> &a_list) {

	a_list.insert(0, x);
	return success;
}

Error_code remove_first(int &x, List<int> &a_list) {

	a_list.remove(0, x);
	return success;
}
Error_code insert_last(const int &x, List<int> &a_list) {
	
	a_list.insert(a_list.size(), x);
	return success;
}
Error_code remove_last(int &x, List<int> &a_list) {

	a_list.remove(a_list.size(), x);
	return success;
}
Error_code median_list(int &x, List<int> &a_list) {
	int median = a_list.size() / 2;
	a_list.retrieve(median, x);
	return success;
}
Error_code interchange(int pos1, int pos2, List<int> &a_list) {

	int x, y;
	a_list.retrieve(pos1, x);
	a_list.retrieve(pos2, y);
	a_list.replace(pos2, x);
	a_list.replace(pos1, y);

	return success;
}
void reverse_traverse(List<int> &a_list, void(*visit)(int &)) {


}
