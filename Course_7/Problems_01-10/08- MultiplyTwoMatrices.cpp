/*
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "InputLib.h"

void FillMatrixWithRandomNumbers(int arr[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			arr[i][j] = random_::GenerateRandNum(1, 10);
}

void PrintMatrix(int arr[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols; j++)
			printf(" %0*d", 2, arr[i][j]);
		std::cout << std::endl;
	}
}

void MultiplyTwoMatrices(int Matrix1[3][3], int Matrix2[3][3], int Matrix3[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			Matrix3[i][j] = Matrix1[i][j] * Matrix2[i][j];
}

int main() {
	int Matrix1[3][3], Matrix2[3][3], Matrix3[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);

	std::cout << "Matrix1:" << std::endl;
	PrintMatrix(Matrix1, 3, 3);

	FillMatrixWithRandomNumbers(Matrix2, 3, 3);

	std::cout << "Matrix2:" << std::endl;
	PrintMatrix(Matrix2, 3, 3);

	std::cout << "Results:" << std::endl;
	MultiplyTwoMatrices(Matrix1, Matrix2, Matrix3, 3, 3);
	PrintMatrix(Matrix3, 3, 3);
	
	return 0;
}
*/