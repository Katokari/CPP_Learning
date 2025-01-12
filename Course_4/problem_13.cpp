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

void printNumberPattern(int num) {
	for (int i = 1; i <= num; i++) {
		for (int j = 0; j < i; j++) {
			cout << i;
		}
		cout << endl;
	}
}

int main() {
	printNumberPattern(getPositiveNumber(""));

	return 0;
}
*/