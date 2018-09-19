#include <stack>
#include <iostream>
#include <string>

using namespace std;
/* Tehtava 1 -----------------------------------
int main()

//Pre:   The user supplies an integer n and n decimal numbers.
//Post:  The numbers are printed in reverse order.
//Uses:  The STL class stack and its methods


{
	int n;
	//	double item;

	char character[100];
	stack<char> word;
	//	stack<double> numbers;  //  declares and initializes a stack of numbers

	//	cout << " Type in an integer n followed by n decimal numbers." << endl
	//		<< " The numbers will be printed in reverse order." << endl;
	cout << "enter a word" << endl;
		//käytettiin 1 a:ssa
	
//		cin >> n;
	//	for (int i = 0; i < n; i++) {
		//	getline(cin, character);
			//word.push(character);
	//	}
		

		// vastaanottaa syötettä space tai enter painallukseen asti, strlen() estää looppia pyörimästä turhia kierroksia
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



	// tulostaa ylimmän stackin, ja poistaa sitten sen. toimii koska last in first out
	// tarkistaa onko sisältö palidroma
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
	*/


/*tehtava 2*/
/*
int main()
{
	stack<char> s;
	char x, y, z;

	s.push('a');
	cout << s.top() << endl;
	s.push('b');
	cout << s.top() << endl;
	s.push('c');
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.pop();

	
	s.push('a');
	cout << s.top() << endl;
	s.push('b');
	cout << s.top() << endl;
	s.push('c');
	cout << s.top() << endl;
	x = s.top();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	y = s.top();
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.push(x);
	cout << s.top() << endl;
	s.push(y);
	cout << s.top() << endl;
	s.pop();
	

	
	s.push('a');
	cout << s.top() << endl;
	s.push('b');
	cout << s.top() << endl;
	s.push('c');
	cout << s.top() << endl;
	while (!s.empty())
		s.pop();

	s.push('a');
	cout << s.top() << endl;
	s.push('b');
	cout << s.top() << endl;
	while (!s.empty()) {
		x = s.top();
		s.pop();
	}
	

	
	s.push('c');
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.push('a');
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.push('b');
	cout << s.top() << endl;
	s.pop();
	

	system("pause");
}
*/

// Tehtava kolme on sama kuin tehtävä 1 c


/*Tehtävä 4*/

int main() 
{
	cout << "Enter numbers in increasing order " << endl;
	bool check = false;
	int number = 0;
	stack<int> num;
	do {
		cin >> number;
		if (!num.empty()) {
			if (number <= num.top()) {
				check = true;
			}
		}
		if (check == false)
		num.push(number);
	
	} while (check == false);
	
	while (!num.empty()) {
		cout << num.top() << " ";
		num.pop();
	}
	cout << endl;
	system("pause");
}