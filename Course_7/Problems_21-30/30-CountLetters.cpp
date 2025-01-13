#include <iostream>
#include <string>
#include "../InputLib.h"

enum enWhatToCount { Small = 0, Capital };

int CountLetters(std::string Str, char LetterToCount) {
    int Count = 0;
    for (int i = 0; i < Str.length(); i++) {
        if (Str[i] == LetterToCount)
            Count++;
    }
    return Count;
}

int main() {
    std::string Str = input::ReadStrings("Please enter a string: \n");
    char Char = input::ReadChar("Please enter a character to count: \n");
    std::cout << "Letter " << Char << " Count = " << CountLetters(Str, Char);
    return 0;
}