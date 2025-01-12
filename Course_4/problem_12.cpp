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

void printInvertedNumberPattern(int num) {
	for (int i = num; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			cout << i;
		}
		cout << endl;
	}
}

int main() {
	printInvertedNumberPattern(getPositiveNumber(""));

	return 0;
}
*/