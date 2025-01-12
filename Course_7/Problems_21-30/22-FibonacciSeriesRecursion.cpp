#include <iostream>

void PrintFibonacciSeries(int Num, int Prev1 = 1, int Prev2 = 0) {
	int temp;
	if (Num > 0) {
		printf("%d\t", Prev1);
		temp = Prev1;
		Prev1 = Prev1 + Prev2;
		Prev2 = temp;
		PrintFibonacciSeries(Num - 1, Prev1, Prev2);
	}
}

int main() {
	PrintFibonacciSeries(10);
	return 0;
}