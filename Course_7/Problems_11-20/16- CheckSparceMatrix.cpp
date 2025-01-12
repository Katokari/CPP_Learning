#include <iostream>

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

bool IsSparceMatrix(int Matrix[3][3], short rows, short cols) {	
	int MatrixSize = rows * cols;
	return (CountNumberInMatrix(Matrix, 3, 3, 0) >= (MatrixSize / 2));
}

int main() {
	int Matrix[3][3] = { {1, 0, 0}, {0, 1, 0}, {0, 0, 1} };

	printf("Matrix1:\n");

	PrintMatrix(Matrix, 3, 3);

	if (IsSparceMatrix(Matrix, 3, 3))
		printf("Yes matrix is an sparce matrix");
	else
		printf("No matrix is not an sparce matrix");

	return 0;
}
