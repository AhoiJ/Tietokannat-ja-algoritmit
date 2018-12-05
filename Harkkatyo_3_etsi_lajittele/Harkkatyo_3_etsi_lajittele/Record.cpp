#include "Record.h"
int Record::comparisons = 0;

Record::operator Key()
{
	return Key(data);
}

Record::Record(int param_data)
{
	data = Key(param_data);
}

void Record::set_data(int number)
{
	data = Key(number);
}

Key Record::get_data()
{
	return Key();
}

int Record::get_key_data() const
{
	return data.the_key();
}


bool operator ==(const Record &x, const Record &y)
{
	Record::comparisons++;
	return x.get_key_data() == y.get_key_data();
}

bool operator>(const Record & x, const Record & y)
{
	Record::comparisons++;
	return x.get_key_data() > y.get_key_data();
}

bool operator<(const Record & x, const Record & y)
{
	Record::comparisons++;
	return x.get_key_data() < y.get_key_data();
}

bool operator>=(const Record & x, const Record & y)
{
	Record::comparisons++;
	return x.get_key_data() >= y.get_key_data();
}

bool operator<=(const Record & x, const Record & y)
{
	Record::comparisons++;
	return x.get_key_data() <= y.get_key_data();
}

bool operator!=(const Record & x, const Record & y)
{
	Record::comparisons++;
	return x.get_key_data() != y.get_key_data();
}
