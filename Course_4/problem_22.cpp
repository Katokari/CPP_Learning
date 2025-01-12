/*
#include <iostream>
#include <string>
using namespace std;

int getPositiveNumber(string message) {
	int num;
	do
	{
		cout << message;
		cin >> num;
		cout << endl;
	} while (num <= 0);

	return num;
}

void addElementToArray(int arr[], int index) {
	arr[index] = getPositiveNumber("Element [" + to_string(index+1) + "] : ");
}

void addElementsToArray(int arr[], int& size) {
	size = getPositiveNumber("");
	for (int i = 0; i < size; i++) {
		addElementToArray(arr, i);
	}
}

int getNumFrequency(int arr[], int size, int num) {
	int frequency = 0;
	for (int i = 0; i < size; i++) {
		if (num == arr[i])
			frequency++;
	}
	return frequency;
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
	int numArr[100];
	int size;
	addElementsToArray(numArr, size);
	int num = getPositiveNumber("Enter the number you want to check : ");
	cout << "Original Array : ";
	printArray(numArr, size);
	cout << endl << num << " is repeated " << getNumFrequency(numArr, size, num) << " time(s)";


	return 0;
}
*/