#include <iostream>
#include <string>
#include "../InputLib.h"

char InvertLetterCase(char Char) { return isupper(Char) ? tolower(Char) : toupper(Char); }

std::string InvertAllLettersCase(std::string Str) {
    for (int i = 0; i < Str.length(); i++)
        Str[i] = InvertLetterCase(Str[i]);
    return Str;
}

int main() {
    std::string Str = input::ReadStrings("Please enter a string: \n");
    
    std::cout << "The string after inverting the case: \n" << InvertAllLettersCase(Str);
    return 0;
}