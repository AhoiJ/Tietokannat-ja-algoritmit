#include <iostream>
#include "List.h"
#include "Utility.h"
#include "Search.h"
#include "Random.h"
#include "Timer.h"
#include "Sortable_list.h"

using namespace std;
void main2();
void main3();
void main4();
void main5();

int main()
{
	int user_input;
//	int record_count;
	List<Record> records;
//	int position;
	int input_check = 0;
	Search search;
	Random random(false);

	while (input_check != 1) {
		cout << "Select which version of program to run (1 , 2, 3 or 4)" << endl;

		cin >> user_input;
		if (user_input == 1 || user_input == 2 || user_input == 3 || user_input == 4)
			input_check = 1;
		else
			cout << " Wrong input, please try again." << endl;
	}
	switch (user_input)
	{
	case 1:
	{
		main2();
		break;
	}

	case 2:
	{
		main3();
		break;
	}
	case 3:
	{
		main4();
		break;
	}
	case 4:
	{
		main5();
		break;
	}
	}

	system("pause");
	return 0;
}


void main2()
{

//	int user_input;
	int record_count;
	List<Record> records;
	int position;
	int input_check = 0;
	Search search;
	Random random(false);

	int randomize;
	cout << "Would you like to randomize searched record? " << endl
		<< "(1 for yes 2 for no)";
	cin >> randomize;

	if (randomize == 1)
	{
		cout << "Give number of records: " << endl;
		cin >> record_count;

		// randomize
		int target_int = random.random_integer(0, record_count);

		cout << "sequential_search:" << endl;
		cout << "------------------" << endl;
		for (int i = 1; i < record_count + 1; i++)
		{
			records.insert(i - 1, Record(2 * i - 1));
		}

		Key target(target_int);

		if (search.sequential_search(records, target, position) == success)
		{
			cout << "Status: Successful" << endl;
			cout << "Key: " << target_int << " position: " << position << endl;
			cout << "Number of comparisons done: " << Key::comparisons << endl;
		}
		else
		{
			cout << "Status: Unsuccessful" << endl;
		}
	}
	else if (randomize == 2)
	{
		int target_int_self;
		cout << "Give number of records: " << endl;
		cin >> record_count;

		cout << "Give number to search: " << endl;
		cin >> target_int_self;

		cout << "sequential_search:" << endl;
		cout << "------------------" << endl;
		for (int i = 1; i < record_count + 1; i++)
		{
			records.insert(i - 1, Record(2 * i - 1));
		}

		Key target(target_int_self);

		if (search.sequential_search(records, target, position) == success)
		{
			cout << "Status: Successful" << endl;
			cout << "Key: " << target_int_self << " position: " << position << endl;
			cout << "Number of comparisons done: " << Key::comparisons << endl;
		}
		else
		{
			cout << "Status: Unsuccessful" << endl;
		}
	}
}

