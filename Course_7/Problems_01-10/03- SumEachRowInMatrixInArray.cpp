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

int SumMatrixRow(int arr[3][3], int CurrentRow, short cols) {
	int Sum = 0;
	for (short i = 0; i < cols; i++)
		Sum += arr[CurrentRow][i];
	return Sum;
}

void SumMatrixRowsInArray(int arr[3][3], int rows, int cols, int RowSum[]) {
	for (int i = 0; i < rows; i++)
		RowSum[i] = SumMatrixRow(arr, i, cols);
}

void PrintRowsSum(int RowsSum[], int Length) {
	for (int i = 0; i < Length; i++)
		std::cout << "Row " << i << " Sum = " << RowsSum[i] << std::endl;
}

int main() {
	int arr[3][3], RowsSum[3];
	FillMatrixWithRandomNumbers(arr, 3, 3);

	std::cout << "The following is a 3x3 random matrix:" << std::endl;
	PrintMatrix(arr, 3, 3);

	std::cout << std::endl << std::endl;

	SumMatrixRowsInArray(arr, 3, 3, RowsSum);

	std::cout << "The following is the sum of each row of the matrix:" << std::endl;
	PrintRowsSum(RowsSum, 3);

	return 0;
}