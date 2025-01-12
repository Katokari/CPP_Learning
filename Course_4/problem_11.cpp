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

bool isPalindrome(int num) {
	if (num == reverseNumber(num))
		return true;
	return false;
}

void printPalindromeOrNot(bool isPalindrome) {
	if (isPalindrome)
		cout << "yes, the number is palindrome";
	else
		cout << "no, the number is not palindrome";
}

int main() {
	printPalindromeOrNot(isPalindrome(getPositiveNumber("")));

	return 0;
}
*/