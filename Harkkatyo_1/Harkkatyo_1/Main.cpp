#include "cacu.h"
#include <stack>
#include <iostream>
typedef double Stack_entry;

using namespace std;

void introduction();

int main() {

	/* Post: The program has executed simple arithmetic commands entered by the user.
	Uses: The class Stack and functions introduction, instructions, do command,
	and get command. */

		stack <double> stored_numbers;
		cacu test;
		
		introduction();
	//	instructions();
		while (test.do_command(test.get_command(), stored_numbers));

}

void introduction() {

		std::cout << "[?]push to stack [=]print top" << std::endl
		<< "[+] [−] [*] [/] are arithmetic operations" << std::endl
		<< "[X] is exchange stack order" << std::endl
		<< "[S] is sum of all numbers in stack" << std::endl
		<< "[A] is average of all numbers in stack" << std::endl
		<< "[Q]uit." << std::endl;

}