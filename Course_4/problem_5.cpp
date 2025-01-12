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

void printReverseDigits(int num) {
	while (num > 0) {
		cout << num % 10;
		num /= 10;
	}
}

int main() {
	printReverseDigits(getPositiveNumber(""));
	return 0;
}
*/