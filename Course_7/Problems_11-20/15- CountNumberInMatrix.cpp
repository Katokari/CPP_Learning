#include <iostream>
#include "../InputLib.h"

void PrintMatrix(int arr[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols; j++)
			printf(" %0*d\t", 2, arr[i][j]);
		std::cout << std::endl;
	}
}

int CountNumberInMatrix(int Matrix[3][3], short rows, short cols, int Number) {
	int Counter = 0;
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			if (Matrix[i][j] == Number)
				Counter++;
	return Counter;
}

int main() {
	int Matrix[3][3] = { {3, 0, 0}, {0, 3, 0}, {0, 0, 3} };

	printf("Matrix1:\n");

	PrintMatrix(Matrix, 3, 3);

	printf("\n\n");

	int Number = input::ReadNumber("Enter the number to count in matrix: ", "Error please enter a valid number: ");

	printf("Number %d count in matrix is %d time(s)", Number, CountNumberInMatrix(Matrix, 3, 3, Number));

	return 0;
}