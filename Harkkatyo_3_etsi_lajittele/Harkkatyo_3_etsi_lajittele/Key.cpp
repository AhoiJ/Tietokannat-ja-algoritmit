#include "Key.h"
#include <iostream>

int Key::comparisons = 0;

bool operator ==(const Key &x, const Key &y)
{
	Key::comparisons++;
	return x.the_key() == y.the_key();
}

bool operator>(const Key & x, const Key & y)
{
	Key::comparisons++;
	return x.the_key() > y.the_key();
}

bool operator<(const Key & x, const Key & y)
{
	Key::comparisons++;
	return x.the_key() < y.the_key();
}

bool operator>=(const Key & x, const Key & y)
{
	Key::comparisons++;
	return x.the_key() >= y.the_key();
}

bool operator<=(const Key & x, const Key & y)
{
	Key::comparisons++;
	return x.the_key() <= y.the_key();
}

bool operator!=(const Key & x, const Key & y)
{
	Key::comparisons++;
	return x.the_key() != y.the_key();
}

Key::Key(int x)
{
	key = x;
}

int Key::the_key() const
{
	return key;
}

void Key::operator = (const Key &original)
{
	Key::assignments++;
	key = original.key;
}

ostream& operator << (ostream& os, const Key& k)
{
	return os << k.the_key();
}
