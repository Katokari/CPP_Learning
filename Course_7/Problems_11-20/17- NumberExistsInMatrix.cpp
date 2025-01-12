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

int main() {
	int Matrix[3][3] = { {3, 0, 0}, {0, 3, 0}, {0, 0, 3} };

	printf("Matrix1:\n");

	PrintMatrix(Matrix, 3, 3);

	printf("\n\n");

	int Number = input::ReadNumber("Enter the number to look for in matrix: ", "Error please enter a valid number: ");

	if (IsNumberInMatrix(Matrix, 3, 3, Number))
		printf("Yes number exists in matrix");
	else
		printf("No number doesnt exists in matrix");

	return 0;
}