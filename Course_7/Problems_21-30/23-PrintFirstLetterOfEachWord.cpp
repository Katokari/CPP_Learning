#include <iostream>
#include <string>
#include <cstdlib>
#include "../InputLib.h"

void PrintFirstLetterOfEachWord(std::string Str) {
	bool IsFirstLetter = true;
	for (int i = 0; i < Str.length(); i++) {
		if (IsFirstLetter && Str[i] != ' ')
		{
			printf("%c\t", toupper(Str[i]));
		}
		IsFirstLetter = (Str[i] == ' ') ? true : false;
	}
}

int main() {
	PrintFirstLetterOfEachWord(input::ReadStrings("Please enter a string? "));
	return 0;
}