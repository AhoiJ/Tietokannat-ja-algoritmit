#include <iostream>
#include <climits>
#include <string>
#include "Extended_stack.h"
using namespace std;

int main()
{
	
	Extended_stack es;

	stack <char> test;
	stack <char> copy;

	es.push( 3 );
	es.push( 2 );

	int i;
	cout << "es.top( i ) = " << es.top( i ) << endl;
	cout << "i = " << i << endl;
	
	es.pop();

	cout << "es.empty(): " << boolalpha << es.empty() << endl;

	es.clear();
	cout << "es.empty(): " << boolalpha << es.empty() << endl;

	cout << "es.full(): " << boolalpha << es.full() << endl;

	cout << "es.size(): " << es.size() << endl;

	for (i = 1; i <= 10; i++)
		es.push(i);

	cout << "es.empty(): " << boolalpha << es.empty() << endl;

	cout << "es.full(): " << boolalpha << es.full() << endl;

	cout << "es.size(): " << es.size() << endl;

	copy_stack(copy, test);
//	system("pause");
	
	return 0;
}
