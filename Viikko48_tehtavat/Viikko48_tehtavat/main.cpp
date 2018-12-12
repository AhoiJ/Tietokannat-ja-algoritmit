#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {
	int arpakoko = 7;
	int arvat[7]{0};
	int oikeat[7]{ 0 };
	int oikein = 0;
	srand(time(NULL));

	for (int i = 0; i < arpakoko; i++) {
		oikeat[i] = rand() % 42 + 1;
		if (i < 0) {
			if (oikeat[i] == oikeat[i - 1])
				i--;
		}
	}
	cout << " give 7 numbers for lottery: " << endl;
	for (int i = 0; i < arpakoko; i++) {
		cout << "give number " << i << ": ";
		cin >> arvat[i];
		cout << endl;
	}
	for (int i = 0; i < arpakoko; i++) {
		for (int u = 0; u < arpakoko; u++) {
			if (arvat[i] == oikeat[u])
				oikein++;

		}
	}

	cout << "You got " << oikein << " correct!" << endl;

	cout << " correct line: ";
	for (int i = 0; i < arpakoko; i++)
		cout << oikeat[i] << " "; 

	cout << " Your line: ";
	for (int i = 0; i < arpakoko; i++)
		cout << arvat[i] << " ";

	system("pause");

}