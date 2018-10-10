#include "Extended_queue.h"
#include "utility.h"
#include "Queue.h"
#include <string>
#include <iostream>

using namespace std;

void readInput(Queue input);

int main()

{
	Queue input;
	string words;
	Queue_entry t;

	cout << "	Enter two words separated by ':'" << endl;
	getline(cin, words);

	for (int i = 0; i < words.length(); i++)
		input.append(words[i]);

/*	while (!input.empty()) {
		input.retrieve(t);
		input.serve();
		cout << char(t) << endl;
	}*/
	readInput(input);
	system("pause");

}


void readInput(Queue input) {
	double count = 0;
	double count2 = 0;
	int isSame = 0;
	bool activate = false;
	Queue_entry p;
	Queue_entry q;
	Queue temp;
	
	// Move the queue to a temp que and count how many entrys there are to count2. 
	while (!input.empty()) {
		input.retrieve(p);
		temp.append(p);
		input.serve();
		count2++;
		if (activate == false) {	// variable count counts how many entrys were before ':'.
			count++;
			if (char(p) == ':') {
				activate = true;
				 count--;
			}
		}
	}
	if (count == count2) // if variables are same value there was no ':'.
		cout << "N" << endl;
	else {
		count2--; // take the count off from the semicolon so we can check word lenghts later.

		if (count2 - count < count2 / 2) // checks if left side is longer.
			cout << "L" << endl;

		else if (count2 - count > count2 / 2)// checks if right side is longer.
			cout << "R" << endl;

		else if (count2 - count == count2 / 2) {// checks if sides are same size.
			
			for (int i = 0; i < count; i++) { // moves all entrys before ':' to input from temp
				temp.retrieve(p);
				input.append(p);
				temp.serve();
			}
			temp.serve();// removes the ':'

			while (!input.empty()) { // checks if both words are same
				input.retrieve(p);
				temp.retrieve(q);
				if (p == q)
					isSame++;
				input.serve();
				temp.serve();
			}
			if (isSame == count)
				cout << "S" << endl;
			else
				cout << "D" << endl;
		}
	}
}