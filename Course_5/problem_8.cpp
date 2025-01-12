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

int digitFrequency(int digit, int num) {
	int frequency = 0, reminder = 0;
	while (num > 0) {
		reminder = num % 10;
		num /= 10;
		if (reminder == digit)
			frequency++;
	}
	return frequency;
}

int main() {
	cout << digitFrequency(getPositiveNumber(""), getPositiveNumber(""));
	return 0;
}
*/