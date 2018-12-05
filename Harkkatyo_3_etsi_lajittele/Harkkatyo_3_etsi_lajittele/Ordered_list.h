#pragma once
#include "List.h"
#include "Record.h"

class Ordered_list :public List<Record> {
public:
	Ordered_list();
	Error_code insert(const Record &data);
	Error_code insertPos(int position, const Record &data);
	// Error_code replace(int position, const Record &data);
};


