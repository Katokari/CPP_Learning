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

bool IsPalindromeMatrix(int Matrix1[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++)
		for (short j = 0; j < cols; j++)
			if (Matrix1[i][j] != Matrix1[i][cols - j - 1])
				return false;
	return true;
}

int main() {
	srand((unsigned)time(NULL));
	int Matrix1[3][3], Matrix2[3][3];

	FillMatrixWithRandomNumbers(Matrix1, 3, 3);

	printf("Matrix1:\n");
	PrintMatrix(Matrix1, 3, 3);

	printf("\n\n");

	if (IsPalindromeMatrix(Matrix1, 3, 3))
		printf("Yes matrix is an palindrome matrix");
	else
		printf("No matrix is not an palindrome matrix");
	return 0;
}