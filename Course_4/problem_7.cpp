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

int reverseNumber(int num) {
	int newNum = 0, reminder = 0;
	while (num > 0) {
		reminder = num % 10;
		num /= 10;
		newNum *= 10;
		newNum += reminder;
	}
	return newNum;
}

int main() {
	cout << reverseNumber(getPositiveNumber(""));
	return 0;
}
*/