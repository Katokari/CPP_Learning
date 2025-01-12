/*
#include <iostream>
using namespace std;

int getPositiveNumber(string message) {
	int num;
	do
	{
		cout << message;
		cin >> num;
		cout << endl;
	} while (num <= 0);

	return num;
}

void printInvertedLetterPattern(int num) {
	for (char i = num+64; i > 64; i--) {
		for (int j = 64; j < i; j++) {
			cout << i;
		}
		cout << endl;
	}
}

int main() {
	printInvertedLetterPattern(getPositiveNumber(""));

	return 0;
}
*/