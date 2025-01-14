#include <iostream>
#include <string>
#include "../InputLib.h"

bool IsVowel(char Char) {
    Char = tolower(Char);
    return (Char == 'a' || Char == 'o' || Char == 'i' || Char == 'u' || Char == 'e');

}

int main() {
    char Char = input::ReadChar("Please enter a character: \n");
    if (IsVowel(Char))
        std::cout << "Yes letter " << Char << " is vowel";
    else
        std::cout << "No letter " << Char << " is not vowel";
}