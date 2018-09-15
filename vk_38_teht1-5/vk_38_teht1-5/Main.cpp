#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main()
/*
Pre:   The user supplies an integer n and n decimal numbers.
Post:  The numbers are printed in reverse order.
Uses:  The STL class stack and its methods
*/

{
	int n;
	//	double item;

	char character[100];
	stack<char> word;
	//	stack<double> numbers;  //  declares and initializes a stack of numbers

	//	cout << " Type in an integer n followed by n decimal numbers." << endl
	//		<< " The numbers will be printed in reverse order." << endl;
	cout << "enter a word" << endl;
		//k�ytettiin 1 a:ssa
	/*
		cin >> n;
		for (int i = 0; i < n; i++) {
			getline(cin, character);
			word.push(character);
		}
		*/

		// vastaanottaa sy�tett� space tai enter painallukseen asti, strlen() est�� looppia py�rim�st� turhia kierroksia
	cin >> character;
	for (int i = 0; i < strlen(character); i++)
	{
		word.push(character[i]);
	}
	// teht 1c, palindromitestaus
	stack<char> palindr = word;
	stack<char>palindr2;
	char c;

	while (!palindr.empty()) {
		c = palindr.top();
		palindr.pop();
		palindr2.push(c);
	}



	// tulostaa ylimm�n stackin, ja poistaa sitten sen. toimii koska last in first out
	// tarkistaa onko sis�lt� palidroma
	int check = 0;
	cout << endl << endl;
	while (!word.empty()) {
		if (palindr2.top() == word.top())
			check++;
		cout << word.top() << " ";
		word.pop();
		palindr2.pop();
	}
	cout << endl;
	if (check == strlen(character))
		cout << endl << "input is a palidrome." << endl;
	else
		cout << "input is not a palindrome" << endl;

	system("pause");
}