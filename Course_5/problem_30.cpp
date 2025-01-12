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

void CopyArr(int originalArr[], int destArr[], int arrLength) {
	for (int i = 0; i < arrLength; i++) {
		destArr[i] = originalArr[i];
	}
}

void SumTwoArr(int arr1[], int arr2[], int arr3[], int arrLength) {
	for (int i = 0; i < arrLength; i++) {
		arr3[i] = arr1[i] + arr2[i];
	}
}

int main() {
	srand((unsigned)time(NULL));
	int arr1[100], arr2[100], arr3[100];
	int arrLength = ReadPositiveNumber("");

	FillArrRandNums(arr1, arrLength);
	cout << "Array1 : ";
	PrintArray(arr1, arrLength);

	cout << endl << endl;
	FillArrRandNums(arr2, arrLength);
	cout << "Array2 : ";
	PrintArray(arr2, arrLength);

	cout << endl << endl;
	SumTwoArr(arr1, arr2, arr3, arrLength);
	cout << "the sum of two arrays : ";
	PrintArray(arr3, arrLength);

	return 0;
}
*/