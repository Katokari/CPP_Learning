/*
#include <iostream>
using namespace std;

void printTableHeader() {
	cout << "\n\t\t\tMultiplication Table From 1 To 10\n\n";
	for (int i = 1; i <= 10; i++) {
		cout << "\t" << i;
	}
	cout << "\n___________________________________________________________________________________";
}

void printFirstColumn(int i) {
	(i < 10) ? cout << i << "   |   " : cout << i << "  |   ";
}

void printRow(int i) {
	cout << endl;
	printFirstColumn(i);

	for (int j = 1; j <= 10; j++) {
		cout << j * i << "\t";
	}
}

void printTable() {
	printTableHeader();
	for (int i = 1; i <= 10; i++) {
		printRow(i);
	}
}

int main1() {
	printTable();
	return 0;
}
*/