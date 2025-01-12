/*
#include <iostream>
#include <iomanip>

void FillMatrixWithOrderedNumbers(int arr[3][3], int rows, int cols) {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			arr[i][j] = (i * rows) + j + 1;
}

void PrintMatrix(int arr[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++) {
		for (short j = 0; j < cols; j++)
			std::cout << std::setw(3) << arr[i][j] << "\t";
		std::cout << std::endl;
	}
}

int main() {
	int arr[3][3];

	FillMatrixWithOrderedNumbers(arr, 3, 3);

	std::cout << "The following is a 3x3 ordered matrix:" << std::endl;

	PrintMatrix(arr, 3, 3);
	return 0;
}
*/