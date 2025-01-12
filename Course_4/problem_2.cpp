/*
#include <iostream>
using namespace std;

bool isPrime(int num) {
	for (int i = 2; i <= round(num / 2); i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

int getNumber() {
	int number;
	do {
		cin >> number;
	} while (number <= 0);
	return number;
}

void printPrimesFrom0toN(int n) {
	for (int i = 1; i <= n; i++) {
		if (isPrime(i)) {
			cout << i << endl;
		}
	}
}

int main() {
	printPrimesFrom0toN(getNumber());
	return 0;
}
*/