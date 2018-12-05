#pragma once
#include "Key.h"
#include "Sortable_list.h"

class Record {
public:
	operator Key(); //  implicit conversion from Record to Key.
	static int comparisons;
	Record(int param_data = 0);
	void set_data(int number);
	Key get_data();
	int get_key_data() const;
private:
	Key data;
};

bool operator ==(const Record &x, const Record &y);
bool operator > (const Record &x, const Record &y);
bool operator < (const Record &x, const Record &y);
bool operator >=(const Record &x, const Record &y);
bool operator <=(const Record &x, const Record &y);
bool operator !=(const Record &x, const Record &y);


