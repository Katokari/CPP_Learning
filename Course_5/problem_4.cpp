/*
#include <iostream>
using namespace std;

bool isPerfect(int num) {
	int sum = 0;
	for (int i = 1; i <= round(num / 2); i++) {
		if (num % i == 0) sum += i;
	}

	return num == sum;
}

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

void PrintPerfectNumbers1toN(int num) {
	for (int i = 1; i <= num; i++) {
		if (isPerfect(i)) {
			cout << i << endl;
		}
	}
}

int main() {
	PrintPerfectNumbers1toN(getPositiveNumber("enter a positive number: "));
	return 0;
}
*/