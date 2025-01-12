#include <iostream>
#include "../InputLib.h"

void PrintMatrix(int arr[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols; j++)
			printf(" %0*d\t", 2, arr[i][j]);
		std::cout << std::endl;
	}
}

void FillMatrixWithRandomNumbers(int arr[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			arr[i][j] = random_::GenerateRandNum(1, 10);
}

int MinNumberInMatrix(int Matrix[3][3], short rows, short cols) {
	int Min = Matrix[0][0];
	for (short i = 0; i < rows; i++)
		for (short j = 1; j < cols; j++)
			if (Matrix[i][j] < Min)
				Min = Matrix[i][j];
	return Min;
}

int MaxNumberInMatrix(int Matrix[3][3], short rows, short cols) {
	int Max = Matrix[0][0];
	for (short i = 0; i < rows; i++)
		for (short j = 1; j < cols; j++)
			if (Matrix[i][j] > Max)
				Max = Matrix[i][j];
	return Max;
}

int main() {
	srand((unsigned)time(NULL));
	int Matrix1[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);

	printf("Matrix1:\n");
	PrintMatrix(Matrix1, 3, 3);

	printf("\n\n");

	printf("Min number in the matrix is %d\n\n", MinNumberInMatrix(Matrix1, 3, 3));

	printf("Max number in the matrix is %d", MaxNumberInMatrix(Matrix1, 3, 3));

	return 0;
}