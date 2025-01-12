#include <iostream>

void PrintFibonacciSeries(int Num) {
	int Prev1 = 0, Prev2 = 1, Current;

	for (int i = 0; i < Num; i++) {
		Current = Prev1 + Prev2;
		Prev2 = Prev1;
		Prev1 = Current;
		printf("%d\t", Current);
	}
}

int main() {
	PrintFibonacciSeries(10);
	return 0;
}