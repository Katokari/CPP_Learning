#include <iostream>
#include <string>
#include "../InputLib.h"

char InvertLetterCase(char Char) { return isupper(Char) ? tolower(Char) : toupper(Char); }

int CountLetters(std::string Str, char LetterToCount, bool MatchCase = true) {
    int Count = 0;
    for (int i = 0; i < Str.length(); i++) {
        if (MatchCase == true)
        {
            if (Str[i] == LetterToCount)
                Count++;
        }
        else
        {
            if (tolower(Str[i]) == tolower(LetterToCount))
                Count++;
        }
    }
    return Count;
}


int main() {
    std::string Str = input::ReadStrings("Please enter a string: \n");
    char Char = input::ReadChar("Please enter a character to count: \n");
    std::cout << "Letter " << Char << " Count = " << CountLetters(Str, Char) << std::endl;
    std::cout << "Letter " << Char << " Or " << InvertLetterCase(Char) << " Count = " << CountLetters(Str, Char, false) << std::endl;
    return 0;
}