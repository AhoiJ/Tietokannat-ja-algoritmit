#pragma once
#include "Record.h"
#include "List.h"
#include "Utility.h"

class Search {
public:
	Search();

	Error_code sequential_search(const List<Record> &the_list,
		const Key &target, int &position);

	Error_code binary_search_1(const List<Record> &the_list,
		const Key &target, int &position);

};