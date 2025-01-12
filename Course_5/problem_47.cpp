/*
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

float ReadFloat(string message) {
	float num;
	cout << message;
	cin >> num;
	cout << endl;
	return num;
}

int MyRound(float num) {
	int intPart = (int)num;
	float fractionalPart = num - intPart;

	if (abs(fractionalPart) >= .5)
	{
		if (num > 0)
			return intPart++;
		return intPart--;
	}
	return intPart;
}

int main() {
	float num = ReadFloat("");
	cout << MyRound(num);

	return 0;
}
*/