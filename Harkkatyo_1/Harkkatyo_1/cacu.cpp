
#include "cacu.h"
#include <iostream>

using namespace std;

cacu::cacu()
{
}

cacu::~cacu()
{
}

char cacu::get_command()
{
	char command;
	bool waiting = true;
	cout << "Select command and press < Enter > :";
	while (waiting) {
		cin >> command;
		command = tolower(command);
		if (command == '?' || command == '=' || command == '+' ||
			command == '-' || command == '*' || command == '/' ||
			command == 'q') waiting = false;

		else {
			cout << "Please enter a valid command:" << endl
				<< "[?]push to stack [=]print top" << endl
				<< "[+] [−] [*] [/] are arithmetic operations" << endl
				<< "[Q]uit." << endl;
		}
	}
	return command;
}

bool cacu::do_command(char command, stack <double> &numbers)
{
	/* Pre: The first parameter specifies a valid calculator command.
	Post: The command specified by the first parameter has been applied to the Stack
	of numbers given by the second parameter. A result of true is returned unless
	command == 0
	q0
	.
	Uses: The class Stack. */
	 double p, q;
	 switch (command) {
	 case'?':
		 cout << "Enter a real number: " << flush; cin >> p;
		 numbers.push(p);
		 break;
	 case '=':
		 cout << endl << "Top of stack: " << numbers.top() << endl;
		 break;
	 case '+':
		 cout << "Enter a real number to add: " << flush; cin >> p;
		 numbers.push(p);
		 q = numbers.top();
		 numbers.pop();
		 p = numbers.top();
		 cout << "Addition: " << q + p << endl;
		 numbers.push(q + p);
		 break;
	 case 'q':
			  cout << "Calculation finished.\n"; return false;
	 } return true;
	
}

void cacu::addition(double p)
{


}
