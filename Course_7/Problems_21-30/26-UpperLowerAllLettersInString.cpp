#include <iostream>
#include <string>
#include "../InputLib.h"

int main() {
	std::string Str = input::ReadStrings("Please enter a string? "), StrUpper, StrLower;
	StrUpper = trans::ToUpper(Str);
	std::cout << "\n\nString after upper all letters: \n" << StrUpper;
    StrLower = trans::ToLower(Str);
    std::cout << "\n\nString after lower all letters: \n" << StrLower;
	return 0;
}