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

bool IsPrime(int num) {
	for (int i = 2; i <= round(num / 2); i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
}

void CopyArrPrimeNumbers(int originalArr[], int destArr[], int arrLength1, int& arrLength2) {
	arrLength2 = 0;
	for (int i = 0; i < arrLength1; i++) {
		if (IsPrime(originalArr[i]))
			AddElementToArray(destArr, arrLength2, originalArr[i]);
	}
}

int main() {
	srand((unsigned)time(NULL));
	int arr1[100], arr2[100], arrLength1, arrLength2;
	arrLength1 = ReadPositiveNumber("");

	FillArrRandNums(arr1, arrLength1);
	cout << "Array1 : ";
	PrintArray(arr1, arrLength1);

	cout << endl << endl;

	CopyArrPrimeNumbers(arr1, arr2, arrLength1, arrLength2);
	cout << "Array2 after copy prime numbers : ";
	PrintArray(arr2, arrLength2);

	return 0;
}
*/