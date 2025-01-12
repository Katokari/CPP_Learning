/*
#include <iostream>
#include <string>
using namespace std;

int ReadNumber(string message) {
	int num;
	cout << message;
	cin >> num;
	cout << endl;
	return num;
}

void ReadArrayElements(int arr[], int& arrLength) {
	int question;
	arrLength = 0;
	do {
		arr[arrLength] = ReadNumber("Please enter a number : ");
		arrLength++;
		cout << "Do u want to add more numbers : [0] No, [1] Yes";
		cin >> question;
	} while (question);
}

void PrintArray(int arr[], int arrLength) {
	for (int i = 0; i < arrLength; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	int arr[100], arrLength;
	ReadArrayElements(arr, arrLength);
	PrintArray(arr, arrLength);
	return 0;
}
*/