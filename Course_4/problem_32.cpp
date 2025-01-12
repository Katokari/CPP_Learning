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

void CopyArrReversed(int originalArr[], int destArr[], int arrLength) {
	for (int i = 0; i < arrLength; i++) {
		destArr[i] = originalArr[arrLength-i-1];
	}
}

int main() {
	srand((unsigned)time(NULL));
	int arr[100], arrLength, copyArr[100];
	FillArrRandNums(arr, arrLength);
	cout << "Original Array : ";
	PrintArray(arr, arrLength);
	CopyArrReversed(arr, copyArr, arrLength);
	cout << endl << endl;
	cout << "Copied Reversed Array : ";
	PrintArray(copyArr, arrLength);

	return 0;
}
*/