#include <iostream>
#include "../InputLib.h"

char InvertLetterCase(char Char) { return isupper(Char) ? tolower(Char) : toupper(Char); }

int main() {
    char Char = input::ReadChar("Please enter a character: ");
    
    std::cout << "The character after inverting the case: " << InvertLetterCase(Char);
    return 0;
}