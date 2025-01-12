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

void printLetterPattern(int num) {
	for (char i = 65; i < num + 65; i++) {
		for (int j = 64; j < i; j++) {
			cout << i;
		}
		cout << endl;
	}
}

int main() {
	printLetterPattern(getPositiveNumber(""));

	return 0;
}
*/