void main3()
{

	double sequential_successful_time = 0;
	double sequential_unsuccessful_time = 0;
	double binary_successful_time = 0;
	double binary_unsuccessful_time = 0;
	int successful_sequential_search_counter = 0;
	int unsuccessful_sequential_search_counter = 0;
	int successful_sequential_comparisons = 0;
	int unsuccessful_sequential_comparisons = 0;
	int successful_binary_search_counter = 0;
	int unsuccessful_binary_search_counter = 0;
	int successful_binary_comparisons = 0;
	int unsuccessful_binary_comparisons = 0;

	int record_count;
	List<Record> records;
	int position;
	int input_check = 0;
	Search search;
	Random random(false);
	int koko = 10;

	Timer timer = Timer();
	Key key_list[10];

	cout << "Give number of records: " << endl;
	cin >> record_count;

	for (int i = 1; i < record_count + 1; i++)
	{
		records.insert(i - 1, Record(2 * i - 1));
	}

	for (int j = 0; j < koko; j++)
	{
		int target_int = random.random_integer(0, record_count * 2 - 1);
		Key target(target_int);
		key_list[j] = target;
	}

	cout << endl << "sequential_search:" << endl;
	cout << "------------------" << endl;
	for (int j = 0; j < koko; j++)
	{
		Key::comparisons = 0;
		timer.reset();

		if (search.sequential_search(records, key_list[j], position) == success)
		{
			sequential_successful_time += timer.elapsed_time();
			successful_sequential_search_counter++;
			successful_sequential_comparisons += Key::comparisons;

			cout << "Status: Successful ";
			cout << "Key: " << key_list[j].the_key() << " position: " << position << endl;
		}
		else
		{
			sequential_unsuccessful_time += timer.elapsed_time();
			unsuccessful_sequential_search_counter++;
			unsuccessful_sequential_comparisons += Key::comparisons;
			cout << "Status: Unsuccessful" << endl;
		}

	}
	cout << endl << "binary_search_1:" << endl;
	cout << "------------------" << endl;
	for (int j = 0; j < koko; j++)
	{
		Key::comparisons = 0;
		timer.reset();

		if (search.binary_search_1(records, key_list[j], position) == success)
		{
			binary_successful_time += timer.elapsed_time();
			successful_binary_search_counter++;
			successful_binary_comparisons += Key::comparisons;

			cout << "Status: Successful ";
			cout << "Key: " << key_list[j].the_key() << " position: " << position << endl;
		}
		else
		{
			binary_unsuccessful_time += timer.elapsed_time();
			unsuccessful_binary_search_counter++;
			unsuccessful_binary_comparisons += Key::comparisons;
			cout << "Status: Unsuccessful" << endl;
		}
	}

	cout << endl << "sequential_search:" << endl;
	cout << "------------------" << endl;
	cout << "Status: Successful" << endl;
	cout << "Elapsed time per search: " << sequential_successful_time / successful_sequential_search_counter << endl;
	cout << "Comparisons per search: " << successful_sequential_comparisons / successful_sequential_search_counter << endl;
	cout << "Searches: " << koko << endl;

	cout << endl << "Status: Unsuccessful" << endl;
	cout << "Elapsed time per search: " << sequential_unsuccessful_time / unsuccessful_sequential_search_counter << endl;
	cout << "Comparisons per search: " << unsuccessful_sequential_comparisons / unsuccessful_sequential_search_counter << endl;
	cout << "Searches: " << koko << endl;


	cout << endl << "binary_search_1:" << endl;
	cout << "------------------" << endl;
	cout << "Status: Successful" << endl;
	cout << "Elapsed time per search: " << binary_successful_time / successful_binary_search_counter << endl;
	cout << "Comparisons per search: " << successful_binary_comparisons / successful_binary_search_counter << endl;
	cout << "Searches: " << koko << endl;

	cout << endl << "Status: Unsuccessful" << endl;
	cout << "Elapsed time per search: " << binary_unsuccessful_time / unsuccessful_binary_search_counter << endl;
	cout << "Comparisons per search: " << unsuccessful_binary_comparisons / unsuccessful_binary_search_counter << endl;
	cout << "Searches: " << koko << endl;


}

void main4()
{
	int record_count;
	Sortable_list <Record> records;
	//List<Record> records;
//	int position;
	int input_check = 0;
	Search search;
	Random random(false);
	int record_check_size;
	Record x;

	cout << "How many random records do you want?" << endl;
	cin >> record_count;
	do {
		cout << "How many records do you want shown?" << endl;
		cin >> record_check_size;

		if (record_check_size > record_count || record_check_size < 0)
			cout << "Input is not correct, size must be less than record amount and more than 0" << endl;
	} while (record_check_size > record_count || record_check_size < 0);

	for (int i = 0; i < record_count; i++)
	{
		int target_int = random.random_integer(0, record_count * 10);
		records.insert(i, target_int);
	}
	cout << "These are the first " << record_check_size 
		<< " elements of record array before sorting." << endl;

	for (int i = 0; i < record_check_size; i++)
	{
		records.retrieve(i, x);
		cout << x.get_key_data() << endl;
	}

	records.insertion_sort(); // Sort the list
	records.selection_sort(); // Just for funsies

	cout << "These are the first " << record_check_size
		<< " elements of record array after sorting." << endl;

	for (int i = 0; i < record_check_size; i++)
	{
		records.retrieve(i, x);
		cout << x.get_key_data() << endl;
	}
	
}

void main5() {
	int record_count;
	Sortable_list <Record> records;
	//List<Record> records;
	//	int position;
	int input_check = 0;
	Search search;
	Random random(false);
	int record_check_size;
	Record x;

	cout << "How many random records do you want?" << endl;
	cin >> record_count; // user inputs records size
	do {
		cout << "How many records do you want shown?" << endl;
		cin >> record_check_size; // shown records size
		
		// Input check 
		if (record_check_size > record_count || record_check_size < 0) 
			cout << "Input is not correct, size must be less than record amount and more than 0" << endl;
	} while (record_check_size > record_count || record_check_size < 0);

	// Insert records
	for (int i = 0; i < record_count; i++)
	{
		int target_int = random.random_integer(0, record_count * 10);
		records.insert(i, target_int);
	}
	/*
	// Scramble records
	for (int i = 0; i < record_count / 2; i++) {
		records.retrieve(i * 2, x);
		records.replace(i,x);
	}
	*/
	cout << "These are the first " << record_check_size
		<< " elements of record array before sorting." << endl;

	for (int i = 0; i < record_check_size; i++)
	{
		records.retrieve(i, x);
		cout << x.get_key_data() << endl;
	}

	records.merge_sort(); // merge sort puuttuu "head" muuttuja, ja varmaa jotain node funktioita.

	cout << "These are the first " << record_check_size
		<< " elements of record array after sorting." << endl;

	for (int i = 0; i < record_check_size; i++)
	{
		records.retrieve(i, x);
		cout << x.get_key_data() << endl;
	}

}