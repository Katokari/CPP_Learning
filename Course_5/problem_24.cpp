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

int MaxNumInArr(int arr[], int arrLength) {
	int max = arr[0];

	for (int i = 1; i < arrLength; i++) {
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

int main() {
	srand((unsigned)time(NULL));
	int arr[100], arrLength;
	FillArrRandNums(arr, arrLength);
	cout << "Array Elements : ";
	PrintArray(arr, arrLength);
	cout << endl << "Max Number : " << MaxNumInArr(arr, arrLength);

	return 0;
}
*/