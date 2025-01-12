#include <iostream>
#include <string>
#include <cstdlib>
#include "../InputLib.h"

void LowerFirstLetterOfEachWord(std::string& Str) {
	bool IsFirstLetter = true;
	for (int i = 0; i < Str.length(); i++) {
		if (IsFirstLetter && Str[i] != ' ')
			Str[i] = tolower(Str[i]);
		IsFirstLetter = (Str[i] == ' ') ? true : false;
	}
}

int main() {
	std::string Str = input::ReadStrings("Please enter a string? ");
	LowerFirstLetterOfEachWord(Str);
	std::cout << "\n\nString after conversion: \n" << Str;
	return 0;
}