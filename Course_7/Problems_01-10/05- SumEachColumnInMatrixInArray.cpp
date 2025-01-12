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

void CalculateEachColInMatrix(int arr[3][3], short Rows, short Cols, int ColsSum[]) {
	for (short i = 0; i < Cols; i++)
		ColsSum[i] = SumMatrixCol(arr, i, Rows);
}

void PrintEachColSum(int ColsSum[], int Length) {
	for (int i = 0; i < Length; i++)
		std::cout << "Col " << i << " Sum = " << ColsSum[i] << std::endl;
}

int main() {
	srand((unsigned)time(NULL));

	int arr[3][3], ColsSum[3];
	FillMatrixWithRandomNumbers(arr, 3, 3);

	std::cout << "The following is a 3x3 random matrix:" << std::endl;
	PrintMatrix(arr, 3, 3);

	std::cout << std::endl << std::endl;

	std::cout << "The following is the sum of each col of the matrix:" << std::endl;
	CalculateEachColInMatrix(arr, 3, 3, ColsSum);
	PrintEachColSum(ColsSum, 3);

	return 0;
}
*/