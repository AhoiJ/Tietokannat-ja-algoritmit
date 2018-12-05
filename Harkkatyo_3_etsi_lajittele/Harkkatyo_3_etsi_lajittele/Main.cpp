#include <iostream>
#include "List.h"
#include "Utility.h"
#include "Search.h"
#include "Random.h"
#include "Timer.h"

using namespace std;

int main()
{
	int user_input;
	int record_count;
	List<Record> records;
	int position;
	int input_check = 0;
	Search search;
	Random random(false);

	while (input_check != 1) {
		cout << "Select which version of program to run (1 or 2)" << endl;

		cin >> user_input;
		if (user_input == 1 || user_input == 2 || user_input == 3)
			input_check = 1;
		else
			cout << " Wrong input, please try again." << endl;
	}
	switch (user_input)
	{
	case 1:
	{
		int randomize;
		cout << "Would you like to randomize searched record? " << endl
			<< "(1 for yes 2 for no)";
		cin >> randomize;
		
		if (randomize == 1)
		{
			cout << "Give number of records: " << endl;
			cin >> record_count;

			// randomize
			int target_int = random.random_integer(0, record_count );

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
			break;
		}
		else
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
			break;
		}
	}

	case 2:
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
		Timer timer = Timer();
		Key key_list[10];

		cout << "Give number of records: " << endl;
		cin >> record_count;

		for (int i = 1; i < record_count + 1; i++)
		{
			records.insert(i - 1, Record(2 * i - 1));
		}

		for (int j = 0; j < 10; j++)
		{
			int target_int = random.random_integer(0, record_count * 2 - 1);
			Key target(target_int);
			key_list[j] = target;
		}

		cout << endl << "sequential_search:" << endl;
		cout << "------------------" << endl;
		for (int j = 0; j < 10; j++)
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
		for (int j = 0; j < 10; j++)
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
		cout << "Searches: 10" << endl;

		cout << endl << "Status: Unsuccessful" << endl;
		cout << "Elapsed time per search: " << sequential_unsuccessful_time / unsuccessful_sequential_search_counter << endl;
		cout << "Comparisons per search: " << unsuccessful_sequential_comparisons / unsuccessful_sequential_search_counter << endl;
		cout << "Searches: 10" << endl;


		cout << endl << "binary_search_1:" << endl;
		cout << "------------------" << endl;
		cout << "Status: Successful" << endl;
		cout << "Elapsed time per search: " << binary_successful_time / successful_binary_search_counter << endl;
		cout << "Comparisons per search: " << successful_binary_comparisons / successful_binary_search_counter << endl;
		cout << "Searches: 10" << endl;

		cout << endl << "Status: Unsuccessful" << endl;
		cout << "Elapsed time per search: " << binary_unsuccessful_time / unsuccessful_binary_search_counter << endl;
		cout << "Comparisons per search: " << unsuccessful_binary_comparisons / unsuccessful_binary_search_counter << endl;
		cout << "Searches: 10" << endl;


	}
	case 3:
	{





	}

	}

	system("pause");
	return 0;
}