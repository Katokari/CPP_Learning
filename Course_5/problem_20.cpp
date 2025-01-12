/*
#include <iostream>
#include <cstdlib>
using namespace std;

enum enCharacterType { SmallLetter = 1, CapitalLetter = 2, SpecalCharacter = 3, Digit = 4 };

int RandomNumber(int From, int To) {
	return (rand() % (To - From + 1) + From);
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

int main() {
	srand((unsigned)time(NULL));
	
	cout << getRandomCharacter(enCharacterType::SmallLetter) << endl;
	cout << getRandomCharacter(enCharacterType::CapitalLetter) << endl;
	cout << getRandomCharacter(enCharacterType::SpecalCharacter) << endl;
	cout << getRandomCharacter(enCharacterType::Digit) << endl;

	return 0;
}
*/