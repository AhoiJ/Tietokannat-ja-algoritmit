#include "cacu.h"
#include <stack>
typedef double Stack_entry;

using namespace std;

int main() {

	/* Post: The program has executed simple arithmetic commands entered by the user.
	Uses: The class Stack and functions introduction, instructions, do command,
	and get command. */

		stack <double> stored_numbers;
		cacu test;
		
	//	introduction();
	//	instructions();
		while (test.do_command(test.get_command(), stored_numbers));

}