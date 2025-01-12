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

void FillArrRandNums(int arr[], int arrLength) {

	for (int i = 0; i < arrLength; i++) {
		arr[i] = GenerateRandNum(1, 100);
	}
}

void PrintArray(int arr[], int arrLength) {
	for (int i = 0; i < arrLength; i++) {
		cout << arr[i] << " ";
	}
}

void AddElementToArray(int arr[], int& arrLength, int num) {
	arr[arrLength] = num;
	arrLength++;
}

bool IsPalindromeArray(int arr[], int arrLength) {
	for (int i = 0; i < arrLength; i++) {
		if (arr[i] != arr[arrLength - i - 1])
			return false;
	}
	return true;
}

void FillArray(int arr[], int arrLength) {
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	arr[3] = 20;
	arr[4] = 10;
}

int main() {
	srand((unsigned)time(NULL));
	int arr1[100], arrLength1;
	arrLength1 = 5;

	FillArray(arr1, arrLength1);
	cout << "Array1 : ";
	PrintArray(arr1, arrLength1);

	if (IsPalindromeArray(arr1, arrLength1))
		cout << "Yes the array is palindrome";
	else
		cout << "No the array is not palindrom";


	return 0;
}
*/