#pragma once
#include "Utility.h"
#include <stack>
typedef double Stack_entry;

class cacu {
public:
	cacu();
	~cacu();

	char get_command();
	bool do_command( char command, std::stack <double> &numbers);
	void addition(double p);

protected:
	char command;
	std::stack <double> numbers;
};
