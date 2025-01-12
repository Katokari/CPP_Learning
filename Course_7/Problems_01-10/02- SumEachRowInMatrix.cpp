#include <iostream>
#include <iomanip>
#include "../InputLib.h"

void FillMatrixWithRandomNumbers(int arr[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			arr[i][j] = random_::GenerateRandNum(1, 100);
}

void PrintMatrix(int arr[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols; j++)
			std::cout << std::setw(3) << arr[i][j] << "\t";
		std::cout << std::endl;
	}
}

int SumMatrixRow(int arr[], short cols) {
	int Sum = 0;
	for (short i = 0; i < cols; i++)
		Sum += arr[i];
	return Sum;
}

void CalculateAndPrintEachRowInMatrix(int arr[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++)
		std::cout << "Row " << i << " Sum = " << SumMatrixRow(arr[i], cols) << std::endl;
}

int main() {
	int arr[3][3];
	FillMatrixWithRandomNumbers(arr, 3, 3);

	std::cout << "The following is a 3x3 random matrix:" << std::endl;
	PrintMatrix(arr, 3, 3);

	std::cout << std::endl << std::endl;

	std::cout << "The following is the sum of each row of the matrix:" << std::endl;
	CalculateAndPrintEachRowInMatrix(arr, 3, 3);

	return 0;
}