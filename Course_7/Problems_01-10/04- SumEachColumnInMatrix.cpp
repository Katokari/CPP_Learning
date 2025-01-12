/*
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "InputLib.h"

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

int SumMatrixCol(int arr[3][3], int CurrentCol, short Rows) {
	int Sum = 0;
	for (short i = 0; i < Rows; i++)
		Sum += arr[i][CurrentCol];
	return Sum;
}

void CalculateAndPrintEachColInMatrix(int arr[3][3], short Rows, short Cols) {
	for (short i = 0; i < Cols; i++)
		std::cout << "Col " << i << " Sum = " << SumMatrixCol(arr, i, Rows) << std::endl;
}

int main() {
	srand((unsigned)time(NULL));

	int arr[3][3];
	FillMatrixWithRandomNumbers(arr, 3, 3);

	std::cout << "The following is a 3x3 random matrix:" << std::endl;
	PrintMatrix(arr, 3, 3);

	std::cout << std::endl << std::endl;

	std::cout << "The following is the sum of each col of the matrix:" << std::endl;
	CalculateAndPrintEachColInMatrix(arr, 3, 3);

	return 0;
}
*/