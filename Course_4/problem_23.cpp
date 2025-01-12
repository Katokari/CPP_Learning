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

void FillArrRandNums(int arr[], int& size) {
	size = ReadPositiveNumber("");

	for (int i = 0; i < size; i++) {
		arr[i] = GenerateRandNum(1, 100);
	}
}

void PrintArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	srand((unsigned)time(NULL));
	int arr[100], size;
	FillArrRandNums(arr, size);
	cout << "Array Elements : ";
	PrintArray(arr, size);

	return 0;
}
*/