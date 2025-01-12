/*
#include <iostream>
#include <string>
using namespace std;

int ReadPositiveNumber(string message) {
	int num;
	do
	{
		cout << message;
		cin >> num;
		cout << endl;
	} while (num <= 0);

	return num;
}

int GenerateRandNum(int From, int To) {
	return (rand() % (To - From + 1) + From);
}

void FillArrRandNums(int arr[], int& arrLength) {
	arrLength = ReadPositiveNumber("");

	for (int i = 0; i < arrLength; i++) {
		arr[i] = GenerateRandNum(1, 100);
	}
}

void PrintArray(int arr[], int arrLength) {
	for (int i = 0; i < arrLength; i++) {
		cout << arr[i] << " ";
	}
}

int SearchForElement(int arr[], int arrLength, int num) {
	for (int i = 0; i < arrLength; i++) {
		if (arr[i] == num)
			return i;
	}
	return -1;
}

int main() {
	srand((unsigned)time(NULL));
	int arr[100], arrLength;
	FillArrRandNums(arr, arrLength);
	cout << "Array Elements : ";
	PrintArray(arr, arrLength);

	int pos = SearchForElement(arr, arrLength, ReadPositiveNumber("Please enter a number to search for : "));

	if (pos >= 0)
		cout << "The number is found at position : " << pos;
	else
		cout << "The number is not found :(";
	return 0;
}
*/