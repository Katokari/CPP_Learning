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

bool IsPrime(int num) {
	for (int i = 2; i <= round(num / 2); i++) {
		if (num % i == 0) {
			return false;
		}
	}
	return true;
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

void CopyArrIfPrime(int originalArr[], int destArr[], int arrLength, int& arrLength2) {
	arrLength2 = 0;
	for (int i = 0; i < arrLength; i++) {
		if (IsPrime(originalArr[i]))
		{
			destArr[arrLength2] = originalArr[i];
			arrLength2++;
		}
	}
}

int main() {
	srand((unsigned)time(NULL));
	int arr[100], arrLength, copyArr[100], arrLength2 = 0;
	FillArrRandNums(arr, arrLength);
	cout << "Original Array : ";
	PrintArray(arr, arrLength);
	CopyArrIfPrime(arr, copyArr, arrLength, arrLength2);
	cout << endl << endl;
	cout << "Copied Array : ";
	PrintArray(copyArr, arrLength2);

	return 0;
}
*/