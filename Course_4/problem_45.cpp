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
		arr[i] = GenerateRandNum(-100, 100);
	}
}

void PrintArray(int arr[], int arrLength) {
	for (int i = 0; i < arrLength; i++) {
		cout << arr[i] << " ";
	}
}

int CountNegative(int arr[], int arrLength) {
	int count = 0;
	for (int i = 0; i < arrLength; i++)
		if (arr[i] < 0)
			count++;
	return count;
}

int main() {
	srand((unsigned)time(NULL));
	int arr1[100], arrLength1;
	arrLength1 = ReadPositiveNumber("");

	FillArrRandNums(arr1, arrLength1);
	cout << "Array1 : ";
	PrintArray(arr1, arrLength1);

	cout << endl << endl;

	cout << "Negative numbers count is : " << CountNegative(arr1, arrLength1);


	return 0;
}
*/