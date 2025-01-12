#include <iostream>
#include "../InputLib.h"

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

int SumMatrix(int Matrix[3][3], int rows, int cols) {
	int Sum = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			Sum += Matrix[i][j];
	return Sum;
}

bool AreTypicalMatrices(int Matrix1[3][3], int Matrix2[3][3], short rows, short cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (Matrix1[i][j] != Matrix2[i][j])
				return false;
		}
	}
	return true;
}

int main() {
	srand((unsigned)time(NULL));
	int Matrix1[3][3], Matrix2[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);

	printf("Matrix1:\n");
	PrintMatrix(Matrix1, 3, 3);

	printf("\n\n");

	FillMatrixWithRandomNumbers(Matrix2, 3, 3);

	printf("Matrix2:\n");
	PrintMatrix(Matrix2, 3, 3);

	printf("\n\n");

	if (!AreTypicalMatrices(Matrix1, Matrix2, 3, 3))
		printf("No the matrices are not typical");
	else
		printf("Yes the matrices are typical");

	printf("\n%d, %d", SumMatrix(Matrix1, 3, 3), SumMatrix(Matrix2, 3, 3));
	return 0;
}