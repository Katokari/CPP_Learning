#include <iostream>
#include <string>
#include "../InputLib.h"

bool IsVowel(char Char) {
    Char = tolower(Char);
    return (Char == 'a' || Char == 'o' || Char == 'i' || Char == 'u' || Char == 'e');

}

void PrintVowels(std::string Str) {
    std::cout << "\nVowels in string are: ";
    for (int i = 0; i < Str.length(); i++) {
        if (IsVowel(Str[i]))
            std::cout << Str[i] << "   ";
    }
}

int main() {
    std::string Str = input::ReadStrings("Please enter your string:\n");
    PrintVowels(Str);
}