#include <iostream>
#include "../InputLib.h"

void PrintMatrix(int arr[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols; j++)
			printf(" %0*d\t", 2, arr[i][j]);
		std::cout << std::endl;
	}
}

bool IsNumberInMatrix(int Matrix[3][3], short rows, short cols, int Number) {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (Matrix[i][j] == Number)
				return true;
	return false;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			arr[i][j] = random_::GenerateRandNum(1, 10);
}

void PrintIntersectedNumber(int Matrix1[3][3],int Matrix2[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			if (IsNumberInMatrix(Matrix2, 3, 3, Matrix1[i][j]))
				printf(" %d\t", Matrix1[i][j]);
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

	printf("Intersect numbers are: \n");
	PrintIntersectedNumber(Matrix1, Matrix2, 3, 3);

	return 0;
}