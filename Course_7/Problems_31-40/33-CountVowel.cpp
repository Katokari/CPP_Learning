#include <iostream>
#include <string>
#include "../InputLib.h"

bool IsVowel(char Char) {
    Char = tolower(Char);
    return (Char == 'a' || Char == 'o' || Char == 'i' || Char == 'u' || Char == 'e');

}

int CountVowels(std::string Str) {
    int Count = 0;
    for (int i = 0; i < Str.length(); i++) {
        if (IsVowel(Str[i]))
            Count++;
    }
    return Count;
}

int main() {
    std::string Str = input::ReadStrings("Please enter your string:\n");

    std::cout << "Number of vowels is " << CountVowels(Str);
}