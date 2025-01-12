/*
#include <iostream>
#include <cstdlib>
using namespace std;

enum enCharacterType { SmallLetter = 1, CapitalLetter = 2, SpecalCharacter = 3, Digit = 4 };

int RandomNumber(int From, int To) {
	return (rand() % (To - From + 1) + From);
}

int getPositiveNumber(string message) {
	int num;
	do
	{
		cout << message;
		cin >> num;
		cout << endl;
	} while (num <= 0);

	return num;
}

void PrintArray(string arr[], int arrLength) {
	for (int i = 0; i < arrLength; i++) {
		cout << "Array [" << i << "] : " << arr[i] << endl;
	}
}


char getRandomCharacter(enCharacterType CharacterType) {
	switch (CharacterType) {
	case enCharacterType::SmallLetter:
	{
		return char(RandomNumber(97, 122));
		break;
	}
	case enCharacterType::CapitalLetter:
	{
		return char(RandomNumber(65, 90));
		break;
	}
	case enCharacterType::SpecalCharacter:
	{
		return char(RandomNumber(33, 47));
		break;
	}
	case enCharacterType::Digit:
	{
		return char(RandomNumber(48, 57));
		break;
	}
	}
}

string generateWord(enCharacterType CharacterType, int length) {
	string word = "";

	for (int i = 0; i < length; i++) {
		word += getRandomCharacter(CharacterType);
	}

	return word;
}

string generateKey() {
	string key = "";
	key += generateWord(enCharacterType::CapitalLetter, 4) + "-";
	key += generateWord(enCharacterType::CapitalLetter, 4) + "-";
	key += generateWord(enCharacterType::CapitalLetter, 4) + "-";
	key += generateWord(enCharacterType::CapitalLetter, 4);
	return key;
}

void FillArrayWithKeys(int num, string arr[]) {
	for (int i = 0; i <= num; i++) {
		arr[i] = generateKey();
	}
}

int main() {
	srand((unsigned)time(NULL));
	string arr[100];
	int arrLength = getPositiveNumber("");

	FillArrayWithKeys(arrLength, arr);
	PrintArray(arr, arrLength);
	

	return 0;
}
*/