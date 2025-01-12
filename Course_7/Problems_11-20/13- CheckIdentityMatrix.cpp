#include <iostream>

void PrintMatrix(int arr[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols; j++)
			printf(" %0*d\t", 2, arr[i][j]);
		std::cout << std::endl;
	}
}

bool IsIdentityMatrix(int Matrix[3][3], short rows, short cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			if (i == j && Matrix[i][j] != 1)
				return false;
			else if (i != j && Matrix[i][j] != 0)
				return false;
		}
	}
	return true;
}

int main() {
	int Matrix[3][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };

	printf("Matrix1:\n");

	PrintMatrix(Matrix, 3, 3);

	if (IsIdentityMatrix(Matrix, 3, 3))
		printf("Yes matrix is an identity matrix");
	else
		printf("No matrix is not an identity matrix");

	return 0;
}