/*
#include <iostream>
#include <math.h>
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
			printf(" %0*d\t", 2, arr[i][j]);
		std::cout << std::endl;
	}
}

void PrintMiddleRowInMatrix(int Matrix[3][3], short rows, short cols) {
	short MiddleRow = floor(rows / 2);
	for (int i = 0; i < cols; i++)
		printf(" %0*d\t", 2, Matrix[MiddleRow][i]);
}

void PrintMiddleColInMatrix(int Matrix[3][3], short rows, short cols) {
	short MiddleCol = floor(rows / 2);
	for (int i = 0; i < cols; i++)
		printf(" %0*d\t", 2, Matrix[i][MiddleCol]);
}

int main() {
	int Matrix1[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);

	printf("Matrix1:\n");
	PrintMatrix(Matrix1, 3, 3);

	printf("\n\n");

	printf("Middle row of matrix1 is:\n");
	PrintMiddleRowInMatrix(Matrix1, 3, 3);

	printf("\n\n");

	printf("Middle column of matrix1 is:\n");
	PrintMiddleColInMatrix(Matrix1, 3, 3);

	return 0;
}
*/