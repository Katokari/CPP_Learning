#include <iostream>

void PrintMatrix(int arr[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols; j++)
			printf(" %0*d\t", 2, arr[i][j]);
		std::cout << std::endl;
	}
}

bool IsScalarMatrix(int Matrix[3][3], short rows, short cols) {
	int Diagonal = Matrix[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			if (i == j && Matrix[i][j] != Diagonal)
				return false;
			else if (i != j && Matrix[i][j] != 0)
				return false;
		}
	}
	return true;
}

int main() {
	int Matrix[3][3] = { {3, 0, 0}, {0, 3, 0}, {0, 0, 3} };

	printf("Matrix1:\n");

	PrintMatrix(Matrix, 3, 3);

	if (IsScalarMatrix(Matrix, 3, 3))
		printf("Yes matrix is an scalar matrix");
	else
		printf("No matrix is not an scalar matrix");

	return 0;
}