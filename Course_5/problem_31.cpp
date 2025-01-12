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

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
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

void ShuffleArray(int arr[], int arrLength)
{
	int j;
	for (int i = arrLength - 1; i > 0; i--) {
		j = GenerateRandNum(0, i);
		swap(&arr[i], &arr[j]);
	}
}

int main() {
	srand((unsigned)time(NULL));
	int arr[100];
	int arrLength = ReadPositiveNumber("");

	FillArrRandNums(arr, arrLength);
	cout << "Original Array : ";
	PrintArray(arr, arrLength);

	cout << endl << endl;
	ShuffleArray(arr, arrLength);
	cout << "Shuffled Array : ";
	PrintArray(arr, arrLength);

	return 0;
}
*/